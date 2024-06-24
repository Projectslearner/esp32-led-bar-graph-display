/*
    Project name : ESP32 LED Bar Graph Display
    Modified Date: 24-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp32-led-bar-graph-display
*/

// Define the number of LEDs in the bar graph
const int numLEDs = 10;

// Define an array to hold the GPIO pins connected to each LED
const int ledPins[numLEDs] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // Example GPIO pins

void setup() {
  // Initialize all LED pins as outputs
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Example: Display a bar graph based on a variable (0 to numLEDs)
  int sensorValue = analogRead(A0); // Read sensor value (example)
  int ledCount = map(sensorValue, 0, 1023, 0, numLEDs); // Map sensor value to LED count

  // Display the LED bar graph
  for (int i = 0; i < numLEDs; i++) {
    if (i < ledCount) {
      digitalWrite(ledPins[i], HIGH); // Turn on LEDs up to the ledCount
    } else {
      digitalWrite(ledPins[i], LOW); // Turn off LEDs beyond the ledCount
    }
  }

  delay(100); // Adjust delay as needed for display refresh rate
}
