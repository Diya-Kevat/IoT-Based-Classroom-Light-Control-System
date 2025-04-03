# IoT-Based-Classroom-Light-Control-System

### 💡 Smart | 📡 IoT-Enabled | ⚡ Energy-Efficient  

This project is an **IoT-based motion-sensing light control system** designed for **automated energy management** in classrooms. It detects motion using a **PIR sensor**, automatically turning **lights ON** when movement is detected and **OFF** after 10 seconds of inactivity, reducing unnecessary power consumption. **ThingSpeak integration** allows real-time data logging and remote monitoring of motion count, light status, and energy usage.  

### 🔹 Features  
✅ **Automated Lighting** – Motion-based light activation & auto-off after inactivity  
✅ **Energy Monitoring** – Tracks power consumption and calculates savings  
✅ **ThingSpeak Integration** – Logs real-time motion and energy data for analysis  
✅ **WiFi Connectivity** – Enables remote monitoring via IoT  

### 🔹 Tech Stack  
🔹 **Hardware**: ESP32, PIR Motion Sensor, Relay Module  
🔹 **Software**: Arduino IDE, ThingSpeak API  
🔹 **Programming Language**: C++  

### 🔹 How It Works  
1️⃣ **Motion Detected** → Lights turn **ON**, event logged on ThingSpeak  
2️⃣ **No Motion for 10s** → Lights turn **OFF**, total ON time updated  
3️⃣ **Every 15s** → Motion count, light status, and power savings sent to ThingSpeak  

### 🔹 Team Contributions  
👩‍💻 **Naimisha Girish** – ThingSpeak setup, real-time data logging, energy tracking implementation  
👩‍💻 **Diya Kevat** – ESP32 programming, motion detection logic, WiFi integration  
👩‍💻 **Vaishnavi Nambiar** – Hardware assembly, sensor testing, data analysis, documentation  

### 🔹 Future Enhancements  
🚀 Adaptive lighting based on ambient brightness  
🚀 AI-powered motion pattern analysis  
🚀 Integration with smart assistants for voice control  

📌 A **smart, automated, and energy-efficient** solution for classrooms! ⚡📡💡
