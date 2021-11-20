// includes
#include <Servo.h>
#include <SPI.h>
#include <SD.h>

// Pin Config
// front drive (6,9) front Servo (3);
// rear drive (10,11) rear servo (5);
// SD MOSI(8),MISO(12),CLK(13),CS(4);

// objects
Servo SFront;// create servo object to control a servo
Servo SRear;// twelve servo objects can be created on most boards

// variables
int posF = 0;// variable to store the servo position    
int posR = 0;

int drvF = 0;// variable to store drive speed posision
int drvR = 0;

// constants
const int ChipSelect = 4;// CS pin for SD card

void setup() 
{
  // put your setup code here, to run once:
  pinMode(1,0);
  pinMode(2,0);
  pinMode(3,OUTPUT);
  pinMode(ChipSelect,OUTPUT);
  pinMode(5,0);
  pinMode(6,OUTPUT);
  pinMode(7,0);
  pinMode(8,0);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,0);
  pinMode(13,0);
 
  Serial.begin(9600);// Open serial communications and wait for port to open:
  while (!Serial) {
    ;// wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.print("Initializing SD card...");

  if (!SD.begin(ChipSelect)) {
    Serial.println("initialization failed! or... card not present");
    return;
  }
  Serial.println("initialization done.");
  
  
  
  SFront.attach(3);
  SRear.attach(5);
  //revirse
  digitalWrite(9, HIGH); //drive forward front
  digitalWrite(6, LOW);
  digitalWrite(11, HIGH); //drive forward rear
  digitalWrite(10, LOW);
  //forward
  digitalWrite(6, HIGH); //drive forward front
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH); //drive forward rear
  digitalWrite(11, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
