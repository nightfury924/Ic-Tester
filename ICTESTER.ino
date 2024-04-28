#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,4);
#define PIN1 19
#define PIN2 18
#define PIN3 5
#define PIN4 17
#define PIN5 16
#define PIN6 4
#define PIN7 14
#define PIN8 27
#define PIN9 26
#define PIN10 25
#define PIN11 33
#define PIN12 32
#define LED1 2
#define LED2 15
#define BUTTON1 35
#define BUTTON2 34
int pins[] = {PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7, PIN8, PIN9, PIN10, PIN11, PIN12};
int icMode = 0;
int andGate[] = {0,0,0,1};
int nandGate[] = {1,1,1,0};
int orGate[] = {0, 1, 1, 1};
int norGate[] = {1, 0, 0, 0};
int xorGate[] = {0, 1, 1, 0};
int xnorGate[] = {1, 0, 0, 1};
int notGate[] = {1, 0};
char ics[][13] = {
  "74_08 AND",
  "74_00 NAND",
  "74_32 OR",
  "74_02 NOR",
  "74_86 XOR",
  "74_266 XNOR",
  "74_04 NOT"
};

void lcdPrint(char ic[13]){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print(ic);
  lcd.setCursor(0,3);
  lcd.print("  Next      Test  ");
}


void lcdPrintPass(){
  lcd.setCursor(3,2);
  lcd.print("IC Passed");
}

bool test3PinGate(int p1, int p2 , int out, int expected,int i1, int i2){
  digitalWrite(p1,i1);
  digitalWrite(p2,i2);
  delay(3);
  if(digitalRead(out) == expected){
    return true;
  }
  return false;
}
bool test2PinGate(int p1, int out, int expected,int i1){
  digitalWrite(p1,i1);
  delay(3);
  if(digitalRead(out) == expected){
    return true;
  }
  return false;
}

void twoInputOneOutputIC(){
  for (int i = 0; i < 12; i++) {
    if ((i+1) % 3 == 0) { 
      pinMode(pins[i], INPUT);
    } else {
      pinMode(pins[i], OUTPUT);
    }
  }
  icMode = 1;
}

void oneOutputTwoInputIC(){
  for (int i = 0; i < 12; i++) {
    if (i % 3 == 0) { 
      pinMode(pins[i], INPUT);
    } else { 
      pinMode(pins[i], OUTPUT);
    }
  }
  icMode = 2;
}

void oneInputoneOutput(){
  for (int i = 0; i < 12; i++) {
    if ((i+1) % 2 == 0) { // Every third pin is an output
      pinMode(pins[i], OUTPUT);
    } else { // All other pins are inputs
      pinMode(pins[i], INPUT);
    }
  }
  icMode = 3;
}

bool testAndIc(){
  if(icMode != 1){
    twoInputOneOutputIC();
  }
  if(test3PinGate(PIN1,PIN2,PIN3,andGate[0],0,0) && test3PinGate(PIN4,PIN5,PIN6,andGate[0],0,0) && test3PinGate(PIN7,PIN8,PIN9,andGate[0],0,0) && test3PinGate(PIN10,PIN11,PIN12,andGate[0],0,0)){
    if(test3PinGate(PIN1,PIN2,PIN3,andGate[1],0,1) && test3PinGate(PIN4,PIN5,PIN6,andGate[1],0,1) && test3PinGate(PIN7,PIN8,PIN9,andGate[1],0,1) && test3PinGate(PIN10,PIN11,PIN12,andGate[1],0,1)){
      if(test3PinGate(PIN1,PIN2,PIN3,andGate[2],1,0) && test3PinGate(PIN4,PIN5,PIN6,andGate[2],1,0) && test3PinGate(PIN7,PIN8,PIN9,andGate[2],1,0) && test3PinGate(PIN10,PIN11,PIN12,andGate[2],1,0)){
        if(test3PinGate(PIN1,PIN2,PIN3,andGate[3],1,1) && test3PinGate(PIN4,PIN5,PIN6,andGate[3],1,1) && test3PinGate(PIN7,PIN8,PIN9,andGate[3],1,1) && test3PinGate(PIN10,PIN11,PIN12,andGate[3],1,1)){
          return true;
        }
      }
    }
  }
  return false;
}
bool testNandIc(){
  if(icMode != 1){
    twoInputOneOutputIC();
  }
  if(test3PinGate(PIN1,PIN2,PIN3,nandGate[0],0,0) && test3PinGate(PIN4,PIN5,PIN6,nandGate[0],0,0) && test3PinGate(PIN7,PIN8,PIN9,nandGate[0],0,0) && test3PinGate(PIN10,PIN11,PIN12,nandGate[0],0,0)){
    if(test3PinGate(PIN1,PIN2,PIN3,nandGate[1],0,1) && test3PinGate(PIN4,PIN5,PIN6,nandGate[1],0,1) && test3PinGate(PIN7,PIN8,PIN9,nandGate[1],0,1) && test3PinGate(PIN10,PIN11,PIN12,nandGate[1],0,1)){
      if(test3PinGate(PIN1,PIN2,PIN3,nandGate[2],1,0) && test3PinGate(PIN4,PIN5,PIN6,nandGate[2],1,0) && test3PinGate(PIN7,PIN8,PIN9,nandGate[2],1,0) && test3PinGate(PIN10,PIN11,PIN12,nandGate[2],1,0)){
        if(test3PinGate(PIN1,PIN2,PIN3,nandGate[3],1,1) && test3PinGate(PIN4,PIN5,PIN6,nandGate[3],1,1) && test3PinGate(PIN7,PIN8,PIN9,nandGate[3],1,1) && test3PinGate(PIN10,PIN11,PIN12,nandGate[3],1,1)){
          return true;
        }
      }
    }
  }
  return false;
}

