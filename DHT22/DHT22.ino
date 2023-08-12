#include <DHT.h>                            // Biblioteca dos sensores DHT
                      
DHT dht22(5, DHT22);                        // Definição do objeto dht22 do tipo DHT22, conectado ao pino GPIO5
float temperatura, umidade;                 // Variáveis que armazenarão os valores de temperatura ambiente e umidade

/////////////////////////////////////////////

// Função do DHT22 que deve rodar no setup principal
void setup() {
  Serial.begin(115200);                     // Inicia o Monitor Serial para visualização dos dados via USB no computador
  dht22.begin();                            // Inicia o sensor
}

/////////////////////////////////////////////

// Função do DHT22 que deve rodar no loop principal
void loop(){
  
  umidade = dht22.readHumidity();           // Lê a umidade do ambiente
  temperatura = dht22.readTemperature();    // Lê a temperatura ambiente

  // Se não houver valor lido para temperatura ou para umidade:
  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Não foi possível medir os parâmetros!");        // Mostra a mensagem no Monitor Serial
  }
  else { // Senão:
    Serial.print("Temperatura: ");          // Mostra a mensagem no Monitor Serial
    Serial.print(temperatura);              // Mostra o resultado no Monitor Serial
    Serial.println(" °C");                  // Mostra a mensagem no Monitor Serial
    Serial.println("--------");             // Mostra a mensagem no Monitor Serial
    Serial.print("Umidade: ");              // Mostra a mensagem no Monitor Serial
    Serial.print(umidade);                  // Mostra o resultado no Monitor Serial
    Serial.println(" %");                   // Mostra a mensagem no Monitor Serial
    Serial.println("--------");             // Mostra a mensagem no Monitor Serial
    delay(2000);                            // Atraso de 2s
  }
}
