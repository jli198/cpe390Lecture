//Code to blink LED
void setup() {
  // put your setup code here, to run once:
  //initalize digital pin LED_BUILTIN as output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //since LED has to blink repeatedly, blinking code is placed in loop
  digitalWrite(LED_BUILTIN, LOW);
  //D1 Mini: turns LED ON
  delay(1000);
  //keep it ON for 1000 milli-seconds which is 1 second
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  //D1 Mini: turns LED OFF delay(1000);
  //try varying delay time to see different blinking elements

}