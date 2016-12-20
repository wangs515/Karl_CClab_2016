
int buttonPin = 7;
int ledPin = 13;
boolean on = false;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,INPUT);
  pinMode(buttonPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH) {
    if(on == true){
      on = false;
      } else{
        on = true;
      }
    }

    if (on == true) {
    digitalWrite(ledPin,HIGH);
    }
    else {
    digitalWrite(ledPin,LOW);
    }

    delay(500);
}
