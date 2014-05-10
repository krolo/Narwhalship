/*
MP3player.playTrack(1); = button 0 sound
 MP3player.playTrack(2); = button 1 sound
 MP3player.playTrack(3); = game loose
 MP3player.playTrack(4); = game win 
 MP3player.playTrack(5); = game start (microwave)




*/
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h> 
#include <SFEMP3Shield.h>
SdFat sd;
SFEMP3Shield MP3player;
int x = 0;    // variable
#define PIN 5
int game;
int ledPin0 = 4;
int ledPin1 = 10;
int switch0 = 14;
int switch1 = 15;
int solenoidPin = 19;
int endpixel = 150;
int selectPin = 17;
int gameswitchPin = 16;
int difficultyPin = 18;
int LED0 = HIGH;
int LED1 = LOW;
int LEDmeter = 0;
int stoppy = LOW;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(endpixel, PIN, NEO_GRB + NEO_KHZ800);      // the first number is how many leds you have, the second is the pin we are using as defined pin 6

volatile int state = LOW;
void setup() {
   sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();
pinMode(PIN,OUTPUT); 
  pinMode(14,INPUT); 
  pinMode(15,INPUT); 
  pinMode(16,INPUT); 
  pinMode(17,INPUT); 
    pinMode(19,OUTPUT); 
   pinMode(ledPin0, OUTPUT);
   pinMode(ledPin1, OUTPUT);
    pinMode(solenoidPin, OUTPUT);
    digitalWrite(16, HIGH);
  attachInterrupt(1, interrupt, RISING);
  Serial.begin(9600);      // open the serial port at 9600 bps:    
}

