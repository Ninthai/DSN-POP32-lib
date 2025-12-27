#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้


void Run1();
void Run2();
void Run3();

void setup(){
    beep();
    POP32_INIT();
    servo(servoPIN,startAngle);
    delay(500);
    servo(servoPIN,-1);
    imu.Start();
    BasicMenu.buttons[0].callback = Run1; // Run 1
    BasicMenu.buttons[1].callback = Run2; // Run 2
    BasicMenu.buttons[2].callback = Run3; // Run 3
    Front.__Track = 750;
    Back.__Track = 750;
    motors.setSpeedRange(96,250);
    motors.setRatio({1,1.3},{1.0,1.0});
}   

void loop(){
    BasicMenu.show();
}

void Run1()
{
    imu.Start();
    beep();
    forwardTill(100,0,1,1);  
    forwardTill(100,1,0,0);   
    forwardAlign(80,3);
    backwardTime(80,250,1,0);
    rotate(-90);

    forwardTill(100,1);
    forwardAlign(80,3);
    backwardTime(80,250,0,0);
    rotate(90);

    forwardTill(100,1);
    forwardAlign(100,2);
    backwardTime(80,250,0,0);
    rotate(90);

    forwardTill(100,1,1,0); 
    Poy();
    backwardTill(100,1,0,0);
    backwardAlign(80 , 2);
    rotate(90);

    forwardTill(100,1,1,0); 
    forwardAlign(80,2);
    backwardTime(80,250,0,0);
    rotate(-90);

    forwardTime(100 , 500 , 1 , 0);

}

void Run2(){
    toggleServoOn();
    delay(1000);
    toggleServoOff();

}

void Run3(){
    forwardAlign(60,3);

}

void Poy()
{
    toggleServoOn();
    delay(300);
    toggleServoOff();
}