// Pin configuration
const int buttonPin1 = 2;  // Pin for the first button
const int lampSet1Pin = 3;  // Pin for the first lamp set

const int buttonPin2 = 4;  // Pin for the second button
const int lampSet2Pin = 5;  // Pin for the second lamp set

const unsigned long duration = 15000;  // Duration to keep the lamps on (in milliseconds)

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(lampSet1Pin, OUTPUT);

  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(lampSet2Pin, OUTPUT);
}

void loop() {
  // Check if the first button is pressed
  if (digitalRead(buttonPin1) == LOW) {
    turnOnLampSet(lampSet1Pin);
  }

  // Check if the second button is pressed
  if (digitalRead(buttonPin2) == LOW) {
    turnOnLampSet(lampSet2Pin);
  }
}

void turnOnLampSet(int lampSetPin) {
  digitalWrite(lampSetPin, HIGH);  // Turn on the corresponding lamp set
  delay(duration);  // Keep the lamp set on for 15 seconds
  digitalWrite(lampSetPin, LOW);  // Turn off the lamp set
}