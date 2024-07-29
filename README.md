# Fan-Controller-system-based-on-Atmega32

Designed a temperature-controlled fan system using an ATmega32 microcontroller operating at 1MHz. The system uses an LM35 sensor to continuously monitor temperature, converting analog signals to digital via ADC. Based on temperature readings, the microcontroller adjusts fan speed using PWM signals: off below 30°C, 25% at 30°C, 50% at 60°C, 75% at 90°C, and 100% at 120°C. The system displays temperature and fan status on an LCD, controlling the fan with a DC motor and maintaining functionality via external interrupts and layered architecture drivers.
