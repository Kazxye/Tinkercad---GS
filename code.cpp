// C++ code
//
/*
  Medidor de nível de água
*/

int waterlevel = 0;

long medidorDeDistancia(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  waterlevel = 0.01723 * medidorDeDistancia(3, 2);
  Serial.println(waterlevel);
  if (waterlevel > 200) {
    digitalWrite(8, HIGH);
    digitalWrite(10, LOW);
  }
  if (waterlevel < 100) {
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(6, HIGH);
  }
  digitalWrite(6, LOW);
  delay(10);
}