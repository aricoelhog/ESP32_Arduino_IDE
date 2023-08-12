#include <ESP_LM35.h>                       // Biblioteca do sensor LM35 para ESP

// Declaração das variáveis
ESP_LM35 temp(36);                          // Definição do objeto temp, do tipo ESP_LM35 onde o valor entre parênteses é o pino GPIO36 que está conectado ao sensor LM35
float tLM35;                                // Variável que armazenará o valor de temperatuta lido pelo sensor

/////////////////////////////////////////////

void setup(){
  Serial.begin(115200);                     // Inicia o Monitor Serial para visualização dos dados via USB no computador
}

// Função do LM35 que deve rodar no loop principal
void loop() {
  tLM35 = temp.tempC();                     // Leitura da temperatura em Celsius(°C) e armazena na variável
  Serial.print("Temperatura da placa: ");   // Mostra a mensagem no Monitor Serial
  Serial.print(tLM35);                      // Mostra o valor da temperatura no Monitor Serial
  Serial.println(" ºC");                    // Mostra a mensagem no Monitor Serial

  delay(1000);                              // Atraso de 1s
}
