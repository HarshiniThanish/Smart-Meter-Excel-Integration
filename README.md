#  Smart Energy Meter using ESP8266, PZEM-004T and PLX-DAQ

This project implements a Smart Energy Meter that monitors real-time electrical parameters such as voltage, current, power, and energy using the **PZEM-004T v3.0** sensor and **ESP8266 NodeMCU**. A unique feature of this project is the use of **PLX-DAQ** for **offline Excel data logging**, which allows users to track power usage without internet connectivity. Firebase integration is currently in progress to enable cloud-based monitoring in future versions.

---

##  Components Used

- **ESP8266 NodeMCU** – Wi-Fi microcontroller
- **PZEM-004T v3.0** – Energy monitoring sensor
- **PLX-DAQ v2.11** – Excel-based serial data logger
- **Microsoft Excel** – For real-time data logging and graphs
- **AC Power Source & Load** – For testing live energy usage
- **USB cable** – For data transfer and powering the NodeMCU

---

## 🔗 Circuit Connections

### ESP8266 to PZEM-004T:

| NodeMCU Pin | GPIO | PZEM Pin | Purpose |
|-------------|------|----------|---------|
| D5          | 14   | RX       | ESP → PZEM data |
| D6          | 12   | TX       | PZEM → ESP data |
| GND         | —    | GND      | Common ground |
| Vin         | —    | Vcc      | 5V power for PZEM |

>  Use the **Vin pin** (5V from USB) to power the PZEM-004T. Do not connect 5V directly to GPIOs.

### PZEM AC Wiring:

- **L (Line)** – Connect to live wire through a load (e.g., bulb)
- **N (Neutral)** – Connect to AC neutral

**Caution:** Use proper insulation and safety precautions while handling AC wiring.

---

##  Excel Logging with PLX-DAQ

- Connect the NodeMCU to your PC using a USB cable.
- Open the provided `PLX-DAQ-v2.11.xlsm` file in Excel.
- Enable Macros.
- Choose the correct COM port and set baud rate to `9600`.
- Data will begin logging in real-time into Excel with proper headers and values.

---

##  Project Files

- `sketch.ino` – Arduino code for reading and logging data
- `connections.txt` – Circuit wiring explanation
- `PLX-DAQ-v2.11.xlsm` – Excel file for logging and visualization
- `Ouptut.png` – Sample output screenshot from Excel

---

##  Features

- Offline energy monitoring via PLX-DAQ
- Real-time logging of:
  - Voltage (V)
  - Current (A)
  - Power (W)
  - Energy (Wh)
  - Power Factor
- Firebase integration (Work in Progress)
- Easy-to-use Excel dashboard

---

##  Future Enhancements

- Push data to Firebase Realtime Database
- Build a live web dashboard using Firebase
- Add mobile alerts and energy usage reports
- Implement overload detection logic

---

##  Author

**Harshini T**  
B.Tech – Electrical and Computer Science Engineering  
Vellore Institute of Technology, Chennai

---

##  License

This project is licensed under the [MIT License](LICENSE).
