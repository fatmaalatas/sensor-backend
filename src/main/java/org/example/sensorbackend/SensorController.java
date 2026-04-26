package org.example.sensorbackend;

import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/sensor")
public class SensorController {

    @PostMapping("/data")
    public String receiveData(@RequestBody SensorData data) {
        System.out.println("🚀 New data received from ESP32!");
        System.out.println("🌡️ Temperature: " + data.getTemperature() + " °C");
        System.out.println("💧 Humidity: %" + data.getHumidity());
        System.out.println("-------------------------------");

        return "Data received successfully by Spring Boot!";
    }
}