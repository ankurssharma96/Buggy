int lm1=5;
int lm2=6;
int rm1=7;
int rm2=8;
float duration;
void setup()
{
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
}

void forward(){
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  delay(5);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(10);
}

void left(){
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(5);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(10);
}

void right(){
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  delay(2);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(5);
}

void brake(){
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}

float irl(){
  return analogRead(A0); 
}

float irr(){
  return analogRead(A1); 
}

float gate(){
  return analogRead(A2);
}

int gray=400;
int barr=0;
int blacks=0;
void loop()
{
    float irreadl=irl();
   float irreadr=irr();
   
    float gates=gate();
    if(gates>gray){
      brake();
      delay(1000);
      irreadl=irl();
   irreadr=irr();
      while(gates>gray){
        if(irreadl>gray&&irreadr>gray){
      forward();
    }
    else if(irreadl<gray&&irreadr>gray){
      left();
    }
    else if(irreadl>gray&&irreadr<gray){
     right();
    }
    irreadl=irl();
   irreadr=irr();
    gates=gate();
      }
    }
  
   irreadl=irl();
   irreadr=irr();
   
   if(blacks!=9){
    if(irreadl>gray&&irreadr>gray){
      forward();
    }
    else if(irreadl<gray&&irreadr>gray){
      left();
    }
    else if(irreadl>gray&&irreadr<gray){
     right();
    }
    else if(blacks==1&&irreadl<gray&&irreadr<gray){
      blacks++;
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      delay(20);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      delay(800);                //Optimize
    }
    else if(blacks!=5&&blacks!=1&&irreadl<gray&&irreadr<gray){
      blacks++;
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      delay(100);                 //Optimize
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
      
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,LOW);
      delay(50);                  //Optimize
    }
    else if(blacks==5&&irreadl<gray&&irreadr<gray){
      blacks++;
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      delay(700);                //Optimize
    }
   }   
   else{
    brake();
   }
}

