String data;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()) {
    data = Serial.readString();
    Serial.println(data);
    if (data == 'a') {
      digitalWrite(13, HIGH);
    }
    if (data == 'b') {
      digitalWrite(13, LOW);
    }
  }
}
