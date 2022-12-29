void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogWriteResolution(12);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 100Khz
  analogWrite(DAC0, 2048);
  /*analogWrite(DAC0, 133056);
  analogWrite(DAC0, 202654);
  analogWrite(DAC0, 178090);
  analogWrite(DAC0, 71646);
  analogWrite(DAC0, -67550);
  analogWrite(DAC0, -173994);
  analogWrite(DAC0, -198558);*/
  analogWrite(DAC0, -128960);
}