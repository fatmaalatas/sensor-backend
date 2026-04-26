package org.example.sensorbackend;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import java.util.List;

@RestController
@RequestMapping("/api/sensor")
public class SensorController {

    @Autowired
    private SensorDataRepository repository;

    @PostMapping("/data")
    public String receiveData(@RequestBody SensorData data) {
        System.out.println("🚀 Veri Alindi -> Sicaklik: " + data.getTemperature() + " | Nem: " + data.getHumidity());

        // Veriyi veritabanına kaydediyoruz
        repository.save(data);

        return "Veri basariyla PostgreSQL'e kaydedildi!";
    }

    @GetMapping("/all")
    public List<SensorData> getAllData() {
        return repository.findAll();
    }
}