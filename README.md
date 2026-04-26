# 🚀 IoT Real-Time Temperature & Humidity Tracking System

A full-stack IoT solution that captures temperature and humidity data from an **ESP32** (via Wokwi simulation), processes it through a **Spring Boot REST API**, and persists it in a **PostgreSQL** database.

## 🏗️ System Architecture
The system consists of three main layers:
1. **Embedded:** ESP32 + DHT22 Sensor (C++).
2. **Backend:** Spring Boot (Java 17) + Spring Data JPA.
3. **Database:** PostgreSQL for persistent storage.

## 🌟 Features
- **Real-Time Data Streaming:** Seamless data transfer from hardware to cloud.
- **Data Persistence:** Historical data storage with PostgreSQL.
- **Containerized Architecture:** Fully dockerized using Docker Compose for easy testing.
- **Cloud Ready:** Deployed and running on Railway.

## 🛠️ Tech Stack
- **Backend:** Java 17, Spring Boot, Maven
- **Database:** PostgreSQL
- **DevOps:** Docker, Docker Compose, Railway
- **Embedded:** C++, ESP32, DHT22 Sensor

## 🚀 How to Run Locally (Docker)
This project is containerized. You don't need to install Java or PostgreSQL manually.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/YOUR_GITHUB_USERNAME/sensor-backend.git](https://github.com/YOUR_GITHUB_USERNAME/sensor-backend.git)
   cd sensor-backend