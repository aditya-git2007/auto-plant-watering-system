# Auto Plant Watering System — Wiring & Power Guidelines

## ⚡ Power & Relay Isolation
* **External Pump Power:** Never power the DC water pump directly from the Arduino's 5V pin. Use an external 5V power supply connected to the relay's common terminal, sharing a common ground with the Arduino.
* **Shared I2C Bus:** The DS3231 RTC and I2C LCD share pins `A4 (SDA)` and `A5 (SCL)`.
