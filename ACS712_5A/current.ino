double dc_current = 0, mediaADC = 0;                  // Variavel que armazenara o valor de corrente e analogico lido pelo sensor

// Funcao do ACS712 que deve rodar no setup principal
void setup() {
  Serial.begin(115200);                               // Inicia o Monitor Serial para visualizacao dos dados via USB no computador
}
 
void loop() {
  
  float somaDasCorrentes = 0;                         // Variavel que armazenara a soma das correntes lidas  
  for(int i=0; i<1000;i++){
    somaDasCorrentes += analogRead(34);               // Le a corrente 1000 vezes para melhorar a precisao
    delay(1);                                         // Atraso 1ms
  }
  
  mediaADC = (somaDasCorrentes/1000);                 // Media dos mil valores lidos

  dc_current = 0.008*mediaADC - 15.298;               // Calculo da corrente correspondida

  if (dc_current < 0)                                 // Como e corrrente continua, nao existe corrente negativa
    dc_current = 0;                                   // Logo quando o sensor ler valores negativos, significa que a corrente e zero
  
  Serial.print("Corrente: ");                         // Mostra a mensagem no Monitor Serial
  Serial.print(dc_current);                           // Mostra o valor no Monitor Serial
  Serial.println(" A");                               // Mostra a mensagem no Monitor Serial
  
  delay(1000);                                        // Atraso de 1s
}
