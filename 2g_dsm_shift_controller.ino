//2button transmission controller
int button = 2;     // Gear 1
int button1 = 4;     // Gear 2
int solenoid1 = 10; 
int solenoid2 = 11;
int pressCount = 1;
int count = 0;
int buttonstate1=0;
int buttonstate2=0;

void setup(){
  pinMode(solenoid1,OUTPUT); 
  pinMode(solenoid2,OUTPUT);
  pinMode(button,INPUT);
  pinMode(button1,INPUT);
}

void loop(){
  buttonstate1 = digitalRead(button);
  buttonstate2 = digitalRead(button1);
 
  if (buttonstate1 == HIGH && pressCount < 4){
   pressCount=(count + 1);
  }
  if(buttonstate2 == HIGH && pressCount > 1){
   pressCount=(count - 1);
  }

  switch(pressCount){
    case 1: //FIRST GEAR ON-ON
      digitalWrite(solenoid1,HIGH);
      digitalWrite(solenoid2,HIGH);
      break;
  
    case 2:  //SECOND GEAR ON-OFF
      digitalWrite(solenoid1,HIGH);
      digitalWrite(solenoid2,LOW);
      break;
   
    case 3:  //THIRD GEAR OFF-OFF
      digitalWrite(solenoid1,LOW);
      digitalWrite(solenoid2,LOW);
      break;
     
    case 4:  //OVERDRIVE OFF-ON
      digitalWrite(solenoid1,LOW);
      digitalWrite(solenoid2,HIGH);
      break; 
  }
}
