
/*
Pin assignments are:
3.3V output to PS2 red pin
5V output to 1Kohm pull up resistors for PS2.
Pin D02 to PS2 brown pin (data)
Pin D02 to PS2 yellow pin (attention)
Pin D08 to PS2 orange pin (command)
Pin D13 to PS2 blue pin (clock)
Pin D06 to Signal Pin
Pin D07 to Signal pin
Pin D08 to MotorEN1 Signal pin
Pin D09 to MotorEN2 Signal pin
Pin D04 to LED Transistor Base
*/

#include <Servo.h> //For driving the ESCs and Servos
#include <PS2X_lib.h> // Bill Porter's PS2 Library
PS2X ps2x; //The PS2 Controller Class
Servo M_EN1; //Create servo object representing Motor Enable 1
Servo M_EN2; //Create servo object representing Motor Enable 2
const int LEDpin = 13; //green LED is on Digital pin 4
const int M1PA = 0;
const int M1PB = 0;
const int M2PA = 0;
const int M2PB = 0;
volatile boolean LEDHdlts; //LED headlights on/off toggle
volatile boolean PSX2SM; // PS2 controller Small motor on/off toggle
int PlyStnRStickUpDn = 0; //Value read off the PS2 Right Stick up/down.
int PlyStnRStickLtRt = 0; //Value read off the PS2 Right Stick left/right
int PlyStnLStickUpDn = 0; //Value read off the PS2 Left Stick up/down
int PlyStnLStickLtRt = 0; // Value read off the PS2 Left Stick left/right
int M_EN1Set1 = 0; //Setting for the Motor Enable 1
int M_EN2Set1 = 0; //Setting for the Motor Enable 2
int M_EN1Set2 = 0; //Setting for the Motor Enable 1
int M_EN2Set2 = 0; //Setting for the Motor Enable 2
int PSX2LM = 0; //Setting for PS2 Large Motor

void setup() 
{
Serial.begin(9600);
  
// put your setup code here, to run once:
ps2x.config_gamepad(13,8,2,12, true, false);
//setup pins and settings: GamePad(clock, command, attention, data, Pressures, Rumble)
pinMode(LEDpin, OUTPUT); //Sets the LEDpin to output
LEDHdlts = false; //Sets the Headlights to off
PSX2SM = false; //Sets the PS2 Small Motor to off for start-up
PSX2LM = 0; //Sets the PS Large Motor to zero for start-up
M_EN1.attach(10);// attaches the Motor Enable 1 to pin 8
M_EN2.attach(9);// attaches the Motor Enable 2 to pin 9

M_EN1.write(0);
M_EN2.write(0);
delay(5000); //Five second delay

}

void Left()
{
  digitalWrite(M1PA,HIGH);
  digitalWrite(M1PB,LOW);
  analogWrite(10,M_EN1Set2); //Pulse the EN pin on the LM293
  }
  
void Right()
{
  digitalWrite(M1PA,LOW);
  digitalWrite(M1PB,HIGH);
  analogWrite(10,M_EN1Set2); //Pulse the EN pin on the LM293
  }

void center()
{
  digitalWrite(M1PA,LOW);
  digitalWrite(M1PB,LOW);
  analogWrite(10,M_EN1Set2); //Pulse the EN pin on the LM293
  }

void Forward()
{
  digitalWrite(M2PA,HIGH);
  digitalWrite(M2PB,LOW);
  analogWrite(9,M_EN2Set2); //Pulse the EN pin on the LM293
  }
  
void Reverse()
{
  digitalWrite(M2PA,LOW);
  digitalWrite(M2PB,HIGH);
  analogWrite(9,M_EN2Set2); //Pulse the EN pin on the LM293
  }

void Stop()
{
  digitalWrite(M2PA,LOW);
  digitalWrite(M2PB,LOW);
  analogWrite(9,M_EN2Set2); //Pulse the EN pin on the LM293
  }

void loop() 
{
  // put your main code here, to run repeatedly:
ps2x.read_gamepad(PSX2SM,PSX2LM); //This needs to be called at least once a second
// to get data from the controller.
if(ps2x.ButtonPressed(PSB_GREEN)) //Triangle pressed
{
LEDHdlts = !LEDHdlts; //Toggle the LED light flag
}
//Analogue Stick readings
PlyStnRStickUpDn = ps2x.Analog(PSS_RY); //Right Stick Up and Down
PlyStnRStickLtRt = ps2x.Analog(PSS_RX); //Right Stick Left and Right
PlyStnLStickUpDn = ps2x.Analog(PSS_LY); //left Stick Up and Down
PlyStnLStickLtRt = ps2x.Analog(PSS_LX); //Left Stick Left and Right
//Readings from PS2 Controller Sticks are from 0 to 255
//with the neutral being 128. The zero positions are to
//the left for X-axis movements and up for Y-axis movements.
//Variables to carry the settings for the ESCs and Servos
//The values from the PS2 Sticks are mapped to 0 to 180 degrees
M_EN1Set1 = map(PlyStnRStickUpDn,-255,255,0,255);
M_EN2Set1 = map(PlyStnRStickLtRt,-255,255,0,255);

M_EN1.write(M_EN1Set2);
M_EN2.write(M_EN2Set2);
digitalWrite(LEDpin,LEDHdlts); //Light the LED based on headlights status flag
delay(15);
}
