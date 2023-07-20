// Declaração das variáveis

const int voltageSensorPin = 39;          // Definição do pino GPIO39 que está conectado ao sensor de tensão
float vIn;                                // Voltagem que será medida, onde para alimentação de 3.3V, mede-se no max. 16.5V, e para 5V, max 25V
float vOut;                               // Voltagem que será medida no pino que está conectado o sensor
float voltageSensorVal;                   // Valor analógico que será lido no pino (0 - 4095)
float vCC = 3.3;                          // Voltagem no pino do ESP

/* Cálculo do fator de redução do sensor:
 * Vin / vOut = factor                    -> Voltagem da placa / Voltagem no pino do esp = fator
 * 8.83 / 1.07 = 8.25                     -> Onde Vin foi medido utilizando um multímetro e VOut é a tensão que sai no pino analógico
 * 9.27 / 1.12 = 8.27
 * 9.71 / 1.22 = 7.95
 * (8.25 + 8.27 + 7.95) / 3 = 8.156       -> Média do Fator
 */
float factor = 8.156;                      // Fator de redução do sensor


void setup(){
  Serial.begin(115200);                                     // Inicia o Monitor Serial para visualização dos dados via USB no computador
}

/////////////////////////////////////////////

// Função da tensão que deve rodar no loop principal
void loop() {
  
  float somaDasTensoes = 0;                           // Variavel que armazenara a soma das tensoes lidas
  for(int i = 0; i < 1000; i++){
    somaDasTensoes += analogRead(voltageSensorPin);   // Le o valor analogico no sensor 1000 vezes para melhorar a precisao
    delay(1);                                         // Atraso 1ms
  }
  voltageSensorADC = somaDasTensoes/1000;             // Calcula a media dos valores de tensao lidos
  vOut = (voltageSensorADC / 4095) * vCC;             // Calcula a voltagem correspondente ao valor analogico lido, de acordo com a tensao dos pinos do ESP (3.3V) e a resolucao(1023)
  
  vIn =  22.434*vOut + 2.9185;                        // Converte a voltagem do pino a tensao gerada correspondente

  if(vIn < 2.93){                                     // Com a equacao, 2.93V e o menor valor que o sensor consegue ler, ja que apos isso a tensao no pino e zero
    vIn = 0;
  }

  Serial.print("Voltagem: ");                         // Mostra a mensagem no Monitor Serial
  Serial.print(vIn);                                  // Mostra o resultado no Monitor Serial
  Serial.println(" V");                               // Mostra a mensagem no Monitor Serial
  
  Serial.println("--------");                         // Mostra a mensagem no Monitor Serial
  
  delay(2000);                                        // Atraso de 2s
}
