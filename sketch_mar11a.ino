#include <Servo.h>
#include <NewPing.h>

Servo hip1;
Servo knee11;
Servo hip2;
Servo knee21;
Servo hip3;
Servo knee31;
Servo hip4;
Servo knee41;
Servo eye;

#define TRIGGER_PIN  A1
#define ECHO_PIN     A2 
#define MAX_DISTANCE 200 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int b;
int x;
int w;
int up;
int up2;
int up3;
int down;
int down2;
int steps;
int rightsteps;
int leftsteps;
int back;
int pos;
int sensor = A0;
int distance = (sonar.ping_cm());

//////////////////////////////////////
void setup()
{
  pinMode(13, OUTPUT);  // LED pin
  // assign servos to pins and center servos
  hip1.attach(5);
  hip1.write(90);
  knee11.attach(6);
  knee11.write(90);
  hip2.attach(7);
  hip2.write(90);
  knee21.attach(8);
  knee21.write(90);
  hip3.attach(9);
  hip3.write(90);
  knee31.attach(10);
  knee31.write(90);
  hip4.attach(11);
  hip4.write(90);
  knee41.attach(12);
  knee41.write(90);
  eye.attach(4);
  eye.write(90);
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}
//////////////////////////////////////
void idle() // this is the delay between the steps -> walking speed
{
  delay(100);  // if set to a bigger number (more delay between the steps -> slower walking) you will see the walking pattern more clearly
}
//////////////////////////////////////
void test() /* just for debugging -> if need a delay between the subroutines
               you can let the LED blink as an indicator that something is still running  */
{
  for (b = 0; b < 3; b++) // this let the LED blink 5 times
  {
    digitalWrite(13, HIGH);   // turn the LED on
    delay(300);               // wait for .5 second
    digitalWrite(13, LOW);    // turn the LED off
    delay(300);
  }
}
//////////////////////////////////////
void standup()
{
  up2 = 90;
  up3 = 90;
  hip1.write(70);
  hip2.write(80);
  hip3.write(120);
  hip4.write(70);
  for (up = 90; up < 170; up++)
  {
    knee11.write(up);
    up2 = up2 - 1;
    knee21.write(up2);
    delay(20);
  }

  for (up = 90; up < 180; up++)
  {
    knee31.write(up);
    up3 = up3 - 1;
    knee41.write(up3);
    delay(15);
  }
}
//////////////////////////////////////
void sleep()
{
  // hips
  hip1.write(70);
  hip2.write(90);
  hip3.write(70);
  hip4.write(90);
  // knees
  knee11.write(0);
  knee21.write(180);
  knee31.write(0);
  knee41.write(180);
}
//////////////////////////////////////
void stand()
{
  hip1.write(70);
  knee11.write(170);
  delay(20);
  hip2.write(80);
  knee21.write(20);
  delay(20);
  hip3.write(80);
  knee31.write(170);
  delay(20);
  hip4.write(70);
  knee41.write(20);
  delay(20);
}
//////////////////////////////////////
void forward()
{
  // lift front right knee, move front right hip forward and rear right hip backward, lower front right knee
  knee31.write(140);  // lower the diagonal opposite leg a bit to keep the balance
  knee11.write(140);
  idle();
  hip1.write(45);
  hip4.write(90);
  idle();
  knee11.write(170);
  knee31.write(170);  // put the diagonal opposite leg down to keep the balance
  // lift rear left knee, move rear left hip forward and front right hip backward, lower rear left knee
  knee11.write(140);  // lower the diagonal opposite leg a bit to keep the balance
  knee31.write(140);
  idle();
  hip3.write(120);
  hip1.write(110);
  idle();
  knee31.write(170);
  knee31.write(170);  // put the diagonal opposite leg down to keep the balance
  // lift front left knee, move front left hip forward and rear left hip backward, lower front left knee
  knee41.write(50);  // lower the diagonal opposite leg a bit to keep the balance
  knee21.write(50);
  idle();
  hip2.write(110);
  hip3.write(60);
  idle();
  knee21.write(20);
  knee41.write(20);  // put the diagonal opposite leg down to keep the balance
  // lift rear right knee, move rear right hip forward and front left hip backward, lower rear right knee
  knee21.write(50);  // lower the diagonal opposite leg a bit to keep the balance
  knee41.write(50);
  idle();
  hip4.write(30);
  hip2.write(50);
  idle();
  knee41.write(20);
  knee21.write(20);  // put the diagonal opposite leg down to keep the balance
  idle();
}
/////////////////////////////////////
void rightturn()
{
  // lift front right knee, move front right hip forward and rear right hip backward, lower front right knee
  knee11.write(150);
  idle();
  hip1.write(30);
  hip4.write(90);
  idle();
  knee11.write(170);
  // lift rear left knee, move rear left hip forward and front right hip backward, lower rear left knee
  knee31.write(150);
  idle();
  hip3.write(130);
  hip1.write(100);
  idle();
  knee31.write(170);
  // lift front left knee, move front left hip forward and rear left hip backward, lower front left knee
  knee21.write(40);
  idle();
  hip2.write(130);
  hip3.write(50);
  idle();
  knee21.write(20);
  // lift rear right knee, move rear right hip forward and front left hip backward, lower rear right knee
  knee41.write(40);
  idle();
  hip4.write(70);
  hip2.write(50);
  idle();
  knee41.write(20);
  idle();
}
/////////////////////////////////////
void leftturn()
{
  // lift front right knee, move front right hip forward and rear right hip backward, lower front right knee
  knee11.write(150);
  idle();
  hip1.write(30);
  hip4.write(100);
  idle();
  knee11.write(170);
  // lift rear left knee, move rear left hip forward and front right hip backward, lower rear left knee
  knee31.write(150);
  idle();
  hip3.write(90);
  hip1.write(120);
  idle();
  knee31.write(170);
  // lift front left knee, move front left hip forward and rear left hip backward, lower front left knee
  knee21.write(40);
  idle();
  hip2.write(90);
  hip3.write(60);
  idle();
  knee21.write(20);
  // lift rear right knee, move rear right hip forward and front left hip backward, lower rear right knee
  knee41.write(40);
  idle();
  hip4.write(30);
  hip2.write(80);
  idle();
  knee41.write(20);
  idle();
}
/////////////////////////////////////
void backward()
{
  // lift front right knee, move front right hip backward and rear right hip forward, lower front right knee
  knee11.write(150);
  idle();
  hip1.write(100);
  hip4.write(50);
  idle();
  knee11.write(170);
  // lift rear left knee, move rear left hip backward and front right hip forward, lower rear left knee
  knee31.write(150);
  idle();
  hip3.write(60);
  hip1.write(45);
  idle();
  knee31.write(170);
  // lift front left knee, move front left hip backward and rear left hip forward, lower front left knee
  knee21.write(40);
  idle();
  hip2.write(70);
  hip3.write(120);
  idle();
  knee21.write(20);
  // lift rear right knee, move rear right hip backward and front left hip forward, lower rear right knee
  knee41.write(40);
  idle();
  hip4.write(110);
  hip2.write(110);
  idle();
  knee41.write(20);
  idle();
}
/////////////////////////////////////
void laydown() // lay down
{
  hip1.write(70);
  hip2.write(80);
  for (down = 170; down > 90; down = down - 1) {
    knee11.write(down);
    down2 = 190 - down;
    knee21.write(down2);
    delay(15);
  }
  delay(1000);
  hip3.write(80);
  hip4.write(70);
  for (down = 170; down > 90; down = down - 1) {
    knee31.write(down);
    down2 = 190 - down;
    knee41.write(down2);
    delay(15);
  }
}
/////////////////////////////////////
void gym()
{
  int y;
  hip1.write(70);
  knee31.write(130);
  delay(200);
  knee21.write(40);
  hip2.write(110);
  knee21.write(20);
  delay(20);
  knee11.write(60);
  delay(20);
  hip3.write(120);
  delay(20);
  hip4.write(70);
  knee41.write(20);
  delay(20);
}
/////////////////////////////////////
void wink()
{
  for (b = 0; b < 3; b++) {
    for (w = 60; w < 20; w = w - 1)
    {
      knee11.write(w);
      delay(10);
    }
    for (w = 20; w < 60; w++)
    {
      knee11.write(w);
      delay(10);
    }
    delay(200);
  }
}

////////////////////////////////////
void small_stop() 
{
  sleep();
  delay(5000);
}
  
void loop()
{

int state = digitalRead(sensor);

if (Serial.available() > 0) {
    char value = Serial.read();
    Serial.println(value);
    
    if (value == 'U') {
      forward();
    } 
    else if (value == 'D') {
      backward();
    } 
    else if (value == 'S') {
      sleep();
    }
    else if(value == 'L'){
      rightturn();
    }
    else if(value == 'R'){
      leftturn();
    }
    else if(value == '1'){
      gym();

    }
    else if(value == '2'){
      laydown();

    }
    else if(value == '3') {
      standup();

    }
    else if(value == '4') {
      small_stop();

    }
    else if(value == '5') {
      wink();

    }
    else if(value == '6') {
      test();
      
    }
    else if(distance <= 8) {
      backward();
      
  }
   else if(state == LOW) {
    forward();
   }
}
}
