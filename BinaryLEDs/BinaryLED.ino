int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int waitTime = 750;
int numbersInHexa = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
}

void loop() {
    for(int num = 0; num <= numbersInHexa; num++){
        flashLED(num);
        delay(waitTime);
    } 
}

void flashLED(int num){
  switch(num){
      case 0:
          digitalWrite(pin2, LOW);
          digitalWrite(pin3, LOW);
          digitalWrite(pin4, LOW);
          digitalWrite(pin5, LOW);
          break;
      case 1:
          digitalWrite(pin2, LOW);
          digitalWrite(pin3, LOW);
          digitalWrite(pin4, LOW);
          digitalWrite(pin5, HIGH);
          break;
      case 2:
          digitalWrite(pin2, LOW);
          digitalWrite(pin3, LOW);
          digitalWrite(pin4, HIGH);
          digitalWrite(pin5, LOW);
          break;
      case 3:
          digitalWrite(pin2, LOW);
          digitalWrite(pin3, LOW);
          digitalWrite(pin4, HIGH);
          digitalWrite(pin5, HIGH);
          break;
      case 4:
          digitalWrite(pin2, LOW);
          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, LOW);
          digitalWrite(pin5, LOW);
          break;
      case 5:
          digitalWrite(pin2, LOW);
          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, LOW);
          digitalWrite(pin5, HIGH);
          break;
      case 6:
          digitalWrite(pin2, LOW);
          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, HIGH);
          digitalWrite(pin5, LOW);
          break;
      case 7:
          digitalWrite(pin2, LOW);
          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, HIGH);
          digitalWrite(pin5, HIGH);
          break;
      case 8:
          digitalWrite(pin2, HIGH);
          digitalWrite(pin3, LOW);
          digitalWrite(pin4, LOW);
          digitalWrite(pin5, LOW);
          break;
      case 9:
          digitalWrite(pin2, HIGH);
          digitalWrite(pin3, LOW);
          digitalWrite(pin4, LOW);
          digitalWrite(pin5, HIGH);
          break;
      case 10:
          digitalWrite(pin2, HIGH);
          digitalWrite(pin3, LOW);
          digitalWrite(pin4, HIGH);
          digitalWrite(pin5, LOW);
          break;
      case 11:
          digitalWrite(pin2, HIGH);
          digitalWrite(pin3, LOW);
          digitalWrite(pin4, HIGH);
          digitalWrite(pin5, HIGH);
          break;
      case 12:
          digitalWrite(pin2, HIGH);
          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, LOW);
          digitalWrite(pin5, LOW);
          break;
      case 13:
          digitalWrite(pin2, HIGH);
          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, LOW);
          digitalWrite(pin5, HIGH);
          break;
      case 14:
          digitalWrite(pin2, HIGH);
          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, HIGH);
          digitalWrite(pin5, LOW);
          break;
      case 15:
          digitalWrite(pin2, HIGH);
          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, HIGH);
          digitalWrite(pin5, HIGH);
          break;    
  }
}
