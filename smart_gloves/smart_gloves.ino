int boutonPlus = 4;
int boutonMoins = 5;

//set motors
int m1 = A1;
int m2= A2;
int m3 = A3;
int m4 = A4;
int m5 = A5;

int led1 = A6;


int Bmoins;
int Bplus;

int etat=0;

int speed = 130;
int MaxSpeed = 250;
int minSpeed = 130;

int pas = 30;

void setup() {
  // put your setup code here, to run once:
  pinMode(boutonPlus,INPUT_PULLUP);
  pinMode(boutonMoins,INPUT_PULLUP);

  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(m5,OUTPUT);

  pinMode(led1,OUTPUT);
  analogWrite(led1,0);


  Serial.begin(115200);
  Serial.println("hello");

}



void loop() {
  
  // put your main code here, to run repeatedly:
  Bmoins = digitalRead(boutonMoins);
  Bplus = digitalRead(boutonPlus);

  // Serial.println(Bmoins);
  // Serial.println(Bplus);



  if(Bplus==0 ){


    while(!digitalRead(boutonPlus)){
      delay(1);
    }
    led_on();
    speed = speed + pas;

    if(speed > MaxSpeed){
      speed = MaxSpeed;
    }
    
  }

  else if(Bmoins==0 ){

    while(!digitalRead(boutonMoins)){
      delay(1);
    }
    led_on();
    speed = speed - pas;
  
    if (speed < minSpeed){
      speed = minSpeed;
    }
    
  }
  
set_motors();
Serial.println(speed);
delay(10);
  

}


void set_motors(){
  analogWrite(m1,speed);
  analogWrite(m2,speed);
  analogWrite(m3,speed);
  analogWrite(m4,speed);
  analogWrite(m5,speed);
}

void led_on(){
  analogWrite(led1,200);
  delay(200);
  analogWrite(led1,0);
}


