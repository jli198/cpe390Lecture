void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogWriteResolution(12);
}

void loop() {
  // put your main code here, to run repeatedly:
  double del = 100; // 8: changed 20 to 100.
  double value = 0;
  double pi = 6.28318;
  double a = pi/5; // 8: changed 32 to 5. this represents 5 samples.
  for(double i = 0; i <= pi; i += a){
    value=2048+(2047*sin(i));
    analogWrite(DAC0, value);
    delayMicroseconds(del);
  }
}