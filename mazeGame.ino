 const int upButton = 2;
 const int downButton = 3;
 const int leftButton = 4;
 const int rightButton = 5;

 int upState = 0;
 int downState = 0;
 int leftState = 0;
 int rightState = 0;
 
void setup() {
Serial.begin(9600); 
pinMode(upButton, INPUT);
pinMode(downButton, INPUT);
pinMode(leftButton, INPUT);
pinMode(rightButton, INPUT);


}

void loop() {

 upState = digitalRead(upButton);
 downState = digitalRead(downButton);
 leftState = digitalRead(leftButton);
 rightState = digitalRead(rightButton);
  if(upState == HIGH) {
    Serial.print("UP"); 
  } else if(downState == HIGH) {
    Serial.print("DOWN"); 
  } else if (leftState == HIGH) {
    Serial.print("LEFT"); 
   } else if (rightState == HIGH) {
    Serial.print("RIGHT");
   }
  delay(250);
}



