#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8); // RX, TX

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(1000);
  sendCommand("AT+CFUN=1", 1000);
  sendCommand("AT+CMGF=1", 1000);
}

void loop() {
  sendCommand("AT+CIPSEND", 1000);
  mySerial.println("HELO google.com\r");
  delay(1000);
  mySerial.println("AUTH LOGIN\r");
  delay(1000);
  mySerial.println("[BASE64 ENCODED USERNAME]\r");
  delay(1000);
  mySerial.println("[BASE64 ENCODED PASSWORD]\r");
  delay(1000);
  mySerial.println("MAIL FROM:<[FROM EMAIL ADDRESS]>\r");
  delay(1000);
  mySerial.println("RCPT TO:<[TO EMAIL ADDRESS]>\r");
  delay(1000);
  mySerial.println("DATA\r");
  delay(1000);
  mySerial.println("Subject: Test Email\r\n");
  mySerial.println("Hello, this is a test email from S800L\r\n");
  mySerial.println("\r\n.\r");
  delay(1000);
  mySerial.println("QUIT");
  delay(1000);
}

void sendCommand(String command, int delayTime) {
  mySerial.println(command);
  delay(delayTime);
  while (mySerial.available()) {
    Serial.write(mySerial.read());
  }
}
