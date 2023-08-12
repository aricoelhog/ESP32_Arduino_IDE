int buzzer = 32;//Atribui o valor 32 a variável buzzer, que representa o pino digital 32, onde o buzzer está conectado
int i = 0;//Variável para contar o número de vezes que o buzzer tocou

void setup() {
  pinMode(buzzer, OUTPUT);//Definindo o pino buzzer como de saída.
}

void loop() {
  for (i; i < 5; i++) {//Para i, enquanto i for menor que 11, realize o código e incremente 1 em i
    tone(buzzer, 2500);//Ligando o buzzer com uma frequência de 1500 Hz.
    delay(2000);//Intervalo de 1000 milissegundos
    noTone(buzzer);//Desligando o buzzer.
    delay(200);//Intervalo de 500 milissegundos
  }
}
