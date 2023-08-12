# ESP32 and ACS712 5A
Using ESP32 and ACS712 5A to read the DC current of a 30W solar panel. To develop the current reading, a direct current Led 12V (1A) was connected directly to the solar panel. The solar panel specifications are illustrated below:

![image](https://github.com/aricoelhog/ESP32_ACS712_5A/assets/139346671/e66f8b80-cddf-44ec-99f7-2ef0ce572ffb)

In addition, the sensor was connected in series to the lamp's positive part. The GND(-) pin of the sensor was connected to the GND pin of the ESP32, VCC(+) to 3v3, and the output pin S to the pin GPIO 34, connections were made as illustrated below:

![Current_Test](https://github.com/aricoelhog/ESP32_ACS712_5A/assets/139346671/8d1a6e26-5b5d-4678-ad1a-488ce3753ad1)

![Esp32_pin](https://github.com/aricoelhog/ESP32_ACS712_5A/assets/139346671/b8178d06-5c34-40dc-a4e9-e6fc8e3f68f2)

For this sensor, it was necessary to calculate an equation that relates the input current with the analog read on the ESP pin, and this was done by measuring them using a multimeter, with the connected sensor. In this way, the graph was generated with the equation that calculates the measured values.

![EqACS712](https://github.com/aricoelhog/ESP32_ACS712_5A/assets/139346671/7522037e-f2ed-4050-b0ea-fe0e70b9e69f)

With this equation, the present project was developed, and the readings were successfully performed.

## FONT: 
[GONÇALVES, A. **Sistema de Monitoramento de Energia Solar Fotovoltaica com Armazenamento de Dados em Nuvem**. Projeto de Conclusão de Curso — Universidade do Estado de Minas Gerais, 2023.](https://drive.google.com/file/d/1ge0Wb9ZYfXhWafDIYcRNHqw6Q1MuCGXX/view)
