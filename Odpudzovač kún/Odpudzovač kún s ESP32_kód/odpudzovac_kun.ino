const int pirPin = 14; // PIR senzor na GPIO14
const int buzzerPin = 27; // Bzučiak na GPIO27
const int ledPin = 25;    // LED na GPIO25

void setup() {
    pinMode(pirPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200); // Na ladenie
}

void loop() {      // opakuj dookola
    int pirState = digitalRead(pirPin); // Stav PIR senzora
    if (pirState == HIGH) { // Detegovaný pohyb
        Serial.println("Pohyb detekovaný! Spúšťam zariadenie.");
        digitalWrite(buzzerPin, HIGH); // Zapneme bzučiak
        digitalWrite(ledPin, HIGH);    // Zapneme LED
        delay(5000);                   // Beží 5 sekúnd
        digitalWrite(buzzerPin, LOW);  // Vypneme bzučiak
        digitalWrite(ledPin, LOW);     // Vypneme LED
    }
    Serial.println(pirState);
    delay(500); // Čakanie pred ďalším cyklom
}
