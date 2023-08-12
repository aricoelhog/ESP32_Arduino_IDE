/* Variáveis que determinarão em que momento as mensagens serão publicadas*/
long TempoExecucao = 0;
int TempoParaPublicar = 10000; //em ms

/////////////////////////////////////////////

// Bibliotecas a serem utilizadas para conectar o ESP32 à AWS
#include "secrets.h"                        // Arquivo com informações de conexão WiFi, chaves de segurança, políticas e certificados que permitem conexão segura
#include <WiFiClientSecure.h>               // Classe que implementa suporte para conexões seguras usando TLS (SSL), necessárias para conexão com AWS
#include <PubSubClient.h>                   // Biblioteca para utilização do protocolo MQTT
#include <ArduinoJson.h>                    // Biblioteca para utilização de JSON
#include "WiFi.h"                           // Biblioteca WiFi para conexão com a internet

#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub" // Define o comando para publicar mensagens MQTT
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub" // Define o comando para inscrever ("receber") uma mensagens MQTT

WiFiClientSecure net = WiFiClientSecure();  // Criou o objeto 'net' do tipo WiFiClientSecure;
PubSubClient client(net);                   // Definiu-se o objeto de conexão da AWS como o cliente.*/

/////////////////////////////////////////////

// Função que conecta o ESP32 à AWS IOT
void connectAWS()
{
  delay(1000);                              // Atraso de 1 seg
  WiFi.mode(WIFI_STA);                      // Habilita o modo estação para permitir conexão WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);     // Inicia e tenta conectar ao WiFi, onde as variáveis (SSID e Senha) foram definidas no arquivo secrets.h
 
  Serial.println("Conectando ao Wi-Fi");    // Mostra a mensagem no Monitor Serial

 // Enquanto o status do WiFi for diferente de 'conectado', será exibido um ponto no monitor serial à cada 500 mili-Segundos
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);                             // Atraso de 500ms
    Serial.print(".");                      // Mostra a mensagem no Monitor Serial
  }

  // Configura o objeto 'net' para utilizar as credenciais da coisa AWS IoT
  net.setCACert(AWS_CERT_CA);               // Certificado CA coletado da coisa ESP32 na AWS IoT
  net.setCertificate(AWS_CERT_CRT);         // Certificado digital da coisa ESP32 na AWS IoT
  net.setPrivateKey(AWS_CERT_PRIVATE);      // Chave privada da coisa ESP32 na AWS IoT
  
  client.setServer(AWS_IOT_ENDPOINT, 8883); // Conecta ao broker do MQTT da AWS por meio do endpoint
    
  client.setCallback(messageHandler);       // Cria um manipulador de mensagens

  Serial.println("Conectando à AWS IOT");   // Mostra a mensagem no Monitor Serial

 // Enquanto não conectar à coisa ESP32 na AWS, será exibido um ponto no monitor serial à cada 100 mili-Segundos
  while (!client.connect(THINGNAME))
  {
    Serial.print(".");                      // Mostra a mensagem no Monitor Serial
    delay(100);                             // Atraso de 100ms
  }

 // Se não for possível conectar, será exibido a mensagem abaixo no monitor serial
  if (!client.connected())
  {
    Serial.println("Não foi possível conectar à AWS IoT!");    // Mostra a mensagem no Monitor Serial
    return;
  }
 
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);                  // Inscrever em um tópico
 
  Serial.println("Conexão à AWS IoT efetuada com sucesso!");  // Mostra a mensagem no Monitor Serial
}


/////////////////////////////////////////////
// Reconecta ao broker
void reconnect() {
  // Loop até reconectar novamente
  while (!client.connected()) {
    Serial.print("Tentando reestabelecer a conexão...");
    
    // Tentativa de reconexão
    if (client.connect(THINGNAME)) {
      Serial.println("Conectado!");
      Serial.println("          ");
      
      publishMessage();                                     // Quando conectado, publica no cliente
      
      client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);            // E inscreve
    } else {
      Serial.print("Falha ao reconectar, rc=");             // Mostra a mensagem no Monitor Serial
      Serial.print(client.state());                         // Mostra a mensagem no Monitor Serial
      Serial.println(" Tentando novamente em 3 segundos");  // Mostra a mensagem no Monitor Serial
      delay(3000);                                          // Atraso de 3s para tentar reconectar
    }
  }
}

/////////////////////////////////////////////


// Envia os dados para AWS IOT, publica a mensagem no formato JSON
void publishMessage()
{
  StaticJsonDocument<200> doc;              // Define um documento JSON do tipo estático
  
  // Escreve no doc
  doc["Hello World"] = 33;
  char jsonBuffer[512];                     // Define vetor de caracteres que será convertida em JSON
  serializeJson(doc, jsonBuffer);           // Converte o documento em string utilizando o buffer
  
  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);      // Publica(Escreve, mostra) o documento no cliente (AWS IoT) utilizando o buffer
}



/////////////////////////////////////////////


// Recebe os dados da AWS IOT
void messageHandler(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Chegando mensagem: ");      // Mostra a mensagem no Monitor Serial
  Serial.println(topic);                    // Mostra o tópico no Monitor Serial
 
  StaticJsonDocument<200> doc;              // Define um documento JSON do tipo estático
  deserializeJson(doc, payload);            // Converte a string no documento JSON
  const char* message = doc["message"];     // Define a variável constante que armazena a mensagem recebida
  Serial.println(message);                  // Mostra a mensagem no Monitor Serial
}


/////////////////////////////////////////////

// Função da AWS que deve rodar no setup principal
void setup() {
  Serial.begin(115200);                     // Inicia o Monitor Serial para visualização dos dados via USB no computador
  connectAWS();                             // Conecta ESP32 à AWS IOT
}

/////////////////////////////////////////////

// Função da AWS que deve rodar no loop principal
void loop() {
   
  if(millis() - TempoExecucao > TempoParaPublicar){       // Executa de acordo com o intervalo de publicação
    publishMessage();                                     // Envia os dados para AWS IOT, publica a mensagem no formato JSON
    client.loop();                                        // Permite que o cliente processe mensagens recebidas para enviar dados de publicação e faz uma atualização da conexão
    Serial.println("Dados publicados com sucesso!");      // Mostra a mensagem no Monitor Serial
    Serial.println("--------");                           // Mostra a mensagem no Monitor Serial
    
    TempoExecucao = millis();                             // Recebe o tempo que o programa está executando
    
    if (!client.connected()) {
      reconnect();                                        // Caso perca a conexão, há uma tentativa de reconectar
    }   
  }
  delay(100);                                             // Atraso de 100ms
}