bool testOrIc(){
  if(icMode != 1){
    twoInputOneOutputIC();
  }
  if(test3PinGate(PIN1,PIN2,PIN3,orGate[0],0,0) && test3PinGate(PIN4,PIN5,PIN6,orGate[0],0,0) && test3PinGate(PIN7,PIN8,PIN9,orGate[0],0,0) && test3PinGate(PIN10,PIN11,PIN12,orGate[0],0,0)){
    if(test3PinGate(PIN1,PIN2,PIN3,orGate[1],0,1) && test3PinGate(PIN4,PIN5,PIN6,orGate[1],0,1) && test3PinGate(PIN7,PIN8,PIN9,orGate[1],0,1) && test3PinGate(PIN10,PIN11,PIN12,orGate[1],0,1)){
      if(test3PinGate(PIN1,PIN2,PIN3,orGate[2],1,0) && test3PinGate(PIN4,PIN5,PIN6,orGate[2],1,0) && test3PinGate(PIN7,PIN8,PIN9,orGate[2],1,0) && test3PinGate(PIN10,PIN11,PIN12,orGate[2],1,0)){
        if(test3PinGate(PIN1,PIN2,PIN3,orGate[3],1,1) && test3PinGate(PIN4,PIN5,PIN6,orGate[3],1,1) && test3PinGate(PIN7,PIN8,PIN9,orGate[3],1,1) && test3PinGate(PIN10,PIN11,PIN12,orGate[3],1,1)){
          return true;
        }
      }
    }
  }
  return false;
}
bool testNorIc(){
  if(icMode != 2){
    oneOutputTwoInputIC();
  }
  if(test3PinGate(PIN2,PIN3,PIN1,norGate[0],0,0) && test3PinGate(PIN5,PIN6,PIN4,norGate[0],0,0) && test3PinGate(PIN8,PIN9,PIN7,norGate[0],0,0) && test3PinGate(PIN11,PIN12,PIN10,norGate[0],0,0)){
    if(test3PinGate(PIN2,PIN3,PIN1,norGate[1],0,1) && test3PinGate(PIN5,PIN6,PIN4,norGate[1],0,1) && test3PinGate(PIN8,PIN9,PIN7,norGate[1],0,1) && test3PinGate(PIN11,PIN12,PIN10,norGate[1],0,1)){
      if(test3PinGate(PIN2,PIN3,PIN1,norGate[2],1,0) && test3PinGate(PIN5,PIN6,PIN4,norGate[2],1,0) && test3PinGate(PIN8,PIN9,PIN7,norGate[2],1,0) && test3PinGate(PIN11,PIN12,PIN10,norGate[2],1,0)){
        if(test3PinGate(PIN2,PIN3,PIN1,norGate[3],1,1) && test3PinGate(PIN5,PIN6,PIN4,norGate[3],1,1) && test3PinGate(PIN8,PIN9,PIN7,norGate[3],1,1) && test3PinGate(PIN11,PIN12,PIN10,norGate[3],1,1)){
          return true;
        }
      }
    }
  }
  return false;
}
bool testXorIc(){
  if(icMode != 1){
    twoInputOneOutputIC();
  }
  if(test3PinGate(PIN1,PIN2,PIN3,xorGate[0],0,0) && test3PinGate(PIN4,PIN5,PIN6,xorGate[0],0,0) && test3PinGate(PIN7,PIN8,PIN9,xorGate[0],0,0) && test3PinGate(PIN10,PIN11,PIN12,xorGate[0],0,0)){
    if(test3PinGate(PIN1,PIN2,PIN3,xorGate[1],0,1) && test3PinGate(PIN4,PIN5,PIN6,xorGate[1],0,1) && test3PinGate(PIN7,PIN8,PIN9,xorGate[1],0,1) && test3PinGate(PIN10,PIN11,PIN12,xorGate[1],0,1)){
      if(test3PinGate(PIN1,PIN2,PIN3,xorGate[2],1,0) && test3PinGate(PIN4,PIN5,PIN6,xorGate[2],1,0) && test3PinGate(PIN7,PIN8,PIN9,xorGate[2],1,0) && test3PinGate(PIN10,PIN11,PIN12,xorGate[2],1,0)){
        if(test3PinGate(PIN1,PIN2,PIN3,xorGate[3],1,1) && test3PinGate(PIN4,PIN5,PIN6,xorGate[3],1,1) && test3PinGate(PIN7,PIN8,PIN9,xorGate[3],1,1) && test3PinGate(PIN10,PIN11,PIN12,xorGate[3],1,1)){
          return true;
        }
      }
    }
  }
  return false;
}
bool testXnorIc(){
  if(icMode != 1){
    twoInputOneOutputIC();
  }
  if(test3PinGate(PIN1,PIN2,PIN3,xnorGate[0],0,0) && test3PinGate(PIN4,PIN5,PIN6,xnorGate[0],0,0) && test3PinGate(PIN7,PIN8,PIN9,xnorGate[0],0,0) && test3PinGate(PIN10,PIN11,PIN12,xnorGate[0],0,0)){
    if(test3PinGate(PIN1,PIN2,PIN3,xnorGate[1],0,1) && test3PinGate(PIN4,PIN5,PIN6,xnorGate[1],0,1) && test3PinGate(PIN7,PIN8,PIN9,xnorGate[1],0,1) && test3PinGate(PIN10,PIN11,PIN12,xnorGate[1],0,1)){
      if(test3PinGate(PIN1,PIN2,PIN3,xnorGate[2],1,0) && test3PinGate(PIN4,PIN5,PIN6,xnorGate[2],1,0) && test3PinGate(PIN7,PIN8,PIN9,xnorGate[2],1,0) && test3PinGate(PIN10,PIN11,PIN12,xnorGate[2],1,0)){
        if(test3PinGate(PIN1,PIN2,PIN3,xnorGate[3],1,1) && test3PinGate(PIN4,PIN5,PIN6,xnorGate[3],1,1) && test3PinGate(PIN7,PIN8,PIN9,xnorGate[3],1,1) && test3PinGate(PIN10,PIN11,PIN12,xnorGate[3],1,1)){
          return true;
        }
      }
    }
  }
  return false;
}
bool testNotIc(){
  if(icMode != 3){
    oneInputoneOutput();
  }
  if(test2PinGate(PIN1,PIN2,notGate[0],0) && test2PinGate(PIN3,PIN4,notGate[0],0) && test2PinGate(PIN5,PIN6,notGate[0],0) && test2PinGate(PIN7,PIN8,notGate[0],0) && test2PinGate(PIN9,PIN10,notGate[0],0) && test2PinGate(PIN11,PIN12,notGate[0],0) ){
    if(test2PinGate(PIN1,PIN2,notGate[1],1) && test2PinGate(PIN3,PIN4,notGate[1],1) && test2PinGate(PIN5,PIN6,notGate[1],1) && test2PinGate(PIN7,PIN8,notGate[1],1) && test2PinGate(PIN9,PIN11,notGate[1],1) && test2PinGate(PIN11,PIN12,notGate[1],1) ){
      return true;
    }
  }
  return false;
}




void setup() {
  // put your setup code here, to run once:
  
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(BUTTON1,INPUT_PULLUP);
  pinMode(BUTTON2,INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("    WELCOME!    ");
  lcd.setCursor(0, 2);
  lcd.print("  IC Tester V1  ");
  delay(500);
}



void loop() {
  int icIndex = 0;
  lcdPrint(ics[icIndex]);
  while(digitalRead(BUTTON2) == HIGH){
    if(digitalRead(BUTTON1) == LOW){
      icIndex++;
      if(icIndex == 7){
        icIndex = 0;
      }
      lcdPrint(ics[icIndex]);
      delay(25);
    }
  }
  if(icIndex == 0){
    if(testAndIc()){
      lcdPrintPass();
    }
  }
  else if(icIndex == 1){
    testNandIc();
  }
  else if(icIndex == 2){
    testOrIc();
  }
  else if(icIndex == 3){
    testNorIc();
  }
  else if(icIndex == 4){
    testXorIc();
  }
  else if(icIndex == 5){
    testXnorIc();
  }
  else if(icIndex == 6){
    testNotIc();
  }

  delay(1500);
}



