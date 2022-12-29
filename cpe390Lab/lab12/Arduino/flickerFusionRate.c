#define LED 12 //use port 12 and GND
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12, HIGH);
  delay(12); // where it doesn't look like its blinking from afar
  digitalWrite(12, LOW);
  delay(12); // where it doesn't look like its blinking from afar
} 