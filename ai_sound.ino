

#include "SPI.h"
#include "TFT_22_ILI9225.h"



#define TFT_CS  2  // SS
#define TFT_RST 3
#define TFT_RS  4
#define TFT_SDI 11  // MOSI
#define TFT_CLK 13  // SCK
   
#define TFT_BRIGHTNESS 200
TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_BRIGHTNESS);
uint16_t xx, yy;
boolean flag = false;

//------------------------------------------------------------------------
int in = A0;
int data1[200];
int data2[200];
int data3[200];

float w[200];
float b;
float z;
float a;
float inx;

void setup() {
  // put your setup code here, to run once:
Serial.begin(250000);

tft.begin();
tft.setOrientation(1);
//tft.drawRectangle(5, 40, 213,170 , COLOR_BLUE);

}

void test(){
 
 for(int j =0;j<200;j++){
  data1[j] = analogRead(in); 
  Serial.println(data1[j]);
  delay(5);
 }

 for(int j =0;j<200;j++){
  data2[j] = analogRead(in); 
  Serial.println(data2[j]);
  delay(5);
 }

 for(int j =0;j<200;j++){
  data3[j] = analogRead(in); 
  Serial.println(data3[j]);
  delay(5);
 }

 for()


 
}



void loop() {
  test();

  
 Serial.println(analogRead(in));
 tft.drawCircle(10,10 , 10, COLOR_GREEN);
 for(int j =0;j<200;j++){
  data1[j] = analogRead(in); 
  Serial.println(data1[j]);
  delay(5);
 }

 tft.drawCircle(10,10 , 10, COLOR_BLUE);
 for(int i =1; i<200;i++){
  
  tft.drawPixel(i,90+data1[i-1]*50/800,COLOR_RED); 
}
delay(2000);


tft.clear();

 
}

void train(float in[200]){
  float z;
  for(int i = 0 ; i <200; i ++){
      z+= in[i]*w[i];
  }
  z+=b;

  float pred = sigmoid(z);
  float cost = (pred - target)*(pred - target);
  
}


float sigmoid(float x){ 
  return  1/(1+pow(so_e,-x)); 
}
float sigmoid_p(float x){
  return sigmoid(x) * (1-sigmoid(x));
}
