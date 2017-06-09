
 #include <LiquidCrystal.h>
 LiquidCrystal lcd(12, 11, 9, 8, 7, 6);

  byte wall[8] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
};

  byte character[8] = {
  B01110,
  B01110,
  B00100,
  B01110,
  B00100,
  B00100,
  B01010,
};

  byte flag[8] = {
  B11111,
  B10101,
  B11011,
  B10101,
  B11111,
  B10000,
  B10000,  
};

 const int upButton = 2;
 const int downButton = 3;
 const int leftButton = 4;
 const int rightButton = 5;

 int upState = 0;
 int downState = 0;
 int leftState = 0;
 int rightState = 0;
  int row =6;
  int col = 16;
  
 int maze[6][16] = {
  { 1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
  { 1,0,1,0,0,0,1,1,0,1,1,0,1,1,1,1 },
  { 1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1 },
  { 1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1 },
  { 1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1 },
  { 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1 },
  };  

  int pinLocation;
class player{
  private:

  public:
      int ycoordinate= 5;
      int xcoordinate = 8;
      int xFinish = 1;
      int yFinish = 0;

  void move(int direction);
  }; 


void player::move(int direction){
  if(direction == 0 && maze[ycoordinate-1][xcoordinate] != 1 && ycoordinate-1!= -1) {
   
        ycoordinate = ycoordinate-1;  
    }
  else if(direction == 1 && ycoordinate+1 != row && maze[ycoordinate+1][xcoordinate] != 1) {
      ycoordinate = ycoordinate+1;
    }
  else if(direction== 3 && xcoordinate+1 != col && maze[ycoordinate][xcoordinate+1] != 1 ) {
      Serial.print(maze[ycoordinate][xcoordinate+1]);
      xcoordinate = xcoordinate+1;
    }
  else if (direction== 2 && xcoordinate-1 != -1 && maze[ycoordinate][xcoordinate-1] != 1 ) {   
    xcoordinate = xcoordinate-1;
  } else {
    xcoordinate=xcoordinate;
    ycoordinate=ycoordinate;   
  }
} 
player* p = new player();

void win(){
  lcd.clear();
  lcd.begin(16,2);
  lcd.print("You win!");
  }

void setup() {
  
Serial.begin(9600); 
lcd.begin(16,2);

pinMode(upButton, INPUT);
pinMode(downButton, INPUT);
pinMode(leftButton, INPUT);
pinMode(rightButton, INPUT);

lcd.createChar(0, wall);
lcd.createChar(1, character);
lcd.createChar(2, flag);


}

void loop() {

 upState = digitalRead(upButton);
 downState = digitalRead(downButton);
 leftState = digitalRead(leftButton);
 rightState = digitalRead(rightButton);
 pinLocation=0;

 Serial.println(p->xcoordinate);
 Serial.println(p->ycoordinate);


 
    for(int i = p->ycoordinate-1; i<p->ycoordinate+1; i++) {
      for(int j = 0; j<16; j++) {
        lcd.setCursor(j,pinLocation);
        if(p->xcoordinate == p->xFinish && p->ycoordinate == p->yFinish) {
          lcd.clear();
          lcd.print("    YOU WIN!    ");
          }else if(i == p->ycoordinate && j == p->xcoordinate) {
          lcd.write(byte(1));  
        }
        else if(maze[i][j] == 1){
          lcd.write(byte(0));
        } else if(maze[i][j] == 3){
          lcd.write(byte(2)); 
         } else {
        lcd.print(" ");
        }  
        }
  pinLocation=pinLocation+1;
    }
  if(upState == HIGH) {
    Serial.print("UP");
    p->move(0);
  } else if(downState == HIGH) {
    Serial.print("DOWN"); 
    lcd.print("DOWN");
    p->move(1);
  } else if (leftState == HIGH) {
    Serial.print("LEFT"); 
    lcd.print("LEFT");
    p->move(3);
   } else if (rightState == HIGH) {
    Serial.print("RIGHT");
    lcd.print("RIGHT");
    p->move(2);
   } else {

   }
  delay(100);
}



