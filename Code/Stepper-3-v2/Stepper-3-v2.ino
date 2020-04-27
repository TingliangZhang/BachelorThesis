// http://www.airspayce.com/mikem/arduino/AccelStepper/
#include <AccelStepper.h>
#include <math.h>

// D6-D12 PWM Pin
// D6 : the Step input to the driver. Low to high transition means to step  
// D7 : the Direction input the driver. High means forward.
AccelStepper stepper1(AccelStepper::DRIVER, 6, 7);
AccelStepper stepper2(AccelStepper::DRIVER, 8, 9);
AccelStepper stepper3(AccelStepper::DRIVER, 10, 11);
//stepper1,2,3 locate at Bottom,Top-Right,Top-Left separately
const double Vdefalut = 500,
	Adefalut = 100,//acceleration
  	Radius = 500;

// Unit : Step or Step per second
// If one step is 1.8 degree, one round is 360/1.8 = 200 step. 
void setMotorSpeed(double Vstepper1, double Vstepper2, double Vstepper3){
  	//assume anticlockwise is positive in the perspective which is above the car
	//hence clockwise is positive for each motor
	stepper1.setMaxSpeed(Vstepper1);
	stepper1.setAcceleration(10*Vstepper1);
	stepper2.setMaxSpeed(Vstepper2);
	stepper2.setAcceleration(10*Vstepper2);
	stepper3.setMaxSpeed(Vstepper3);
	stepper3.setAcceleration(10*Vstepper3);
}

void setMotorTarget(double x, double y, double omega, double V = Vdefalut, double theta = 0){
    //assume anticlockwise is positive in the perspective which is above the car
	//hence clockwise is positive for each motor
	//omega is anticlockwise-positive, theta is anticlockwise-positive
	// if(x < 1e-5 && y < 1e-5 && omega < 1e-5)return;
	double t = sqrt(x*x + y*y + omega*omega)/V;
	double tmp_x = cos(theta)*x + sin(theta)*y,
			tmp_y = -sin(theta)*x + cos(theta)*y;
	double Sstepper1 =      tmp_x +                     Radius*omega;
	double Sstepper2 = -0.5*tmp_x + sqrt(3)/2.0*tmp_y + Radius*omega;
	double Sstepper3 = -0.5*tmp_x - sqrt(3)/2.0*tmp_y + Radius*omega;
	setMotorSpeed(fabs(Sstepper1/t), fabs(Sstepper2/t), fabs(Sstepper3/t));
	stepper1.move(long(Sstepper1));
	stepper2.move(long(Sstepper2));
	stepper3.move(long(Sstepper3));
}

void setup() {
  // put your setup code here, to run once:
    stepper1.setMaxSpeed(1000.0);
    stepper1.setAcceleration(1000.0);
    stepper1.moveTo(1000);
    

	
    stepper2.setMaxSpeed(500.0);
    stepper2.setAcceleration(500.0);
    stepper2.moveTo(-500);
    
    stepper3.setMaxSpeed(500.0);
    stepper3.setAcceleration(500.0);
    stepper3.moveTo(-500); 
	// setMotorTarget(1000,0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
	if(stepper1.currentPosition() == 0){
		setMotorTarget(1000,0,0);
	}else if(stepper1.currentPosition() == 1000){
		setMotorTarget(-1000,0,0);
	}
	
    stepper1.run();
    stepper2.run();
    stepper3.run();
}
