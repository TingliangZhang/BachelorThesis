#include <XBee.h>

/*
https://github.com/andrewrapp/xbee-arduino/blob/wiki/DevelopersGuide.md
This example is for Series 2 XBee
Receives a ZB RX packet and sets a PWM value based on packet data.
Error led is flashed if an unexpected packet is received
*/

XBee xbee = XBee();
XBeeResponse response = XBeeResponse();
// create reusable response objects for responses we expect to handle 
ZBRxResponse rx = ZBRxResponse();
ModemStatusResponse msr = ModemStatusResponse();


/*Example sketch to control a stepper motor with A4988/DRV8825 stepper motor driver and Arduino without a library. More info: https://www.makerguides.com */

// Using DRV8825
// D6-D12 PWM Pin
// D6 : the Step input to the driver. Low to high transition means to step  
// D7 : the Direction input the driver. High means forward.

// Unit : Step or Step per second
// If one step is 1.8 degree, one round is 360/1.8 = 200 step. 


// Define stepper motor connections and steps per revolution:

#define stepPin1 6
#define dirPin1 7
#define stepPin2 8
#define dirPin2 9
#define stepPin3 10
#define dirPin3 11

// Clock Error
#define TimeScale 16

#define stepsPerRevolution 200

int statusLed = 13;
int errorLed = 13;
int dataLed = 13;

void flashLed(int pin, int times, int wait) {
    
    for (int i = 0; i < times; i++) {
      digitalWrite(pin, HIGH);
      delay(wait);
      digitalWrite(pin, LOW);
      
      if (i + 1 < times) {
        delay(wait);
      }
    }
}

float speedabs = 0;
float stepsabs = 0;
float MicrosecondsDelay = 0;

//float SetSpeed(int dirPin, int stepPin, float stepperspeed)
//{
//  if (stepperspeed >= 0)
//  {
//    // Set the spinning direction clockwise:
//    digitalWrite(dirPin, HIGH);
//    speedabs = stepperspeed;
//  }
//  else
//  {
//    // Set the spinning direction clockwise:
//    digitalWrite(dirPin, LOW);
//    speedabs = - stepperspeed;   
//  }
//  return speedabs;
//}

float Speedabs(int dirPin, int stepPin, float stepperspeed)
{
  if (stepperspeed >= 0)
  {
    // Set the spinning direction clockwise:
    digitalWrite(dirPin, HIGH);
    speedabs = stepperspeed;
  }
  else
  {
    // Set the spinning direction clockwise:
    digitalWrite(dirPin, LOW);
    speedabs = - stepperspeed;   
  }
  return speedabs;
}

void Forward(int steps)
{
  if (steps >= 0)
  {
    // Set the spinning direction clockwise:
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    stepsabs = steps;
  }
  else
  {
    // Set the spinning direction clockwise:
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    stepsabs = - steps;   
  }
  //Spin the stepper motor steps revolutions fast:
  for (int i = 0; i < stepsabs * stepsPerRevolution; i++) 
  {
    // These four lines result in 1 step:
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
//    digitalWrite(stepPin3, HIGH);
    delayMicroseconds(500/TimeScale);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
//    digitalWrite(stepPin3, LOW);
    delayMicroseconds(500/TimeScale);
  }
  
}

void Run()
{
  //Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) 
  {
    // These four lines result in 1 step:
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    digitalWrite(stepPin3, HIGH);
    delayMicroseconds(500/TimeScale);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    digitalWrite(stepPin3, LOW);
    delayMicroseconds(500/TimeScale);
  }
}

