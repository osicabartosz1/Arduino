#define A 2
#define B 3
#define C 4
#define D 5
 
#define NUMBER_OF_STEPS_PER_REV 512

void setup()
{
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  Serial.begin(9600);
}

void write(int a,int b,int c,int d)
{
  digitalWrite(A,a);
  digitalWrite(B,b);
  digitalWrite(C,c);
  digitalWrite(D,d);
}

void onestepforward(){

  write(0,0,1,0);
  myDelay(5);
  write(0,1,0,0);
  myDelay(5);
  write(1,0,0,0);
  myDelay(5);
}

void onestepforward20(){
  write(1,0,0,0);
  myDelay(5);
  write(1,1,0,0);
  myDelay(5);
  write(0,1,0,0);
  myDelay(5);
  write(0,1,1,0);
  myDelay(5);
  write(0,0,1,0);
  myDelay(5);
  write(1,0,1,0);
  myDelay(5);
}
void onestepback(){
  write(1,0,0,1);
  myDelay(5);
  write(0,0,0,1);
  myDelay(5);
  write(0,0,1,1);
  myDelay(5);
  write(0,0,1,0);
  myDelay(5);
  write(0,1,1,0);
  myDelay(5);
  write(0,1,0,0);
  myDelay(5);
  write(1,1,0,0);
  myDelay(5);
  write(1,0,0,0);
  myDelay(5);
}
void loop()
{
  int i;
  i=0;
  while(i<NUMBER_OF_STEPS_PER_REV){
    onestepforward20();
    Serial.print("step: ");Serial.println(i);
    i++;
  }
  delay(10000);
}

void myDelay(int type)
{
  delay(20);
}

