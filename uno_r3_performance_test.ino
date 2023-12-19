void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long startTime = millis(); // Get the start time

  // Perform a simple task, for example, a loop
  for (int i = 0; i < 10000; i++) {
    Serial.println(i);
  }

  unsigned long endTime = millis(); // Get the end time
  unsigned long elapsedTime = endTime - startTime; // Calculate the elapsed time
  Serial.println("Elapsed time (s) on Uno R3: ");
  Serial.println(elapsedTime/1000.0);
  delay(10000); // Delay for better readability
}

// Elapsed time (s) on Uno R3: 
// 61.18 sec.
