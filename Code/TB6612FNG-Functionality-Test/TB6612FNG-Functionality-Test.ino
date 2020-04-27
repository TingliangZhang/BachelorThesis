// TB6612FNG-Functionality-Test BY TINA ZHANG
// CC NC-BY 4.0
                        //define the two direction logic pins and the speed / PWMA and PWMB pin
const int PWMA = 6;     // Motor (A)
const int AIN1 = 22;
const int AIN2 = 23;
                        // Motor (B)
const int PWMB = 7;
const int BIN1 = 24;
const int BIN2 = 25;

                        // Motor (C)
const int PWMC = 8;
const int CIN1 = 26;
const int CIN2 = 27;

                        // Motor (D)
const int PWMD = 9;
const int DIN1 = 28;
const int DIN2 = 29;

const int STBY = 39;

void setup()
{
                        // Motor A : set all pins as output
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

                        // Motor B : set all pins as output
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
}

void loop()
{
  digitalWrite(STBY, HIGH);
                        //drive forward at full speed by pulling AIN1/BIN1 High
                        //and AIN2/BIN2 low, while writing a full 255 to PWMA/PWMB to
                        //control speed
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 255);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 255);

  digitalWrite(CIN1, HIGH);
  digitalWrite(CIN2, LOW);
  analogWrite(PWMC, 255);  

  digitalWrite(DIN1, HIGH);
  digitalWrite(DIN2, LOW);
  analogWrite(PWMD, 255);
                        //wait 1 second
  delay(1000);

                        //Brake the motorS by pulling both direction pins to
                        //the same state (in this case LOW). PWMA/PWMB doesn't matter
                        //in a brake situation, but set as 0.
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0);
  digitalWrite(CIN1, LOW);
  digitalWrite(CIN2, LOW);
  analogWrite(PWMC, 0);
  digitalWrite(DIN1, LOW);
  digitalWrite(DIN2, LOW);
  analogWrite(PWMD, 0);
                        //wait 1 second
  delay(1000);

                        //change direction to reverse by flipping the states
                        //of the direction pins from their forward state at lower speed
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 150);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 150);
  digitalWrite(CIN1, LOW);
  digitalWrite(CIN2, HIGH);
  analogWrite(PWMC, 150);
  digitalWrite(DIN1, LOW);
  digitalWrite(DIN2, HIGH);
  analogWrite(PWMD, 150);
                        //wait 1 second
  delay(1000);

                        //Brake again
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0);
  digitalWrite(CIN1, LOW);
  digitalWrite(CIN2, LOW);
  analogWrite(PWMC, 0);
  digitalWrite(DIN1, LOW);
  digitalWrite(DIN2, LOW);
  analogWrite(PWMD, 0);
                        //wait 1 second
  delay(1000);
}
