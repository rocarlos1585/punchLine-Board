#include <Keyboard.h>
#define KEY_AB_COR 0x7B;
#define KEY_CERR_COR 0x7d;
char boton1;
char boton2;
int button=A0;
int bandera = 1;
int resread;
int boton;
void setup() {
  // put your setup code here, to run once:
pinMode(button, INPUT);
Serial.begin(9600);
Keyboard.begin();
}


void loop() {
  if(Serial.available()>0){
  boton = Serial.read();

  if(boton=='1'){
      boton1=KEY_LEFT_CTRL;
      boton2='z';}
      if(boton=='2'){
      boton1=KEY_LEFT_ALT;
      boton2=KEY_TAB;}
    if(boton=='3'){
      boton1=KEY_LEFT_CTRL;
      boton2='c';}
    if(boton=='4'){
      boton1=KEY_LEFT_ALT;
      boton2=KEY_F4;
      }
    if(boton=='5'){
      boton1='n';
      boton2='n';}
    if(boton=='6'){
      boton1='n';}
    if(boton=='7'){
      boton1='n';}
    if(boton=='8'){
      boton1=KEY_BACKSPACE;}
    if(boton=='9'){
      boton='n';}
    
  }
  
    
    
resread = analogRead(button);
map(resread, 0, 1023, 0, 255);

if(resread > 700){

  if(boton=='1' || boton=='2' || boton=='3' || boton=='4' || boton=='5'){

  Keyboard.press(boton1);
  delay(50);
  Keyboard.press(boton2);
  delay(50);
  Keyboard.release(boton2);
  Keyboard.release(boton1);

}
  if(boton=='6' || boton=='7' || boton=='8' || boton=='9'){
    Keyboard.press(boton1);
    delay(100);
    Keyboard.release(boton1);
    }
}
}

