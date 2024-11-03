#define PIR_SENSOR_OUTPUT_PIN 39  /* PIR sensor O/P pin */
#define LED_PIN 40                /* LED pin (connected to pin 20) */
int warm_up;

void setup() {
  pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT);   /* PIR sensor input */
  pinMode(LED_PIN, OUTPUT);                /* LED output */
  Serial.begin(115200); /* Define baud rate for serial communication */
  Serial.println("Waiting For Power On Warm Up");
  delay(20000); /* Power On Warm Up Delay */
  Serial.println("Ready!");
}

void loop() {
  int sensor_output;
  sensor_output = digitalRead(PIR_SENSOR_OUTPUT_PIN);

  if (sensor_output == LOW)
   {
    if (warm_up == 1) {
      Serial.print("Warming Up\n\n");
      warm_up = 0;
      delay(1000);
    }
    Serial.print("No object in sight\n\n");
    digitalWrite(LED_PIN, LOW);  // Turn off the LED
    delay(1000);
  } else {
    Serial.print("Object detected\n\n");   
    warm_up = 1;
    digitalWrite(LED_PIN, HIGH);  // Turn on the LED
    delay(3000);
  }
}
