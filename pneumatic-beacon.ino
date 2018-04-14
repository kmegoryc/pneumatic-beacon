#include <Wire.h>
#include <PneuDuino.h>

PneuDuino air = PneuDuino();

//rgb pressure
int rPressure, gPressure, bPressure;

//rgb values
int r, g, b;

//rgb 
int rInput = 6;
int gInput = 7;
int bInput = 8;

void setup() {
  Serial.begin(9600);
  air.begin(); // initialize the pneuDuino library. 
}

void loop() {
  air.update(); // update the pneuduino library. 

  rPressure = air.readPressure(rInput);
  gPressure = air.readPressure(gInput);
  bPressure = air.readPressure(bInput);
  
  delay(10);

  //RED MEDIATE
  if (rPressure > 200 || rPressure < 30) {
    //Serial.println("Deflating...");
    air.out(rInput, LEFT);
   // air.out(bInput, LEFT);
  }

  else {
    //Serial.println("Inflating...");
    air.in(rInput, LEFT); 
  }

  //GREEN MEDIATE
  if (gPressure > 200 || gPressure < 30) {
    //Serial.println("Deflating...");
    air.out(gInput, LEFT);
   // air.out(rInput, LEFT);
   // air.out(bInput, LEFT);
    //delay(50);
  }

  else {
    //Serial.println("Inflating...");
    air.in(gInput, LEFT);
  }

  //BLUE MEDIATE
  if (bPressure > 200 || bPressure < 30) {
    //Serial.println("Deflating...");
    air.out(bInput, LEFT);
  }

  else {
    //Serial.println("Inflating...");
    air.in(bInput, LEFT);
  }

  
  //RED PRESSED
  if (rPressure > 220) {
    air.in(rInput, RIGHT);
    r = map(rPressure, 190, 255, 0, 255);
    Serial.print("R value: ");
    Serial.println(r);
  }
  
  else {
    air.out(rInput, RIGHT);
  }

  //GREEN PRESSED
  if (gPressure > 220) {
    air.in(gInput, RIGHT);
    g = map(gPressure, 190, 255, 0, 255);
    Serial.print("G value: ");
    Serial.println(g);
  }
  
  else {
    air.out(gInput, RIGHT);
  }

  //BLUE PRESSED
  if (bPressure > 220) {
    air.in(bInput, RIGHT);
    b = map(bPressure, 190, 255, 0, 255);
    Serial.print("B value: ");
    Serial.println(b);
  }
  
  else {
    air.out(bInput, RIGHT);
  }
  
}
