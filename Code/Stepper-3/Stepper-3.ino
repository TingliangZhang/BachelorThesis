// http://www.airspayce.com/mikem/arduino/AccelStepper/
#include <AccelStepper.h>

// D6-D12 PWM Pin
// D6 : the Step input to the driver. Low to high transition means to step  
// D7 : the Direction input the driver. High means forward.
AccelStepper stepper1(AccelStepper::DRIVER, 6, 7);
AccelStepper stepper2(AccelStepper::DRIVER, 8, 9);
AccelStepper stepper3(AccelStepper::DRIVER, 10, 11);

// Unit : Step or Step per second
// If one step is 1.8 degree, one round is 360/1.8 = 200 step. 

void setup() {
  // put your setup code here, to run once:
    stepper1.setMaxSpeed(1200.0);
    stepper1.setAcceleration(300.0);
    stepper1.moveTo(1000000);
    
    stepper2.setMaxSpeed(1200.0);
    stepper2.setAcceleration(300.0);
    stepper2.moveTo(1000000);
    
    stepper3.setMaxSpeed(1200.0);
    stepper3.setAcceleration(300.0);
    stepper3.moveTo(1000000); 
}

void loop() {
  // put your main code here, to run repeatedly:
    stepper1.run();
    stepper2.run();
    stepper3.run();
}
