#define LED 12 //use port 12 and GND
// setup function runs once when press reset or power board
void setup() {
  // put your setup code here, to run once:
  // initialize digital pin LED_BUILTIN as output
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12, HIGH); // turn LED on (HIGH is voltage level)
  delay(1000); // wait for second
  digitalWrite(12, LOW); // turn LED off by making voltage LOW
  delay(1000); // wait for second
} 