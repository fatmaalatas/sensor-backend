package org.example.sensorbackend; // Kendi paket adın neyse o kalsın

import jakarta.persistence.*;
import lombok.Data;
import java.time.LocalDateTime;

@Data // Lombok harikası! Getter ve Setter'ları arka planda kendi hallediyor.
@Entity
@Table(name = "sensor_readings")
public class SensorData {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private double temperature; // Senin yazdığın gibi double kalabilir
    private double humidity;

    // Verinin geliş zamanını otomatik kaydetmek için
    private LocalDateTime timestamp = LocalDateTime.now();
}