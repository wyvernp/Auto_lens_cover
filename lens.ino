int directionPin = 2;
int stepPin = 3;
int incomingByte = 0; // for incoming serial data
int j;
void setup() {

  Serial.begin(9600);
  Serial.println("Starting StepperTest");

  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  //digitalWrite(directionPin, LOW);
}

void loop()
  {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    if (incomingByte == 111) {
        for(j=0; j<=399; j++) {
        digitalWrite(directionPin, LOW); 
        digitalWrite(stepPin, HIGH);
        delay(2);
        digitalWrite(stepPin, LOW);
        delay(3);
        }
      Serial.print("opening");
    }
    if (incomingByte == 99) {
        for(j=0; j<=399; j++) {
        digitalWrite(directionPin, HIGH); 
        digitalWrite(stepPin, HIGH);
        delay(2);
        digitalWrite(stepPin, LOW);
        delay(3);
        }
      Serial.print("closing");
     } 
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);
    }
 }
