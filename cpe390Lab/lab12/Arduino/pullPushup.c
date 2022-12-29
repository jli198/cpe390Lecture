void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  //pinMode(7, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
   int sensorVal = digitalRead(2);
   Serial.println(sensorVal);
   if (sensorVal == HIGH){
     digitalWrite(13, LOW);
   } else{
     digitalWrite(13, HIGH);
   }
   if (digitalRead(2)==LOW){
      digitalWrite(8, HIGH);
      delay(150);
      digitalWrite(8, LOW);
      delay(50);
   }
}