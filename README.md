# Heartbeat Sensor with ESP32 and MAX30100

## Overview

This project is a simple real-time heartbeat monitoring system built using an ESP32 microcontroller and the MAX30100 pulse oximeter/heart rate sensor. The system reads pulse data from a fingertip and calculates an estimated heart rate (BPM) while displaying the results through the serial monitor.
The purpose of this project was to explore embedded systems development, sensor communication over I²C, and real-time physiological data acquisition using the ESP32 platform.
This project was developed using PlatformIO in Visual Studio Code.

---

## Features
- Real-time heart rate monitoring
- Communication using the I²C protocol
- ESP32-based embedded implementation
- Serial monitor output for BPM and SpO₂ readings
- Beat detection callback support
- Adjustable LED current for signal optimization

---

## Hardware Used
| Component | Description |
|---|---|
| ESP32 Dev Board --> Main microcontroller |
| MAX30100 Sensor --> Pulse oximeter and heart rate sensor |
| USB Cable --> Used for programming and power |
| Jumper Wires --> Sensor connections |

---

## Wiring
| MAX30100 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

---

## Software and Tools
- Visual Studio Code
- PlatformIO
- Arduino Framework for ESP32
- MAX30100 Pulse Oximeter Library

---

## How It Works
The MAX30100 sensor uses infrared and red LEDs to detect blood flow changes in the fingertip. These changes are processed to estimate heart rate and oxygen saturation levels.
The ESP32 continuously polls the sensor through the I²C interface and processes incoming data using the MAX30100 library. Once a heartbeat is detected, the BPM value is calculated and printed to the serial monitor.

---

## Project Structure

```text
heartbeat_sensor/
│
├── src/
│   └── main.cpp
│
├── platformio.ini
│
└── README.md
```

---

## PlatformIO Configuration

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino

monitor_speed = 115200
upload_speed = 115200

lib_deps =
    https://github.com/oxullo/Arduino-MAX30100.git
```

---

## Running the Project

1. Open the project in VS Code with PlatformIO installed.

2. Connect the ESP32 board.

3. Upload the code.

4. Open the serial monitor:

5. Place a finger over the MAX30100 sensor and wait several seconds for stable readings.

---

## Challenges Encountered

During development, several practical hardware and embedded system issues were encountered:
- Incorrect USB cable preventing data transfer
- ESP32 upload/boot mode issues
- Noisy or unstable sensor readings
- BPM values occasionally dropping to zero
- Sensitivity to finger placement and ambient lighting

These issues provided useful experience troubleshooting embedded hardware systems and serial communication problems.

---

## Future Improvements

Potential future improvements for the project include:
- OLED display integration
- Wireless BPM monitoring through Wi-Fi
- Mobile/web dashboard visualization
- Data logging to SD card or cloud services
- Signal filtering and averaging algorithms
- Migration to the MAX30102 sensor for improved accuracy

---

## Disclaimer

This project is intended for educational and prototyping purposes only. The MAX30100 is not a medical-grade device and should not be used for professional medical diagnostics.

---

## Author

Developed using ESP32 and MAX30100 as an embedded systems and sensor integration project.
