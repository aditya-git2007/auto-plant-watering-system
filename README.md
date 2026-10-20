# auto-plant-watering-system
Dual-mode automated plant irrigation system using Arduino Uno, RTC scheduled watering, and capacitive soil moisture threshold triggering.
# 🌱 Auto Plant Watering System (Scheduled & Threshold-Based)

> An intelligent, dual-mode automated plant irrigation system combining real-time clock (RTC) scheduling with capacitive soil moisture feedback to ensure optimal hydration without water wastage.

[![Status](https://img.shields.io/badge/Status-Completed-emerald?style=for-the-badge)]()
[![MCU](https://img.shields.io/badge/MCU-Arduino_Uno-blue?style=for-the-badge)]()

---

## 🎯 Overview & Mission Objective
Plants have precise watering needs that change with weather and time. This system operates in two distinct modes:
1. **RTC Scheduled Watering:** Triggers timed irrigation intervals at user-defined hours via a DS3231 Real-Time Clock.
2. **Capacitive Threshold Auto-Trigger:** Continuously monitors volumetric water content (VWC). If moisture drops below 40%, the water pump activates automatically until optimal hydration is restored.

---

## 🛠️ Bill of Materials (BOM)
| Component | Specification / Role |
| :--- | :--- |
| **Arduino Uno (ATmega328P)** | Central microcontroller managing sensor inputs and pump output |
| **Capacitive Soil Moisture Sensor v1.2** | Corrosion-resistant dielectric moisture transducer |
| **DS3231 RTC Module** | High-precision real-time clock for scheduled watering |
| **5V Relay Module** | Electronic switch controlling the mini water pump |
| **Submersible DC Water Pump** | Irrigation delivery actuator |
| **LCD 1602 with I2C** | Real-time display for moisture percentage and system status |

---

## 📌 GPIO Pinout Mapping
| Component | Component Pin | Arduino Uno Pin | Engineering Function |
| :--- | :--- | :--- | :--- |
| **Capacitive Moisture Sensor**| `Analog Out (AOUT)`| `A0` | Volumetric Moisture Measurement |
| **DS3231 RTC Module** | `SDA / SCL` | `A4 / A5` | I2C Time and Date Synchronization |
| **Relay Control Module** | `IN` | `Pin 7` | Pump Motor Power Switch |
| **I2C LCD Display** | `SDA / SCL` | `A4 / A5` | System Telemetry Display |

---

## 📂 Repository Structure
```text
📂 auto-plant-watering-system
├── 📂 firmware             <-- C++ source code (plant_watering.ino)
├── 📂 schematics           <-- Wiring and relay isolation guide
└── 📄 README.md            <-- Project documentation
