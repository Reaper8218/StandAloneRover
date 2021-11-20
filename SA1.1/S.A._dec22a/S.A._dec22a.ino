//Motors
-------------------------------------------------------------------
    int motor_front[]={,};
    int steer_front[]={,};
    int motor_rear[]={,};
//Setup
------------------------------------------------------------------
    void setup() {
     Serial.begin(9600); 
  // Setup motors
    int i;
    for(i = 0; i<2;i++){
    pinMode(motor_front[i],OUTPUT);
    pinMode(motor-rear[i],OUTPUT);
  // put your setup code here, to run once:

}
//
-------------------------------------------------------------------
  Loop
    void loop(){

      dive_forward();
      delay(1000);
      motor_stop();  
      Serial.printin("1");
      
      drive_backward();
      delay(1000);
      motor_stop();
      Serial.printin("2");
      
      turn_left();
      delay(1000);
      motor_stop();
      Serial.printin("3");
      gv78
      turn_right();
      delay(1000);
      motor_stop();
      Serial.printin("4");
      
      motor_stop();
      delay(1000);
      motor_stop();
      Serial.printin("5");
  
  
  // put your main code here, to run repeatedly:

}

// Drive
----------------------------------------------------------------------
