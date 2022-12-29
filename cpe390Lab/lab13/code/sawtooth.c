void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(DAC0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  double inc = 4095.0/32.0;
  double f = 440.0 * 32.0;
  double del = 62.5;
  for(double i = 0; i <= 4095.0; i += inc){
    analogWriteResolution(12);
    analogWrite(DAC0, i);
    delayMicroseconds(del);
  }
}