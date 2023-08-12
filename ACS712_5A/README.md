# ESP32 and ACS712 5A
Using ESP32 and ACS712 5A to read the DC current of a 30W solar panel. To develop the current reading, a direct current Led 12V (1A) was connected directly to the solar panel. The solar panel specifications are illustrated below:

![PlacaSolarEspecific](https://github.com/aricoelhog/ESP32_Arduino_IDE/assets/139346671/899a5529-6860-4a58-9a19-8eea0b9bc506)

In addition, the sensor was connected in series to the lamp's positive part. The GND(-) pin of the sensor was connected to the GND pin of the ESP32, VCC(+) to 3v3, and the output pin S to the pin GPIO 34, connections were made as illustrated below:

![Current_Test](https://github.com/aricoelhog/ESP32_Arduino_IDE/assets/139346671/0a8daa8b-2dec-49b9-8315-8323801d0723)

![Esp32_pin](https://github.com/aricoelhog/ESP32_Arduino_IDE/assets/139346671/05884b1e-96b6-4829-9923-4148bef1abdf)

For this sensor, it was necessary to calculate an equation that relates the input current with the analog read on the ESP pin, and this was done by measuring them using a multimeter, with the connected sensor. In this way, the graph was generated with the equation that calculates the measured values.

![EqACS712](https://github.com/aricoelhog/ESP32_Arduino_IDE/assets/139346671/8d383c27-38a7-4aed-8ed8-532aa2106288)

With this equation, the present project was developed, and the readings were successfully performed.

## FONT: 
[GONÇALVES, A. **Sistema de Monitoramento de Energia Solar Fotovoltaica com Armazenamento de Dados em Nuvem**. Projeto de Conclusão de Curso — Universidade do Estado de Minas Gerais, 2023.](https://drive.google.com/file/d/1ge0Wb9ZYfXhWafDIYcRNHqw6Q1MuCGXX/view)
