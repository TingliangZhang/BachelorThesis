// http://www.airspayce.com/mikem/arduino/AccelStepper/
#include <AccelStepper.h>

// D6-D12 PWM Pin
// D6 : the Step input to the driver. Low to high transition means to step  
// D7 : the Direction input the driver. High means forward.
AccelStepper stepper1(AccelStepper::DRIVER, 6, 7);
AccelStepper stepper2(AccelStepper::DRIVER, 8, 9);
AccelStepper stepper3(AccelStepper::DRIVER, 10, 11);

float MaxSpeed = 1200.0;
float Acceleration = 300.0;
float Distance = 10000;

// Unit : Step or Step per second
// If one step is 1.8 degree, one round is 360/1.8 = 200 step. 

void setup() {
  // put your setup code here, to run once:
    stepper1.setMaxSpeed(MaxSpeed);
    stepper1.setAcceleration(Acceleration);
//    stepper1.moveTo(Distance);

    stepper2.setMaxSpeed(MaxSpeed);
    stepper2.setAcceleration(Acceleration);
    stepper2.moveTo(-Distance);
    
    stepper3.setMaxSpeed(MaxSpeed);
    stepper3.setAcceleration(Acceleration);
    stepper3.moveTo(Distance); 

    delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
    stepper1.run();
    stepper2.run();
    stepper3.run();
}
