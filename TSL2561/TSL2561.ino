#include <Wire.h>                                 // Biblioteca que permite comunicacao com dispositivos I2C
#include <Adafruit_TSL2561_U.h>                   // Biblioteca do sensor TSL2561
#include <Adafruit_Sensor.h>                      // Biblioteca de sensores da Adafruit

// Declaracao das variaveis que armazenarao os valores de luminosidade e irradiancia
float luminosidade = 0;
float irradiancia = 0;

/* Definicao do objeto tsl do tipo 'Adafruit_TSL2561_Unified', float(numero real), 
 * e o numero correspondente ao dispositivo I2C, que no caso e o sensor TSL2561 */
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT,12345);


/////////////////////////////////////////////

// Funcao que configura o sensor TSL
void TSL2561_configureSensor()
{
    tsl.enableAutoRange(true);                              // Habilita as configuracoes de ganho automatico ao ler dados do sensor
    tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  // Define o tempo de 101ms para leitura da luz 
}

/////////////////////////////////////////////

// Funcao do TSL2561 que deve rodar no setup principal
void setup(){
  Serial.begin(115200);                                     // Inicia o Monitor Serial para visualizacao dos dados via USB no computador
  TSL2561_configureSensor();                                // Funcao que configura o sensor TSL
}

/////////////////////////////////////////////

// Funcao do TSL2561 que deve rodar no loop principal
void loop(){
  sensors_event_t event;                                    // Ponteiro do tipo sensor_event_t que sera preenchido com o valor lux, datatmp, tipo de dados e ID do sensor
  tsl.getEvent(&event);                                     // Recebe o evento mais recente do sensor
  
  // Se o evento detectar luz:
  if (event.light)
  {
    luminosidade = event.light;                             // A variavel armazena o valor da luz em lux
    Serial.print("Luminosidade: ");                         // Mostra a mensagem no Monitor Serial
    Serial.print(luminosidade,0);                           // Mostra o resultado no Monitor Serial
    Serial.println(" lux");                                 // Mostra a mensagem no Monitor Serial
    
    Serial.println("--------");                             // Mostra a mensagem no Monitor Serial

    /* Irradiancia solar de 1 Sol (1 W/m2), equivale a aproximadamente 120 lux:
     * 1 W/m2 = 120 lux
     */
    irradiancia = luminosidade / 120;                       // Calculo da irradiancia armazenado na variavel
    Serial.print("Irradiancia: ");                          // Mostra a mensagem no Monitor Serial
    Serial.print(irradiancia);                              // Mostra o resultado no Monitor Serial
    Serial.println(" W/m2");                                // Mostra a mensagem no Monitor Serial
    Serial.println("--------");                             // Mostra a mensagem no Monitor Serial
  }
  else      // Se o evento nao detecta luz
  {
    Serial.println("Sensor sobrecarregado!");               // Mostra a mensagem no Monitor Serial
  }
  delay(2000);                                              // Atraso de 2s
}
