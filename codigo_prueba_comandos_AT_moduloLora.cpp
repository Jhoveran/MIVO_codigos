// Configuración de UART2 (Serial2) para LoRa
#define RXD2 16 // RX2 del ESP32 conectado al UART2_TX del LoRa
#define TXD2 17 // TX2 del ESP32 conectado al UART2_RX del LoRa

void setup() {
  Serial.begin(9600); // Monitor serial para depuración
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2); // UART2 para LoRa
  delay(2000); // Esperar un poco para inicialización
  Serial.println("Iniciando comunicación LoRa...");
}

void loop() {
  // Enviar comandos al LoRa desde el monitor serial
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Leer comando del monitor serial
    Serial2.println(command); // Enviar al LoRa
  }

  // Recibir datos del LoRa y mostrarlos en el monitor serial
  if (Serial2.available() > 0) {
    String response = Serial2.readStringUntil('\n'); // Leer respuesta del LoRa
    Serial.println("LoRa: " + response);
  }
}
