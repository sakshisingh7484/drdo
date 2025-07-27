const int sensorpin=A0;
const int motorpin=9;
int stepdutycycle=50;
int initialdutycycle=100;

void setup(){
  Serial.begin(9600);
  pinMode(motorpin,OUTPUT);
  pinMode(sensorpin,OUTPUT);
}
void loop(){
  int pressure=analogRead(sensorpin);
  Serial.println(pressure);
  if(pressure>600){
    for(initialdutycycle=0;initialdutycycle<=255;initialdutycycle+=stepdutycycle){
      analogWrite(motorpin,initialdutycycle);
      delay(50);
    }
  }

else{
  for(initialdutycycle=255;initialdutycycle>=0;initialdutycycle-=stepdutycycle){
    analogWrite(motorpin,initialdutycycle);
    delay(50);

  }
}
}
