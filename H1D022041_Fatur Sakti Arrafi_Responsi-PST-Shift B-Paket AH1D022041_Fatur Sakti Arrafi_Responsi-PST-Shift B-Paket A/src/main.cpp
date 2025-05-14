#include <Arduino.h>

// Pin HC-SR04
const int trigPin = D5;
const int echoPin = D6;

//LED indikator
const int ledWarning = D1; // LED Merah
const int ledSafe = D2;    // LED Hijau

//Batas jarak aman (dalam cm)
const int batasJarak = 10;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(ledWarning, OUTPUT);
  pinMode(ledSafe, OUTPUT);
}

void loop() {
  long durasi;
  float jarak;

  // Kirim sinyal TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi ECHO
  durasi = pulseIn(echoPin, HIGH);

  // Hitung jarak (cm)
  jarak = durasi * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  // Logika indikator
  if (jarak<= batasJarak) {
    digitalWrite(ledWarning, HIGH);
    digitalWrite(ledSafe, LOW);
  } else {
    digitalWrite(ledWarning, LOW);
    digitalWrite(ledSafe, HIGH);
  }

  delay(1000); // Delay 1 detik
}