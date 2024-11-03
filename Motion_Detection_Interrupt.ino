const int PIR_SENSOR_OUTPUT_PIN = 39;  /* PIR sensor O/P pin */
const int LED_PIN = 40;                /* LED pin (connected to pin 20) */
volatile bool motion_detected = false;  // Use a volatile variable to indicate motion

void setup() {
  pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT);   /* PIR sensor input */
  pinMode(LED_PIN, OUTPUT);                /* LED output */
  
  // Attach an interrupt to PIR_SENSOR_OUTPUT_PIN, call the handleMotion function on RISING edge
  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR_OUTPUT_PIN), handleMotion, RISING);
  
  Serial.begin(115200); /* Define baud rate for serial communication */
  Serial.println("Waiting For Power On Warm Up");
  delay(20000); /* Power On Warm Up Delay */
  Serial.println("Ready!");
}

void loop() {
  if (motion_detected) {   // Check if motion is detected
    Serial.println("Object detected");
    digitalWrite(LED_PIN, HIGH);  // Turn on the LED
    delay(3000);  // Keep the LED on for 3 seconds
    digitalWrite(LED_PIN, LOW);   // Turn off the LED
    motion_detected = false;      // Reset the motion detection flag
  }
}

void handleMotion() {
  motion_detected = true;   // Set motion detected flag
}
