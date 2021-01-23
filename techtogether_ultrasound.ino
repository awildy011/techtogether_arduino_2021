int trig=13;
int echo=11;
float interval;
float distance;
float sound =776.5; //miles per hour
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode (trig, OUTPUT);

}

void loop() {
  // this gets the back and forth going
  digitalWrite(trig, LOW);
  delayMicroseconds(2000);
  digitalWrite(trig, HIGH);
  delayMicroseconds(15);
  digitalWrite(trig, LOW);
  delayMicroseconds(10);

  interval = pulseIn(echo, HIGH);
  interval = interval/1000000; //to seconds
  interval = interval/3600; 
  distance = sound *interval;
  distance = distance/2; // to the object
  distance = distance*63360;

  
  
  Serial.println(distance);
  delay(100); // not using delays is not safe
}
