#include <cstdint>
void setup() {
  //uint64_t x;
  // note: don't use float unless really need it on original arduino
  // declaring float will take approx 4k memory float y;
  pinMode(2, OUTPUT); // will read 5V or 0V
  pinMode(7, INPUT); // will read
  Serial.begin(9600); // speed to communicate with host computer
}

/*
  Arduino UNO voltage = 5V
  Arduino Due voltage = 3.3V
*/
void loop() {
  digitalWrite(2, HIGH); // write high voltage to that pin
  digitalWrite(2, LOW); // write low voltage (0V) to that pin

  digitalWrite(3, HIGH); // will not work since did not specify OUTPUT
  int v = digitalRead(7);
  if (v == HIGH || v == LOW) {
    Serial.println("duh!"); // this takes 4 * 1/960th of second
  }


  if (digitalRead(7) == LOW) {
    
  }

  if (digitalRead(7) == HIGH) {

  }

  // analogReadResolution(12); // set resolution if different than default
  int a = analogRead(A0); // read analog input
  // UNO: 10 bit accuracy, 7700 samples/second 0..1023 (5V-0)/(1023-0) (2.5V-0)/(512-0)
  //Due: 12 bit accuracy, 1M s/s

  // for any PWM pin (Pulse width modulation)
  analogWrite(3, 128); // number from 0 to 255 controls duty cycle

  // analogWriteResolution(12) // set resolution if different
  // for Arduino Due, can write to two DAC pins to put out waveforms
  analogWrite(DAC0, 2047); // 12 bit accuracy
}

/*
int main() {
  setup();
  for (;;) {
    loop();
  }
}
*/