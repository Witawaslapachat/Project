const int analogInPin = A0; // กำหนดขา input เซ็นเซอร์
const int Relay = 2; // กำหนดขา input รีเลย์

int sensorValue = 0;        // ตัวแปรค่า Analog
int outputValue = 0;        // ตัวแปรสำหรับ Map เพื่อคิด %

void setup() {
  Serial.begin(9600); 
  pinMode(Relay, OUTPUT); // กำหนด รีเลย์เป็น Output
}

void loop() {
  sensorValue = analogRead(analogInPin); 
  outputValue = map(sensorValue, 0, 1023, 100, 0); 

  Serial.print(outputValue); 
  Serial.println(" %"); 

  if (outputValue <= 40) {  //ตั้งค่า % ที่ต้องการจะรดน้ำต้นไม้
    digitalWrite(Relay, HIGH); // เมื่อความชื้นน้อยกว่า 40% ให้เปิดปั๊มน้ำ
  }
  else {
    digitalWrite(Relay, LOW); // เมื่อความชื้นมากกว่า 40% ปิดปั๊ม
  }
  delay(500);
}