void loop() {  
  if ( game == HIGH){
     int wait = analogRead(difficultyPin)*2;
    bargame(wait);
    
  } else {
  if ( x == 0){
   mode0(5000, 60);
  }
 else if ( x == 1){
    mode1(5000, 30);
  }
// else if ( x == 2){
//   mode2(100, 150);
 //  }
 // else if ( x == 3){
 //  mode3(100, 100);
// }
  else if ( x == 4){
    mode4(500, 20);
  }
  else if ( x == 5){
    mode5(500, 30);
  }
  else if ( x == 6){
    mode6(4000, 25);
  }
    else if ( x == 7){
    mode7(400, 25);
  }
    else if ( x == 8){
    mode8(400, 25);
  }
  delay(30);
  
   
  
  }
}

 void bargame(int wait){
            LED0 = HIGH;
            digitalWrite(ledPin0, LED0);
            LED1 = LOW;
            digitalWrite(ledPin1, LED1);
   if (stoppy == HIGH){
    int reset = digitalRead(selectPin);
     if ( reset == HIGH){
       Serial.print("Game has been reset"); 
       stoppy = LOW;
     }
     delay(50);
     
   } else {
     MP3player.playTrack(5);
   colorWipe(strip.Color(255, 0, 50), 80); // Red
            LED0 = HIGH;
            digitalWrite(ledPin0, LED0);
            LED1 = HIGH;
            digitalWrite(ledPin1, LED1);
            delay(1000);
            LED0 = LOW;
            digitalWrite(ledPin0, LED0);
            LED1 = LOW;
            digitalWrite(ledPin1, LED1);
            delay(1000);
            LED0 = HIGH;
            digitalWrite(ledPin0, LED0);
            LED1 = LOW;
            digitalWrite(ledPin1, LED1);
  for ( LEDmeter = 20; LEDmeter <= endpixel; LEDmeter--){
        for ( int i = 0; i < LEDmeter; i++){
        strip.setPixelColor(i,230,100,0);
        }
         for ( int i = LEDmeter; i < endpixel; i++){
        strip.setPixelColor(i,0,0,0);
        }
          Serial.print("LED meter is"); 
           Serial.print(LEDmeter); 
           Serial.print("\t"); 
     Serial.println(); 
         strip.show();
      delay(wait);
      if ( LEDmeter >= endpixel){
        MP3player.playTrack(4);
          Serial.print("dispensing liquid"); 
    Serial.print("\t"); 
     Serial.println(); 
    digitalWrite(solenoidPin, HIGH); 
     
     delay(5000);
     digitalWrite(solenoidPin, LOW); 
    Serial.print("needs reset"); 
     stoppy = HIGH;
}
      if ( LEDmeter <= 0){
         MP3player.playTrack(3);
          stoppy = HIGH;
          delay(5000);
           break; 
      }
      if ( game != HIGH){
        break;
      }
     }
   }
 }

 void mode0(int endcount, int wait){
      Serial.print("mode 0 "); 
    Serial.print("\t"); 
     Serial.println(); 
 int direction = 1;
  int direction2 = -1;
  int direction3 = 1;
  int direction4 = -1;
          for (int channel = 0, channel2 = endpixel/8, channel3 = endpixel/2 , channel4 = endpixel/4, howmanytimes = 0; howmanytimes < endcount; channel += direction, channel2 += direction2, channel3 += direction3, channel4 += direction4, howmanytimes++ ) {
  
                  if (channel == 0) {
                    direction = 1;
                      } 
                  if (channel2 == 0) {
                    direction2 = 1;
                      } 
                  if (channel3 == 0) {
                    direction3 = 1;
                      } 
                  if (channel4 == 0) {
                    direction4 = 1;
                      } 
                      
                  for (int j = 0; j <= endpixel; j++){
                      if (j == channel){
                        int red = 255;
                        int green = 5;
                        int blue = 67;
                         strip.setPixelColor(channel,red,green,blue);
                         
                           red = red *.3;
                           green = green *.3;
                           blue = blue *.3;
                           if ( direction == 1){
                           strip.setPixelColor(channel -1,red,green,blue);
                           strip.setPixelColor(channel -2,red,green,blue);
                           } else {
                              strip.setPixelColor(channel + 1,red,green,blue);
                               strip.setPixelColor(channel + 2,red,green,blue);
                           }
                      } else if (j == channel2){
                        
                        int red = 0;
                        int green = 225;
                        int blue = 50;
                         strip.setPixelColor(channel2,red,green,blue);
                         
                           red = red *.4;
                           green = green *.4;
                           blue = blue *.4;
                           if ( direction2 == 1){
                           strip.setPixelColor(channel2 -1,red,green,blue);
                           strip.setPixelColor(channel2 -2,red,green,blue);
                           } else {
                              strip.setPixelColor(channel2 + 1,red,green,blue);
                               strip.setPixelColor(channel2 + 2,red,green,blue);
                           }
                      } else if (j == channel3){
                        int red = 200;
                        int green = 45;
                        int blue = 0;
                         strip.setPixelColor(channel3,red,green,blue);
                         
                           red = red *.4;
                           green = green *.4;
                           blue = blue *.4;
                           if ( direction3 == 1){
                           strip.setPixelColor(channel3 -1,red,green,blue);
                           strip.setPixelColor(channel3 -2,red,green,blue);
                           } else {
                              strip.setPixelColor(channel3 + 1,red,green,blue);
                              strip.setPixelColor(channel3 + 2,red,green,blue);
                           }
                        
                        
                         
                      } else if (j == channel4){
                        int red = 0;
                        int green = 0;
                        int blue = 255;
                         strip.setPixelColor(channel4,red,green,blue);
                         
                           red = red *.4;
                           green = green *.4;
                           blue = blue *.4;
                           if ( direction4 == 1){
                           strip.setPixelColor(channel4 -1,red,green,blue);
                           strip.setPixelColor(channel4 -2,red,green,blue);
                           } else {
                              strip.setPixelColor(channel4 + 1,red,green,blue);
                              strip.setPixelColor(channel4 + 2,red,green,blue);
                           }
                         strip.setPixelColor(channel4,0,0,240);
                      } else {
                         strip.setPixelColor(j,0,0,0);   // turn off rest of leds
                      }
                    }
   
                    if (channel == endpixel) {
                        direction = -1;
                        }
    
                    if (channel2 == endpixel) {
                        direction2 = -1;
                        }
                    if (channel3 == endpixel) {
                        direction3 = -1;
                        }
                    if (channel4 == endpixel) {
                        direction4 = -1;
                        }
     strip.show();
     delay(wait);
     if ( x != 0 || game == HIGH){
       break;
     }
          }
  
}
   
 
  void mode1(int endcount, int wait){
       Serial.print("mode 1"); 
    Serial.print("\t"); 
     Serial.println(); 
     int direction = 1;
  int direction2 = -1;
  int direction3 = 1;
  int direction4 = -1;
          for (int channel = 0, channel2 = endpixel/8, channel3 = endpixel/2 , channel4 = endpixel, howmanytimes = 0; howmanytimes < endcount; channel += direction, channel2 += direction2, channel3 += direction3, channel4 += direction4, howmanytimes++ ) {
                if ( x != 1 || game == HIGH){
       break;
     }
                  if (channel == 0) {
                    direction = 1;
                      } 
                  if (channel2 == 0) {
                    direction2 = 1;
                      } 
                  if (channel3 == 0) {
                    direction3 = 1;
                      } 
                  if (channel4 == 0) {
                    direction4 = 1;
                      } 
                      
                  for (int j = 0; j <= endpixel; j++){
                      if (j == channel){
                         strip.setPixelColor(channel,0,25,167);
                      } else if (j == channel2){
                         strip.setPixelColor(channel2,0,300,50);
                      } else if (j == channel3){
                         strip.setPixelColor(channel3,50,240,0);
                      } else if (j == channel4){
                         strip.setPixelColor(channel4,40,0,240);
                      } else {
                      //   strip.setPixelColor(j,0,0,0);
                      }
                    }
   
                    if (channel == endpixel) {
                        direction = -1;
                        }
    
                    if (channel2 == endpixel) {
                        direction2 = -1;
                        }
                    if (channel3 == endpixel) {
                        direction3 = -1;
                        }
                    if (channel4 == endpixel) {
                        direction4 = -1;
                        }
     strip.show();
     delay(wait);
     if ( x != 1 || game == HIGH){
       break;
     }
          }
  
}
  
  void mode2(int endcount, int wait){
       Serial.print("mode 2"); 
    Serial.print("\t"); 
     Serial.println(); 
     // fill effect
    for ( int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){
     for ( int end = endpixel; end > 0; end--){
     for ( int start = 0;start <= end;start++){
          for (int j = 0; j <= end; j++){
                      if (j == start){
        strip.setPixelColor(start,40,0,240);
                      } else {
                 strip.setPixelColor(j, strip.Color(0, 50, 0) );
                     }
                      for ( int j = end;j <= endpixel;j++){
                        strip.setPixelColor(j,40,0,240);
                      }
                        
                   strip.show();
                   delay(wait);
                   if ( x != 2 || game == HIGH){
       break;
     }
                   
                      }
                   }
                 } 
                }
  }
 void mode3(int endcount, int wait){
  Serial.print("mode 3"); 
    Serial.print("\t"); 
     Serial.println(); 
     //  reverse fill effect
    for ( int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){
     for ( int end = 0; end < endpixel; end++){
     for ( int start = end;start >= 0;start--){
          for (int j = 0; j <= end; j++){
                      if (j == start){
        strip.setPixelColor(start,40,0,240);
                      } else {
                 strip.setPixelColor(j, strip.Color(0, 0, 0) );
                     }
                      for ( int j = end;j <= endpixel;j++){
                        strip.setPixelColor(j,40,0,240);
                      }
                        
                   strip.show();
                   delay(wait);
                   if ( x != 3 || game == HIGH){
       break;
     }
                   
                      }
                   }
                 } 
                }
   
 }
 
 void mode4(int endcount, int wait){
     Serial.print("mode 4 "); 
    Serial.print("\t"); 
     Serial.println(); 
for (int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
            if ( x != 4 || game == HIGH){
       break;
     }
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
          delay(wait);
                   if ( x != 4 || game == HIGH){
       break;
     }
  }
}

 }
 
 void mode5(int endcount, int wait){
     Serial.print("mode 5 "); 
    Serial.print("\t"); 
     Serial.println(); 
   int direction =1;
          for (int howmanytimes = 0, channel = 0;howmanytimes < endcount; howmanytimes++, channel += direction){
   
            if (channel == 0){
                direction = 1;
                }
                int red = 50;
                int green = 200;
                int blue = 0;
           for(uint16_t i=0; i<strip.numPixels(); i++) {
              if (i == channel){                
                  strip.setPixelColor((i),red,green,blue);
                  red = red * .6;
                green = green * .6;
                blue = blue * .6;
                  strip.setPixelColor((i+1),red,green,blue);
                   strip.setPixelColor((i-1),red,green,blue);
                   red = red * .4;
                green = green * .4;
                blue = blue * .4;
                  strip.setPixelColor((i+2),red,green,blue);
                  strip.setPixelColor((i-2),red,green,blue);
                 red = red * .2;
                green = green * .2;
                blue = blue * .2;
                  strip.setPixelColor((i+3),red,green,blue);
                  strip.setPixelColor((i-3),red,green,blue);
              } else {
                 strip.setPixelColor(i, strip.Color(0, 0, 0) );
                     }
               }
      strip.show();
      delay(wait);
           if ( x != 5 || game == HIGH){
       break;
     }
              if (channel == strip.numPixels()){
                    direction = -1;
                    }
          
 }
   
 }
 
 
 void mode6(int endcount, int wait){
     Serial.print("Mode 6 "); 
    Serial.print("\t"); 
     Serial.println(); 
   int power1 = 50;
   int power2 = 205;
   int power3 = 205;
   int power4 = 105;
  
                  for (int channel=0, channel2 = strip.numPixels(), howmanytimes = 0; howmanytimes < endcount; howmanytimes++){ 
                     
                   

                       if ( channel > strip.numPixels()){
                             channel = 0;
                             channel2 = strip.numPixels();
                              }
                
   
  
             for(uint16_t i=0; i<strip.numPixels(); i++) {
              if (i == channel){
                    strip.setPixelColor(i,power1,power2,power1);
              if ( (i -1) >= 0){
                    strip.setPixelColor(i-1,power2,power2,power2);
                    }
              if ( (i -2) >= 0){
                   strip.setPixelColor(i-2,power3,power2,power3);
                   }
              if ( (i -3) >= 0){
                   strip.setPixelColor(i-3,power4,power2,power4);
                   } 
              } else if (i == channel2){
                   strip.setPixelColor(i,power1,power2,power1);
              if ( (i + 1) <= strip.numPixels()){
                   strip.setPixelColor(i+1,power2,power2,power2);
                   }
              if ( (i + 2) <= strip.numPixels()){
                   strip.setPixelColor(i+2,power3,power2,power3);
                   }
              if ( (i + 3) <= strip.numPixels()){
                   strip.setPixelColor(i+3,power4,power2,power4);
                   } 
               } else {
                   strip.setPixelColor(i, strip.Color(50, 205, 50) );
                      }
                 }
 
        power1 +=  20;
        power3 -= 8;
        power4 -= 8;

     if (power1 > 205){
           channel++;
           channel2--;
           power1 = 50;
           power3 = 205;
           power4 = 105;
           }
  
     strip.show();
      delay(wait);
            if ( x != 6 || game == HIGH){
       break;
     }
   }            
  }
   
  void mode7(int endcount, int wait){
       Serial.print("mode 7"); 
    Serial.print("\t"); 
     Serial.println(); 
     int direction = 1;
  int direction2 = -1;
  int direction3 = 1;
  int direction4 = -1;
          for (int channel = 0, channel2 = endpixel/8, channel3 = endpixel/2 , channel4 = endpixel, howmanytimes = 0, tick = 0; howmanytimes < endcount; channel += direction, tick++ ) {
  
                if (tick > 8){
                  tick = 0;
                }
                if ( tick > 1){
                  channel2 += direction2;
                }
                 if ( tick > 3){
                  channel3 += direction3;
                }
                 if ( tick > 6){
                  channel4 += direction4;
                }
            
                  if (channel == 0) {
                    direction = 1;
                      } 
                  if (channel2 == 0) {
                    direction2 = 1;
                      } 
                  if (channel3 == 0) {
                    direction3 = 1;
                      } 
                  if (channel4 == 0) {
                    direction4 = 1;
                      } 
                      
                  for (int j = 0; j <= endpixel; j++){
                      if (j == channel){
                         strip.setPixelColor(channel,200,25,50);
                      } else if (j == channel2){
                         strip.setPixelColor(channel2,80,130,0);
                      } else if (j == channel3){
                         strip.setPixelColor(channel3,135,0,200);
                      } else if (j == channel4){
                         strip.setPixelColor(channel4,0,30,240);
                      } else {
                        strip.setPixelColor(j,0,0,0);
                      }
                    }
   
                    if (channel == endpixel) {
                        direction = -1;
                        }
    
                    if (channel2 == endpixel) {
                        direction2 = -1;
                        }
                    if (channel3 == endpixel) {
                        direction3 = -1;
                        }
                    if (channel4 == endpixel) {
                        direction4 = -1;
                        }
     strip.show();
     delay(wait);
 
     if ( x != 7 || game == HIGH){
       break;
     }
          }
}
  
  void mode8(int endcount, int wait){
        Serial.print("mode 8"); 
    Serial.print("\t"); 
     Serial.println(); 
      int flashcount = 0;
  int waslow = 0;
  int channel = 0;
  int endchannel = 0;
  int start = 0;
  for (int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){

    if (endchannel - 4 < 0) {
      start = 0;
    } else {
      start = endchannel - 4;
    }
   for (int betweenchannel = start; betweenchannel <= endchannel ; betweenchannel += 1) {
       strip.setPixelColor(betweenchannel,120,180,0);
   }
if ( flashcount > 5 ){
         strip.setPixelColor(endchannel,120,180,0);
  endchannel++;
  flashcount = 0;
} else {
  if ( waslow == 0){
      strip.setPixelColor(endchannel,0,0,0);
      strip.setPixelColor(start,0,0,0);
    waslow = 1;
  } else {
          strip.setPixelColor(endchannel,120,180,0);
      strip.setPixelColor(start,120,180,0);
    waslow = 0;
    flashcount++;
  }
}
  
  if (endchannel > 150){
    endchannel = 0;
  }
      strip.show();
      delay(wait);
  }
}
 
 
  
  
    void colorWipe(uint32_t c, uint8_t wait) {           // unint32_t is the defining variable, it is expecing a large variable, uint8_t is expecting a smaller variable
  for(uint16_t i=0; i<endpixel; i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}







  
void interrupt()
{
   static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
   if (interrupt_time - last_interrupt_time > 300){
    MP3player.stopTrack();
    game = digitalRead(gameswitchPin);
      int button0 = digitalRead(switch0);
    int button1 = digitalRead(switch1);
    if ( game == HIGH ){
          if ( button0 == HIGH && LED0 == HIGH ){
            LEDmeter += 15;
            LED0 = LOW;
            digitalWrite(ledPin0, LED0);
            LED1 = HIGH;
            digitalWrite(ledPin1, LED1);
            Serial.print("Button 0 has been pressed"); 
            Serial.print("\t"); 
            Serial.println(); 
             MP3player.playTrack(1);
          } else if ( button1 == HIGH && LED1 == HIGH ){
             LEDmeter += 15;
            LED1 = LOW;
            digitalWrite(ledPin1, LED1);
            LED0 = HIGH;
            digitalWrite(ledPin0, LED0);
            Serial.print("Button 1 has been pressed"); 
            Serial.print("\t"); 
            Serial.println(); 
             MP3player.playTrack(2);
          }
    } else {
      x++;
      if (x > 8){
        x = 0;
      }
            Serial.print("Variable x is "); 
            Serial.print(x); 
            Serial.print("\t"); 
            Serial.println(); 
 
    }
      
      
  }
    last_interrupt_time = interrupt_time;
  state = !state;
}


