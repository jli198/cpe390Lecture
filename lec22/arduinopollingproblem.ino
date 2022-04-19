/*
  on Arduino to check 2 buttons and blink light 10 Hz
*/
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}
void loop() {
  digitalWrite(2, HIGH);
  delay(50); // 10ms = ??? = .05
  digitalWrite(2, LOW);
  delay(50); // 10MS = .05
  if (digitalRead(3) == HIGH) {

  }
  if (digitalRead(4) == HIGH) {
    
  }
  /*
  digitalWrite(2, HIGH);
  for (int i = 0; i < 50; i++) {
    delay(10:
    if (digitalRead(3) == HIGH) {

    }
  }
  */
}