# Using the ESP32 to read the lightness in lux with TSL2561

On this project, the ESP32 and TSL2561 were used to read the environment's lightness in lux. The TSL2561 transmits data via I2C 
communication, so, the VCC pin of the module was connected to the 3v3 pin of the ESP32 (red jumper), GND (black jumper) to GND, 
SCL (yellow jumper) to GPIO22 and SDA (blue jumper) to GPIO21, according to the pinout and connection illustrated below.

![tsl2561_pin](https://github.com/aricoelhog/ESP32_Arduino_IDE/assets/139346671/ea1e5793-be7f-4b6d-9abc-7d9c91cd4b5a)

![tsl2561_Test](https://github.com/aricoelhog/ESP32_Arduino_IDE/assets/139346671/04a98b1c-6c68-43d6-b119-a9d3b8907487)

![Esp32_pin](https://github.com/aricoelhog/ESP32_Arduino_IDE/assets/139346671/05884b1e-96b6-4829-9923-4148bef1abdf)

To measure the luminosity, it was necessary use three libraries: Wire, Arduino's native that allows communication via I2C, 
[Adafruit TSL2561](https://github.com/adafruit/Adafruit_TSL2561) and [Adafruit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor)
were installed. Furthermore, this projects converts the luminosity (lux) in irradiance (W/m²) through the equation proposed by 
Michael, Johnston and Moreno (2020):

### _irradiance = lightness/120_

## Fonts:

[GONÇALVES, A. **Sistema de Monitoramento de Energia Solar Fotovoltaica com Armazenamento de Dados em Nuvem**. Projeto de Conclusão de Curso — Universidade do Estado de Minas Gerais, 2023.](https://drive.google.com/file/d/1ge0Wb9ZYfXhWafDIYcRNHqw6Q1MuCGXX/view)

MICHAEL, P. R.; JOHNSTON, D. E.; MORENO, W. A conversion guide: solar irradiance and lux illuminance. Journal of Measurements in Engineering, JVE International Ltd., v. 8, n. 4, p. 153–166, 2020.