void Stop(){
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(stepPin3, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  digitalWrite(dirPin3, LOW);
}

void XBeeRX() {
  // Put in loop
  // continuously reads packets, looking for ZB Receive or Modem Status
  xbee.readPacket();
  
  if (xbee.getResponse().isAvailable()) {
    // got something
    
    if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
      // got a zb rx packet
      
      // now fill our zb rx class
      xbee.getResponse().getZBRxResponse(rx);

      Forward(rx.getData());
          
//      if (rx.getOption() == ZB_PACKET_ACKNOWLEDGED) {
//          // the sender got an ACK
//          flashLed(statusLed, 10, 10);
//      } else {
//          // we got it (obviously) but sender didn't get an ACK
//          flashLed(errorLed, 2, 20);
//      }
//      // set dataLed PWM to value of the first byte in the data
//      analogWrite(dataLed, rx.getData(0));
    } else if (xbee.getResponse().getApiId() == MODEM_STATUS_RESPONSE) {
      xbee.getResponse().getModemStatusResponse(msr);
      // the local XBee sends this response on certain events, like association/dissociation
      
      if (msr.getStatus() == ASSOCIATED) {
        // yay this is great.  flash led
        flashLed(statusLed, 10, 10);
      } else if (msr.getStatus() == DISASSOCIATED) {
        // this is awful.. flash led to show our discontent
        flashLed(errorLed, 10, 10);
      } else {
        // another status
        flashLed(statusLed, 5, 10);
      }
    } else {
      // not something we were expecting
      flashLed(errorLed, 1, 25);    
    }
  } else if (xbee.getResponse().isError()) {
    //nss.print("Error reading packet.  Error code: ");  
    //nss.println(xbee.getResponse().getErrorCode());
  }
}

void DelayCorrected(float s){
  delay(s/16);
}

void ForwardUnits(float u){
  Forward(u/6);
}

void ForwardDelay(float u){
  ForwardUnits(u);
  DelayCorrected(3000-abs(u)*33.33);
}

void setup() {
  pinMode(statusLed, OUTPUT);
  pinMode(errorLed, OUTPUT);
  pinMode(dataLed,  OUTPUT);
  
  // Declare pins as output:
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(dirPin3, OUTPUT);

//  // start serial TX1 RX1
//  Serial1.begin(9600);
//  xbee.begin(Serial1);

//  // No.1
//  DelayCorrected(5000);
//  ForwardDelay(0);
//  ForwardDelay(15);
//  ForwardDelay(15);
//  ForwardDelay(0);
//  ForwardDelay(0);
//  ForwardDelay(0);
//  ForwardDelay(11);
//
//  // No.2
//  DelayCorrected(5000);
//  ForwardDelay(30);
//  ForwardDelay(15);
//  ForwardDelay(-8);
//  ForwardDelay(-8);
//  ForwardDelay(0);
//  ForwardDelay(10);
//  ForwardDelay(1);
//
//  // No.3
//  DelayCorrected(5000);
//  ForwardDelay(60);
//  ForwardDelay(-30);
//  ForwardDelay(-8);
//  ForwardDelay(8);
//  ForwardDelay(20);
//  ForwardDelay(-3);
//  ForwardDelay(-6);
//
//  // No.4
//  // 注意把1号电机改为3号
//  DelayCorrected(5000);
//  ForwardDelay(0);
//  ForwardDelay(0);
//  ForwardDelay(0);
//  ForwardDelay(0);
//  ForwardDelay(-30);
//  ForwardDelay(-15);
//  ForwardDelay(-4);
  
//  ForwardUnits(0);
//  DelayCorrected(3000);
//  ForwardUnits(15);
//  DelayCorrected(2500);
//  ForwardUnits(15);
//  DelayCorrected(2500);
//  ForwardUnits(0);
//  DelayCorrected(3000);
//  ForwardUnits(0); 
//  DelayCorrected(3000);
//  ForwardUnits(0);
//  DelayCorrected(3000);
//  ForwardUnits(11);

  Stop();  
}

void loop() {
//  SetSpeed(dirPin1, stepPin1, 100);
//  SetSpeed(dirPin2, stepPin2, 100);
//  SetSpeed(dirPin3, stepPin3, 100);

  // 电机测试
  Run();

}
