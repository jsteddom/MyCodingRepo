class Stoplight {
public:
  Stoplight() = default;
  int redLight {13}; 
  int yellowLight {12};
  int blueLight {11};
};

Stoplight myStopLight {};
void setup() {
  // put your setup code here, to run once:
  
  pinMode(myStopLight.redLight, OUTPUT);
  pinMode(myStopLight.yellowLight, OUTPUT);
  pinMode(myStopLight.blueLight, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(myStopLight.blueLight, HIGH);
  delay(500);
  digitalWrite(myStopLight.blueLight, LOW);
  digitalWrite(myStopLight.yellowLight, HIGH);
  delay(500);
  digitalWrite(myStopLight.yellowLight, LOW);
  digitalWrite(myStopLight.redLight, HIGH);
  delay(500);
  digitalWrite(myStopLight.blueLight, HIGH);
  digitalWrite(myStopLight.redLight, HIGH);
  digitalWrite(myStopLight.yellowLight, HIGH);
  delay(500);
  digitalWrite(myStopLight.blueLight, LOW);
  digitalWrite(myStopLight.redLight, LOW);
  digitalWrite(myStopLight.yellowLight, LOW);
  delay(200);
}
