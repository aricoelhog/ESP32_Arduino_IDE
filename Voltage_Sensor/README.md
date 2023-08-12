# ESP32 and Voltage Sensor (25V)

Using ESP32 and Voltage Sensor (25V) to read the voltage of a 30W solar panel. To develop the voltage reading, a direct current Led 12V (1A) was connected directly to the solar panel. The solar panel specifications are illustrated below:

![PlacaSolarEspecific](https://github.com/aricoelhog/ESP32_Voltage_Sensor/assets/139346671/c2d94440-c5d4-466c-9814-e4b903eda3a5)

In addition, the sensor was connected in parallel to the lamp. The GND(-) pin of the sensor was connected to the GND pin of the ESP32, VCC(+) to Vin, as it needs a voltage of 5V for correct reading, and the output pin S to the pin GPIO 39 using a voltage divider. ESP32 analog pin supports maximum voltage of 3.3V, so to avoid damage to the microcontroller, connections were made as illustrated below:

![image](https://github.com/aricoelhog/ESP32_Voltage_Sensor/assets/139346671/69bea32b-c228-44d6-96aa-2915c62dd56e)
![Esp32_pin](https://github.com/aricoelhog/ESP32_Voltage_Sensor/assets/139346671/7c8e8af9-2987-4c2b-bd32-ccc3959d4f37)

For this sensor, it was necessary to calculate an equation that relates the input voltage with the voltage on the ESP pin, and this was done by measuring them using a multimeter, with the connected sensor. In this way, the graph was generated with the equation that calculates the measured values.
![EqVoltageSensor](https://github.com/aricoelhog/ESP32_Voltage_Sensor/assets/139346671/1dfb734d-5789-46f6-ab8c-bc762493f70a)

With this equation, the present project was developed, and the readings were successfully performed.

FONT: [GONÇALVES, A. **Sistema de Monitoramento de Energia Solar Fotovoltaica com Armazenamento de Dados em Nuvem**. Projeto de Conclusão de Curso — Universidade do Estado de Minas Gerais, 2023.](https://drive.google.com/file/d/1ge0Wb9ZYfXhWafDIYcRNHqw6Q1MuCGXX/view)
