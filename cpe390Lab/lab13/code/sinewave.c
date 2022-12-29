void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogWriteResolution(12);
}

void loop() {
  // put your main code here, to run repeatedly:
  double del = 20; // for 8, change 20 to 100.
  double value = 0;
  double pi = 6.28318;
  double a = pi/32; // for 8, change 32 to 5. this represents 5 samples.
  for(double i = 0; i <= pi; i += a){
    value=2048+(2047*sin(i));
    analogWrite(DAC0, value);
    delayMicroseconds(del);
  }
}