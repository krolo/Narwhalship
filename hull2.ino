

const int relayPin = 5;
#include "Tlc5940.h"
int runtime = 30000; // 30 seconds
int funcDelay = 40;
int funcEndcount = 100;
int blue = 0;
int green = 16;
int red = 32;
int bluepower1 = 4095;
int greenpower1 = 0;
int redpower1 = 0;
int bluepower2 = 0;
int greenpower2 = 4094;
int redpower2 = 0;
int bluepower3 = 0;
int greenpower3 = 0;
int redpower3 = 0;
int bluepower4 = 0;
int greenpower4 = 0;
int redpower4 = 0;
int choice1 = 0;
int choice2 = 0;
int choice3 = 0;
int choice4 = 0;
int delay1 = 40;
int bluepower[32];
int greenpower[32];
int redpower[32];
      
int sequence0[4]= {0, 9, 18, 27};
int sequence1[4]= {8, 17, 26, 4};
int sequence2[4]= {16, 25, 5, 12};
int sequence3[4]= {24, 6, 13, 20};
int sequence4[4]= {7, 14, 21, 28};
int sequence5[4]= {15, 22, 29, 3};
int sequence6[4]= {23, 30, 2, 11};
int sequence7[4]= {31, 1, 10, 19};
     
int sequence[16]    =  {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
byte sequencefibi[32]=  {0, 9, 18, 27, 8, 17, 26, 4, 16, 25, 5, 12, 24, 6, 13, 20, 7, 14, 21, 28, 15, 22, 29, 3, 23, 30, 2, 11, 31, 1, 10, 19};

    
int position[96] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95};
int choice[96] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95};
int loopcount = 0;
 void setup(){
    Tlc.init();
    pinMode(relayPin, OUTPUT);
 }
 void loop() {

  time();
  rain(funcEndcount,funcDelay);
  time();
  zoom(funcEndcount,funcDelay);
  time();
  fibi2(funcEndcount,funcDelay,1);
  time();
   knight32fade(funcEndcount,funcDelay);
     time();
 // fourknight(funcEndcount,funcDelay);
   time();
  knight32morph(funcEndcount,funcDelay);

  wiperight(600,20);
  
  
  time();
   
  innerfade(funcEndcount,funcDelay);
  time();
  
    
   
 fibi2(funcEndcount,funcDelay,5);
 time();
 //fourknightLED(funcEndcount,funcDelay);
 time();
 // fibi3(funcEndcount,funcDelay,12);
  time();
 // fourknightLED(funcEndcount,funcDelay);
  time();
  

 
 // fibi3(funcEndcount,funcDelay,10);
  time();
 
  outrun32(funcEndcount,funcDelay);
 
   time();
    rain(funcEndcount,funcDelay);
 
  // spiral(512,30);
   combo1(funcEndcount,funcDelay);
   time();
   zoom(funcEndcount,funcDelay);
   time();
  // fourknight(funcEndcount,funcDelay);
   time();
  middlecolorcombo(funcEndcount,funcDelay);
  time();
 // twoknight16(400,60);
 twocolorrainbow(funcEndcount,funcDelay);
 time();
//   fourknight(200,150);
   
//  twocolorrandom(128,200);
 // twoknight16(128,180);
  flash(funcEndcount,funcDelay);
  time();
  rain(funcEndcount,funcDelay); 
  //fill(200,40); 
  
  loopcount++;
   
}


  void time(){
funcDelay = random(30,300);
funcEndcount = runtime/funcDelay;
}


 
 void spiral(int endcount, int wait){
   Tlc.clear();
   choice1 = random(0,95);
   power(choice1,0);
   choice2 = random(0,95);
   power(choice2,1);
   choice3 = random(0,95);
   power(choice3,2);
  int channel = 0;
  int channel1 =15;
  int channel2 = 31;
   for (int howmanytimes = 0;howmanytimes < endcount; howmanytimes++){
     Tlc.set(channel + blue, bluepower[0]);
      Tlc.set(channel + green, greenpower[0]);
      Tlc.set(channel + red, redpower[0]);
      
      Tlc.set(channel1 + blue, bluepower[1]);
      Tlc.set(channel1 + green, greenpower[1]);
      Tlc.set(channel1 + red, redpower[1]);
      
      Tlc.set(channel2 + blue, bluepower[2]);
      Tlc.set(channel2 + green, greenpower[2]);
      Tlc.set(channel2 + red, redpower[2]);
      Tlc.update();
      delay(wait);
      channel++;
      channel1++;
      channel2++;
      if (channel > 8){
        channel = 0;
      }
      if (channel1 > 26){
        channel1 = 8;
      }
      if (channel2 > 31){
        channel2 = 26;
      }
   }
 }
 
 
 
 
 
 void faster(){
   Tlc.clear();
  int progressive = 200;
  for (progressive; progressive <= 10; progressive += -10){
   choice1 = random(0,95);
    power(choice1,0);
    
    for (int channel = 0;channel < 25;channel++){
    Tlc.set(channel + blue, bluepower[0]);
      Tlc.set(channel + green, greenpower[0]);
      Tlc.set(channel + red, redpower[0]);
   Tlc.update();
   delay(progressive);
    }
  }
 } 
     
 void wiperight(int endcount, int wait){
   
   int power1 = 0;
   int power2 = 4080;
   int power3 = 0;
   int power4 = 0;
    int sequence[4][4]= {{ 0, 4,8,12},
                        {1,5,9,13},
                        {2,6,10,14},
                        {3,7,11,15}};
                        
                  for (int i=0, howmanytimes = 0; howmanytimes < endcount; howmanytimes++){ 
                      Tlc.clear();
                            
                       if ( i > 3){
    i = 0;
  }
  if ( i  < 30){                
 for (int j=0; j < 4; j++){ 
int channel = sequence[i][j];
 if (channel != NULL){
 Tlc.set(channel, power1);
   }
 }
  }
   if ( i  < 31){ 
 if ( (i -1) >= 0){
 int newi = i -1;
  for (int j=0; j < 4; j++){ 
int channel = sequence[newi][j];
 if (channel != NULL){
 Tlc.set(channel, power2);
 }
 } 
 }
   }
  if ( i  < 32){ 
  if ( (i -2) >= 0){
 int  newi = i -2;
 int  newk = i -1;
  for (int j=0; j < 4; j++){ 
int channel = sequence[newi][j];
int altchannel = sequence[newk][j];
if (channel == altchannel){
  Tlc.set(channel, power2);
} else {
 if (channel != NULL){
 Tlc.set(channel, power3);
 }
 } 
  }
  }
  }
 

 power1 +=  120;
 power3 -= 60;
 power4 -= 60;
 if (power1 > 3940){
   i++;
   power1 = 0;
   power3 = 4095;
   power4 = 2025;
 }
   int direction = 1;
    Tlc.update();
   

    delay(wait);
    
 }                                
 }
   
   
   
   
   
 void fill(int endcount, int wait){
   Tlc.clear();
   int waslow = 0;
   int end = 25;
   int fillstart = 25;
   int fillend = 25;
   int position[96] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95};

   choice[0] = random(95);
   power(choice[0], 0);
   
   for (int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){
     if ( waslow == 0){
    Tlc.set(blue + position[0], 0);
   Tlc.set(red + position[0], 0);
   Tlc.set(green + position[0], 0);
    
    waslow = 1;
  } else {
   Tlc.set(blue + position[0], bluepower[0]);
   Tlc.set(red + position[0], redpower[0]);
   Tlc.set(green + position[0], greenpower[0]);
    waslow = 0;
  }
   Tlc.update();
  delay(wait);
   }
   for (int fillstart = 25;fillstart == 0;fillstart--){
   int  choice = random(95);
   power(choice, fillstart);
   for (int start = 0; start < fillstart; start++){
     for (int constantstart = fillstart, constantend = 25;constantstart <= constantend; constantstart++){
     Tlc.set(blue + position[constantstart], bluepower[constantstart]);
   Tlc.set(red + position[constantstart], redpower[constantstart]);
   Tlc.set(green + position[constantstart], greenpower[constantstart]);
   }
     Tlc.set(blue + position[start], bluepower[fillstart]);
   Tlc.set(red + position[start], redpower[fillstart]);
   Tlc.set(green + position[start], greenpower[fillstart]);
   Tlc.update();
  delay(wait);
   }
   
   for (fillstart = 25, fillend = 25;fillstart <= fillend; fillstart++){
     Tlc.set(blue + position[fillstart], bluepower[0]);
   Tlc.set(red + position[fillstart], redpower[0]);
   Tlc.set(green + position[fillstart], greenpower[0]);
   }
   }
 }
   
   
   
   
   
   
   
   
   
     
 
 
 
 
 
 
 
 
 
 
 
void zoom(int endcount, int wait){
int count = 0;
int z = 0;
 int  sequence[7][16] = {{0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15},
                          {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13,12},
                          {0,4,8,12,13,9,5,1,2,6,10,14,15,11,7,3},
                          {15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6},
                          {0,5,10,15,3,6,9,12,0,1,2,3,12,13,14,15},
                          {3,2,1,0,8,9,10,11,12,13,14,15,7,6,5,4},
                          {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};
  for (int channel = 0, channel2 = 15, howmanytimes = 0; howmanytimes < endcount ; channel++, howmanytimes++ , channel2--) {

    Tlc.clear();

    Tlc.set(sequence[z][channel] + blue, bluepower[0]);
    Tlc.set(sequence[z][channel] + green, greenpower[0]);
    Tlc.set(sequence[z][channel] + red, redpower[0]);
    if (!(channel + 1 >= 15)) {
      int newchan = channel + 1;
      Tlc.set(sequence[z][channel] + blue, bluepower[1]);
      Tlc.set(sequence[z][channel] + green, greenpower[1]);
      Tlc.set(sequence[z][channel] + red, redpower[1]);
    }
     if (!(channel + 2 >= 15)) {
       int newchan1 = channel + 2;
      Tlc.set(sequence[z][channel] + blue, bluepower[2]);
      Tlc.set(sequence[z][channel] + green, greenpower[2]);
      Tlc.set(sequence[z][channel] + red, redpower[2]);
    }
    Tlc.set(sequence[z][channel2]+ blue, bluepower[3]);
    Tlc.set(sequence[z][channel2] + green, greenpower[3]);
    Tlc.set(sequence[z][channel2] + red, redpower[3]);
    
     if (!(channel - 1 <= 0)) {
       int newchan2 = channel2 - 1;
      Tlc.set(sequence[z][newchan2]  + blue, bluepower[4]);
      Tlc.set(sequence[z][newchan2]  + green, greenpower[4]);
      Tlc.set(sequence[z][newchan2]  + red, redpower[4]);
    }
     if (!(channel2 - 2 <= 0)) {
      int newchan3 = channel2 - 2;
      Tlc.set(sequence[z][newchan3] + blue, bluepower[5]);
      Tlc.set(sequence[z][newchan3] + green, greenpower[5]);
      Tlc.set(sequence[z][newchan3] + red, redpower[5]);
    }
   
    if (channel >= 15){
      channel = 0;
    choice1 = random(0,95);
    power(choice1,position[0]);
    choice1 = random(0,95);
    power(choice1,position[1]);
    choice1 = random(0,95);
    power(choice1,position[2]);
    }
    if (channel2 <= 0){
     channel2 = 15;    
    choice1 = random(0,95);
    power(choice1,position[3]);
    choice1 = random(0,95);
    power(choice1,position[4]);
    choice1 = random(0,95);
    power(choice1,position[5]);
    choice1 = random(0,95);
   
    

  
    Tlc.update();

    delay(wait);
    count++;
 if (count >= 200){
 z++;
 count =0 ;
 } 
  if ( z > 6){
   z= 0;
 }
    
    
    }
  }
}











 void rain(int endcount, int wait){
   int count = 0;
   int z = 0;
 int  sequence[7][16] = {{0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15},
                          {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13,12},
                          {0,4,8,12,13,9,5,1,2,6,10,14,15,11,7,3},
                          {15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6},
                          {0,5,10,15,3,6,9,12,0,1,2,3,12,13,14,15},
                          {3,2,1,0,8,9,10,11,12,13,14,15,7,6,5,4},
                          {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};
for (int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){
for (int i =0; i < 16; i++){
power(choice[i], position[i]);
}

for (int k = 0; k < 16; k++){
 Tlc.set(blue + sequence[z][k], bluepower[k]);
 Tlc.set(green + sequence[z][k], greenpower[k]);
 Tlc.set(red + sequence[z][k], redpower[k]);
 
}
Tlc.update();
 delay(wait);
 count++;
 if (count >= 200){
 z++;
 count =0 ;
 } 
  if ( z > 5){
   z= 0;
 }
   
 for ( int j = 0; j < 96; j++){
 choice[j] = choice[j] + 3;
 if (choice[j] > 95 ){
   choice[j] = 0;
 }
 }
 
}
 }




void fibi2(int endcount, int wait, int jump){
int count = 0;
int z = 0;

  int sequence[5][4][4] = {
    {
 {0,4,8,12},
{1,5,9,13},
 {2,6,10,14},
{3,7,11,15}
    },
    {
 {3,7,11,15},
{2,6,10,14},
{1,5,9,13},
 {0,4,8,12},
    },
    {
{0,4,8,12},
{1,5,9,13},
{2,6,10,14},
 {3,7,11,15}
    },
    {
 {12,13,14,15},
{8,9,10,11},
{4,5,6,7},
{0,1,2,3}
    },
    {
{0,1,2,3},
 {4,5,6,7},
{8,9,10,11},
 {12,13,14,15}}
  };
  
  for (int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){
  Tlc.clear();
   for (int i =0; i < 32; i++){
power(choice[i], position[i]);
}
   for (int t = 0; t < 4; t++){
  for (int k = 0; k < 4; k++){
 Tlc.set(blue + sequence[z][t][k], bluepower[t]);
 Tlc.set(green + sequence[z][t][k], greenpower[t]);
 Tlc.set(red + sequence[z][t][k], redpower[t]);
 }
   }
  Tlc.update();
 delay(wait);
 
  for ( int j = 0; j < 96; j++){
 choice[j] = choice[j] + jump;
 if (choice[j] > 95 ){
   choice[j] = 0;
 }
 }
  count++;
 if (count >= 120){
 z++;
 count =0 ;
 } 
  if ( z > 5){
   z= 0;
 }
 }
}

void fibi3(int endcount, int wait, int jump){

      
 
  
  for (int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){
  Tlc.clear();
    for (int n =0; n < 32; n++){
power(choice[n], position[n]);
}
  for (int i = 0; i < 32; i++){   
   
 Tlc.set(blue + sequence[i], bluepower[i]);
 Tlc.set(green + sequence[i], greenpower[i]);
 Tlc.set(red + sequence[i], redpower[i]);
 }
  Tlc.update();
 delay(wait);
  for ( int j = 0; j < 96; j++){
 choice[j] = choice[j] + jump;
 if (choice[j] > 95 ){
   choice[j] = 0;
   }
 
 }
 }
}

 
void flash(int endcount, int wait){
  int sequence[]={12,6,11,4,14,8,1,10,5,15,7,9,0,2,13,3};
  int flashcount = 0;
  int waslow = 0;
  int channel = 0;
  int endchannel = 0;
  int start = 0;
   choice1 = random(95);
    power(choice1, position[0]);
  for (int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){
  Tlc.clear();
    if (endchannel - 4 < 0) {
      start = 0;
    } else {
      start = endchannel - 4;
    }
      if (endchannel > 15){
    endchannel = 0;
    choice1 = random(0,95);
    power(choice1, position[0]);
  }
   for (int betweenchannel = start; betweenchannel <= endchannel ; betweenchannel += 1) {
     
     Tlc.set(blue + sequence[betweenchannel], bluepower[0]);
     Tlc.set(red + sequence[betweenchannel], redpower[0]); 
     Tlc.set(green + sequence[betweenchannel], greenpower[0]); 
   }
if ( flashcount > 5 ){
  Tlc.set(blue + sequence[endchannel], bluepower[0]);
  Tlc.set(red + sequence[endchannel], redpower[0]);
  Tlc.set(green + sequence[endchannel], greenpower[0]);
  endchannel++;
  flashcount = 0;
} else {
  if ( waslow == 0){
  
   Tlc.set(blue + sequence[endchannel], 0);
   Tlc.set(red + sequence[endchannel], 0);
   Tlc.set(green + sequence[endchannel], 0);
    Tlc.set(blue + sequence[start], 0);
    Tlc.set(red + sequence[start], 0);
    Tlc.set(green + sequence[start], 0);
    waslow = 1;
  } else {
  Tlc.set(blue + sequence[endchannel], bluepower[0]);
  Tlc.set(red + sequence[endchannel], redpower[0]);
  Tlc.set(green + sequence[endchannel], greenpower[0]);
    Tlc.set(blue + sequence[start], bluepower[0]);
  Tlc.set(red + sequence[start], redpower[0]);
  Tlc.set(green + sequence[start], greenpower[0]);
    waslow = 0;
    flashcount++;
  }
}
  

   Tlc.update();
  delay(wait);
  }
}
 
 
 
 
 
 
 void twocolorrainbow(int endcount, int wait){
    Tlc.clear();  
    choice1 = 0;
    choice2 = 48;
  int  sequence[]={0,1,4,5,8,9,12,13};
  int  sequence2[]={2,3,6,7,10,11,14,15};
   for (int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){   
   for (int channel = 0; channel < 8; channel++) {
     
     Tlc.set(blue + sequence[channel], bluepower[0]);
      Tlc.set(red + sequence[channel], redpower[0]);
      Tlc.set(green + sequence[channel], greenpower[0]);
      
   }
   for (int channel2 = 8; channel2 < 16; channel2++) {
     
     Tlc.set(blue + sequence2[channel2], bluepower[1]);
      Tlc.set(red + sequence2[channel2], redpower[1]);
      Tlc.set(green + sequence2[channel2], greenpower[1]);
      
   }
  
 Tlc.update();
  delay(wait);
  if (choice1 > 95 ){
    choice1 = 0;
  } else {
  choice1 += 2 ;
  }
  power(choice1, position[0]);
  if (choice2 > 95 ){
    choice2 = 0;
  } else {
  choice2 += 2;
  }
  power(choice2, position[1]);
   }
} 
 
 
 
 
void twocolorrandom(int endcount, int wait){
    Tlc.clear();  
   for (int howmanytimes = 0; howmanytimes < endcount; howmanytimes++){   
   for (int channel = 0; channel < 16; channel += 1) {
     
     Tlc.set(blue + channel, bluepower[0]);
      Tlc.set(red + channel, redpower[0]);
      Tlc.set(green + channel, greenpower[0]);
      
   }
   for (int channel2 = 15; channel2 < 32; channel2 += 1) {
     
     Tlc.set(blue + channel2, bluepower[1]);
      Tlc.set(red + channel2, redpower[1]);
      Tlc.set(green + channel2, greenpower[1]);
      
   }
 Tlc.update();
  delay(wait);
  choice1 = random(0,95);
  power(choice1, position[0]);
  choice2 = random(0,95);
  power(choice2, position[1]);
   }
} 
 
 
 

 
 
 
 
 
 void fourknightLED(int endcount,int wait){
  int direction = 1;
  int direction1 = -1;
    for (int channel = 0, channel2 = 8, channel3 = 16, channel4 = 24, channel5 = 31, channel6 = 23, channel7 = 15, channel8 = 7, howmanytimes = 0; howmanytimes < endcount; channel += direction, channel2 += direction, channel3 += direction, channel4 += direction, channel5 += direction1, channel6 += direction1, channel7 += direction1, channel8 += direction1, howmanytimes++ ) {
        Tlc.clear();

   
    if (channel == 0) {
      direction = 1;
      direction1 = -1;
    } 
   
  
  
           Tlc.set(channel + blue, bluepower[0]);
           Tlc.set(channel + green, greenpower[0]);
           Tlc.set(channel + red, redpower[0]);
           
           Tlc.set(channel2 + blue, bluepower[0]);
           Tlc.set(channel2 + green, greenpower[0]);
           Tlc.set(channel2 + red, redpower[0]);
           
           Tlc.set(channel3 + blue, bluepower[0]);
           Tlc.set(channel3 + green, greenpower[0]);
           Tlc.set(channel3 + red, redpower[0]);
           
           Tlc.set(channel4 + blue, bluepower[0]);
           Tlc.set(channel4 + green, greenpower[0]);
           Tlc.set(channel4 + red, redpower[0]);
           
            Tlc.set(channel5 + blue, bluepower[0]);
           Tlc.set(channel5 + green, greenpower[0]);
           Tlc.set(channel5 + red, redpower[0]);
           
           Tlc.set(channel6 + blue, bluepower[0]);
           Tlc.set(channel6 + green, greenpower[0]);
           Tlc.set(channel6 + red, redpower[0]);
           
           Tlc.set(channel7 + blue, bluepower[0]);
           Tlc.set(channel7 + green, greenpower[0]);
           Tlc.set(channel7 + red, redpower[0]);
           
           Tlc.set(channel8 + blue, bluepower[0]);
           Tlc.set(channel8 + green, greenpower[0]);
           Tlc.set(channel8 + red, redpower[0]);
   
   
    if (channel == 7) {
      direction = -1;
      direction1 = 1;
      choice1 = random(95);
      power(choice1, position[0]);
    }
    
    
     Tlc.update();
    delay(wait);
  }
}
 
 
 
 
 /*
void fourknight(int endcount,int wait){
  
  int direction = 1;
  int direction2 = -1;
  int direction3 = 1;
  int direction4 = -1;
   int  sequence[4][4][4] = {{{0,4,8,12},
                           {1,5,9,13},
                          {0,4,8,12,13,9,5,1,2,6,10,14,15,11,7,3},
                          {15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6}},

                          {{3,7,11,15},
                          {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13,12},
                          {0,4,8,12,13,9,5,1,2,6,10,14,15,11,7,3},
                          {15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6}},
                          {
                          {12,13,14,15},
                          {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13,12},
                          {0,4,8,12,13,9,5,1,2,6,10,14,15,11,7,3},
                          {15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6}},
                          {{0,1,2,3},
                          {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13,12},
                          {0,4,8,12,13,9,5,1,2,6,10,14,15,11,7,3},
                          {15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6}}};
    for (int channel = 0, channel2 = 1, channel3 = 2, channel4 = 3, howmanytimes = 0, count = 0; howmanytimes < endcount; channel += direction, channel2 += direction2, channel3 += direction3, channel4 += direction4, howmanytimes++, count++ ) {
        Tlc.clear();

   
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
      for (int t = 0; t < 4; t++){

 Tlc.set(blue + sequence[z][t][channel], bluepower[t]);
 Tlc.set(green + sequence[z][t][k], greenpower[t]);
 Tlc.set(red + sequence[z][t][k], redpower[t]);
 }
   
  
           Tlc.set(sequence[z][channel] + blue, bluepower[0]);
           Tlc.set(sequence[z][channel]+ green, greenpower[0]);
           Tlc.set(sequence[z][channel] + red, redpower[0]);
          
           Tlc.set(sequence1[z][channel2] + blue, bluepower[1]);
           Tlc.set(sequence1[z][channel2] + green, greenpower[1]);
           Tlc.set(sequence1[z][channel2] + red, redpower[1]);
           
           Tlc.set(sequence2[z][channel3] + blue, bluepower[2]);
           Tlc.set(sequence2[z][channel3]  + green, greenpower[2]);
           Tlc.set(sequence2[z][channel3]  + red, redpower[2]);
           
           Tlc.set(sequence3[z][channel4] + blue, bluepower[3]);
           Tlc.set(sequence3[z][channel4] + green, greenpower[3]);
           Tlc.set(sequence3[z][channel4]+ red, redpower[3]);
   
   
    if (channel == 3) {
      direction = -1;
      
    }
    
     if (channel2 == 3) {
      direction2 = -1;
      
    }
    if (channel3 == 3) {
      direction3 = -1;
    
    }
    
     if (channel4 == 3) {
      direction4 = -1;
     
    }
     Tlc.update();
    delay(wait);
    if (count >= 100){
      
      int number = random(3);
      channel= number;
      number = random(3);
      channel2= number;
     number = random(3);
      channel3= number;
    number = random(3);
      channel4= number;
      
   choice1 = random(95);
      power(choice1, position[0]);
      choice2 = random(95);
      power(choice2, position[1]);
         choice3 = random(95);
      power(choice3, position[2]);
       choice4 = random(95);
      power(choice4, position[3]);
  int sequence[z][] = {0,4,8,12};
 int sequence1[] = {1,5,9,13};
 int sequence2[] = {2,6,10,14};
  int sequence3[] = {3,7,11,15};
  
 } else if (count > 200){
    int number = random(3);
      channel= number;
      number = random(3);
      channel2= number;
     number = random(3);
      channel3= number;
    number = random(3);
      channel4= number;
    power(choice1, position[0]);
      choice2 = random(95);
      power(choice2, position[1]);
         choice3 = random(95);
      power(choice3, position[2]);
       choice4 = random(95);
      power(choice4, position[3]);
      int sequence0[] = {3,7,11,15};
 int sequence1[] = {2,6,10,14};
 int sequence2[] = {1,5,9,13};
  int sequence3[] = {0,4,8,12};
  
 } else if (count > 300){
     int number = random(3);
      channel= number;
      number = random(3);
      channel2= number;
     number = random(3);
      channel3= number;
    number = random(3);
      channel4= number;
    power(choice1, position[0]);
      choice2 = random(95);
      power(choice2, position[1]);
         choice3 = random(95);
      power(choice3, position[2]);
       choice4 = random(95);
      power(choice4, position[3]);
    int sequence0[] = {12,13,14,15};
 int sequence1[] = {8,9,10,11};
 int sequence2[] = {4,5,6,7};
  int sequence3[] = {0,1,2,3};
  
 } else if ( count > 400){
   count = 0;
     int number = random(3);
      channel= number;
      number = random(3);
      channel2= number;
     number = random(3);
      channel3= number;
    number = random(3);
      channel4= number;
        int sequence0[] = {0,1,2,3};
 int sequence1[] = {4,5,6,7};
 int sequence2[] = {8,9,10,11};
  int sequence3[] = {12,13,14,15};
   power(choice1, position[0]);
      choice2 = random(95);
      power(choice2, position[1]);
         choice3 = random(95);
      power(choice3, position[2]);
       choice4 = random(95);
      power(choice4, position[3]);
 }
  }
}
  */
 void outrun32(int endcount, int wait){
   int z = 0;
   int count = 0;
int direction = 1;
int direction2 = 1;
int direction3 = 1;
 int   sequence[12][16]={{15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6},
    {0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15},
      {0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15},
  {15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6},
 
     {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13,12},

 {0,4,8,12,13,9,5,1,2,6,10,14,15,11,7,3},
 
{15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6},
 {0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15},
 
   {15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6},
{0,4,8,12,13,9,5,1,2,6,10,14,15,11,7,3},

{5,6,9,10,1,2,13,14,4,7,8,11,12,15,0,3},
{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};
  for (int channel = 0, channel2 = 0, channel3 = 0, howmanytimes = 0, tick = 0; howmanytimes < endcount; channel += direction, channel3 += direction3, tick++, howmanytimes++) {
    if ( tick == 1){
      channel2 += direction2;
      tick = 0;
    } 
    if ( z > 12){
      z = 0;
    }
    Tlc.clear();
     if ( channel == 0){
       direction = 1;
     } else if ( channel2 == 0){
       direction = 1;
     }else if ( channel3 == 0){
       direction = 1;
     }
     
     if (channel > 15) {
       choice1 = random(0,95);
      power(choice1, position[0]);
      direction = -1;
    } 
    if (channel2 > 15) {
      direction2 = -1;
      choice2 = random(0,95);
      power(choice2, position[1]);
    } 
     if (channel3 > 15) {
      direction3 = -1;
      choice3 = random(0,95);
      power(choice2, position[2]);
    } 
   
         
           Tlc.set(sequence[z][channel] + blue, bluepower[0]);
           Tlc.set(sequence[z][channel] + green, greenpower[0]);
           Tlc.set(sequence[z][channel] + red, redpower[0]);
           
        
           Tlc.set(sequence[z][channel2]  + blue, bluepower[1]);
           Tlc.set(sequence[z][channel2] + green, greenpower[1]);
           Tlc.set(sequence[z][channel2] + red, redpower[1]);
       
           Tlc.set(sequence[z][channel3] + blue, bluepower[2]);
           Tlc.set(sequence[z][channel3] + green, greenpower[2]);
           Tlc.set(sequence[z][channel3] + red, redpower[2]);
  
   

    Tlc.update();
    delay(wait);
    
    if (count >= 200){
z++;
count = 0;
}
  }
 }
  
  
  
  
  
 
 
void twoknight32(int endcount, int wait){
int direction = 1;
int direction2 = -1;

  for (int channel = 0, channel2 = 31, howmanytimes = 0; howmanytimes < endcount; channel += direction, channel2 += direction2, howmanytimes++) {
    Tlc.clear();
     if (channel == 0) {
      direction = 1;
    } 
    if (channel2 == 0) {
      direction2 = 1;
    } 
   
           Tlc.set(sequencefibi[channel] + blue, bluepower[0]);
           Tlc.set(sequencefibi[channel] + green, greenpower[0]);
           Tlc.set(sequencefibi[channel] + red, redpower[0]);
  
           Tlc.set(sequencefibi[channel2] + blue, bluepower[1]);
           Tlc.set(sequencefibi[channel2] + green, greenpower[1]);
           Tlc.set(sequencefibi[channel2] + red, redpower[1]);
  
    if (channel == 31) {
      direction = -1;
      choice1 = random(95);
      power(choice1, position[0]);
    }
    
     if (channel2 == 31) {
      direction2 = -1;
      choice2 = random(95);
      power(choice2, position[1]);
    }

    Tlc.update();
    delay(wait);
  }
}
 
 
 
 
 void knight32fade(int endcount, int wait){
     int count = 0;
   int z = 0;
 int  sequence[7][16] = {{0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15},
                          {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13,12},
                          {0,4,8,12,13,9,5,1,2,6,10,14,15,11,7,3},
                          {15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6},
                          {0,5,10,15,3,6,9,12,0,1,2,3,12,13,14,15},
                          {3,2,1,0,8,9,10,11,12,13,14,15,7,6,5,4},
                          {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};
int direction = 1;
choice1 = random(95);
      power(choice1, position[0]);
  for (int channel = 0, howmanytimes = 0; howmanytimes < endcount; channel += direction, howmanytimes++) {
    Tlc.clear();
     if (channel == 0) {
      direction = 1;
    } 
           Tlc.set(sequence[z][channel] + blue, bluepower[0]);
           Tlc.set(sequence[z][channel] + green, greenpower[0]);
           Tlc.set(sequence[z][channel] + red, redpower[0]);
           
    if ( (direction == 1) && (channel != 0 )){
     int newblue = bluepower[0] * .5;
     int newred = redpower[0] * .5;
     int newgreen = greenpower[0] * .5;
     Tlc.set(sequence[z][channel -1]  + blue, newblue);
           Tlc.set(sequence[z][channel -1]  + green, newgreen);
           Tlc.set(sequence[z][channel -1]  + red, newred);
    }
        if ( (direction == 1) && (channel > 1 )){
     int newblue1 = bluepower[0] * .3;
     int newred1 = redpower[0] * .3;
     int newgreen1 = greenpower[0] * .3;
     Tlc.set(sequence[z][channel- 2]  + blue, newblue1);
           Tlc.set(sequence[z][channel- 2]  + green, newgreen1);
           Tlc.set(sequence[z][channel- 2]  + red, newred1);
    }
       
           
               if ( (direction == -1) && (channel < 15 )){
     int newblue3 = bluepower[0] * .5;
     int newred3 = redpower[0] * .5;
     int newgreen3 = greenpower[0] * .5;
     Tlc.set(sequence[z][channel+ 1]  + blue, newblue3);
           Tlc.set(sequence[z][channel+ 1]  + green, newgreen3);
           Tlc.set(sequence[z][channel+ 1]  + red, newred3);
    }
         if ( (direction == -1) && (channel < 14 )){
     int newblue4 = bluepower[0] * .3;
     int newred4= redpower[0] * .3;
     int newgreen4 = greenpower[0] * .3;
     Tlc.set(sequence[z][channel+ 2] + blue, newblue4);
           Tlc.set(sequence[z][channel+ 2]+ green, newgreen4);
           Tlc.set(sequence[z][channel+ 2] + red, newred4);
    }
         
           
           choice1++;
      power(choice1, position[0]);     
  
    if (channel > 16) {
      direction = -1;
      
    }

    Tlc.update();
    delay(wait);
     count++;
 if (count >= 200){
 z++;
 count =0 ;
 } 
  if ( z > 7){
   z= 0;
 }
    
    
  }
}


void knight32morph(int endcount, int wait){
 int  count = 0;
 int z = 0;
  int  sequence[7][16] = {{0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15},
                          {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13,12},
                          {0,4,8,12,13,9,5,1,2,6,10,14,15,11,7,3},
                          {15,14,13,12,8,4,0,1,2,3,7,11,10,9,5,6},
                          {0,5,10,15,3,6,9,12,0,1,2,3,12,13,14,15},
                          {3,2,1,0,8,9,10,11,12,13,14,15,7,6,5,4},
                          {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};
int direction = 1;

  for (int channel = 0, howmanytimes = 0; howmanytimes < endcount; channel += direction, howmanytimes++) {
    Tlc.clear();
     if (channel == 0) {
      direction = 1;
    } 
           Tlc.set(sequence[z][channel] + blue, bluepower[0]);
           Tlc.set(sequence[z][channel] + green, greenpower[0]);
           Tlc.set(sequence[z][channel] + red, redpower[0]);
           
    if ( (direction == 1) && (channel != 0 )){
      int offset0 = channel - 1;
           Tlc.set(sequence[z][offset0] + blue, bluepower[1]);
           Tlc.set(sequence[z][offset0] + green, greenpower[1]);
           Tlc.set(sequence[z][offset0] + red, redpower[1]);
    }
        if ( (direction == 1) && (channel > 1 )){
        int offset1 = channel - 2;
           Tlc.set(sequence[z][offset1] + blue, bluepower[2]);
           Tlc.set(sequence[z][offset1]  + green, greenpower[2]);
           Tlc.set(sequence[z][offset1]  + red, redpower[2]);
    }
        if ( (direction == 1) && (channel > 2 )){  
          int offset2 = channel - 3;
           Tlc.set(sequence[z][offset2]  + blue, bluepower[3]);
           Tlc.set(sequence[z][offset2]  + green, greenpower[3]);
           Tlc.set(sequence[z][offset2]  + red, redpower[3]);
    }
           
               if ( (direction == -1) && (channel < 31 )){
                  int offset3 = channel + 1;
     Tlc.set(sequence[z][offset3]  + blue, bluepower[1]);
           Tlc.set(sequence[z][offset3] + 1 + green, greenpower[1]);
           Tlc.set(sequence[z][offset3] + 1 + red, redpower[1]);
    }
         if ( (direction == -1) && (channel < 30 )){
           int offset4 = channel + 2;
           
           Tlc.set(sequence[z][offset4] + blue, bluepower[2]);
           Tlc.set(sequence[z][offset4] + green, greenpower[2]);
           Tlc.set(sequence[z][offset4] + red, redpower[2]);
    }
         if ( (direction == -1) && (channel < 29 )){
           int offset5 = channel + 3;
           Tlc.set(sequence[z][offset5] + blue, bluepower[3]);
           Tlc.set(sequence[z][offset5] + green, greenpower[3]);
           Tlc.set(sequence[z][offset5] + red, redpower[3]);
    }
           
           
           
  
    if (channel == 15) {
      direction = -1;
      choice1 = random(84);
      power(choice1, position[0]);
      choice2 = choice1 + 4;
      power(choice2, position[1]);
      choice3 = choice1 + 7;
      power(choice3, position[2]);
      choice4 = choice1 + 11;
      power(choice4, position[3]);
      
    }

    Tlc.update();
    delay(wait);
      count++;
 if (count >= 200){
 z++;
 count =0 ;
 } 
  if ( z > 5){
   z= 0;
 }
    
    
    
    
  }
}



 
 
 void sparkle2(int endcount, int wait){

int channel = 0;
int channel2 = 6;
float mult = 0;
float mult2 = .7;
  for (int tick1 = 0, tick2 = 2, howmanytimes = 0; howmanytimes < endcount; tick1++, tick2++, howmanytimes++) {
    Tlc.clear();
    
       if ( tick1 == 0){
         float mult = .3 ;
       } else if ( tick1 == 1){
         float mult = .7;
       } else if ( tick1 == 2){
         float mult = 1;
       } else if ( tick1 == 3){
         float mult = .7;
       } else if ( tick1 == 4){
         float mult = .3;
       }
       
        if ( tick2 == 0){
         float mult2 = .3;
       } else if ( tick2 == 1){
         float mult2 = .7;
       } else if ( tick2 == 2){
         float mult2 = 1;
       } else if ( tick2 == 3){
         float mult2 = .7;
       } else if ( tick2 == 4){
         float mult2 = .3;
       }
       
          int newblue = bluepower[0] * mult;
     int newred = redpower[0] * mult;
     int newgreen = greenpower[0] * mult;
           Tlc.set(channel + blue, newblue);
           Tlc.set(channel + green, newgreen);
           Tlc.set(channel + red, newred);
       
        int newblue2 = bluepower[1] * mult2;
     int newred2 = redpower[1] * mult2;
     int newgreen2 = greenpower[1] * mult2;
           Tlc.set(channel2 + blue, newblue2);
           Tlc.set(channel2 + green, newgreen2);
           Tlc.set(channel2 + red, newred2);
       
       
       Tlc.update();
    delay(wait);
       
       if (tick1 > 4 ) {
        channel = random(0,15);
        choice1 = random(0,95);
      power(choice1, position[0]);
      tick1 = 0;
       }
        if (tick2 > 4 ) {
        channel2 = random(0,15);
        choice2 = random(0,95);
      power(choice2, position[1]);
      tick2 = 0;
       }
       
       
  }
}
 
   void innerfade(int endcount, int wait){
   
    int count = 0;
    int z = 0;
 int inner[4][4] = {{0,1,2,3},
                {4,5,6,7},
                {8,9,10,11},
           {12,13,14,15}};
     float mult = 1;
   for (int howmanytimes = 0, tick = 0; howmanytimes < endcount; howmanytimes++, tick++) {
    Tlc.clear();
            if ( z > 4){
              z = 0;
            }
            if ( tick == 6){
              tick = 0;
            }
            if ( tick == 0 ) {
               mult = 1;
            } else if (tick == 1){
              mult = .75;
            } else if (tick == 2){
               mult = .5;
            } else if (tick == 3){
              mult = .25;
            } else if (tick == 4){
               mult = 0;
            } else if (tick == 5){
              mult = 0;
              z++;
            }
    
       for (int channel1 = 0; channel1 < 4; channel1 += 1 ) {
         int newblue = mult * bluepower[0];
         int newgreen = mult * greenpower[0];
         int newred = mult * redpower[0];
           Tlc.set(inner[z][channel1] + blue, newblue);
           Tlc.set(inner[z][channel1] + green, newgreen);
           Tlc.set(inner[z][channel1] + red, newred);
           }
      
         
        choice1 += 2;
          if (choice1 > 95){
            choice1 = 0;
          }
     
      power(choice1, position[0]); 
      Tlc.update();
      delay(wait);
  
   }
   }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  void middlecolorcombo(int endcount, int wait){
   int direction = 1;
   int direction2 = -1;
   int sequence1[]={5,6,9,10};
   int sequence[]={1,0,4,8,12,13,14,15,11,7,3,2};
   for (int channel = 0, channel2 = 11, howmanytimes = 0; howmanytimes < endcount; channel++, channel2--, howmanytimes++ ) {
    Tlc.clear();
       for (int channel1 = 0; channel1 < 4; channel1++ ) {
           Tlc.set(sequence1[channel1] + blue, bluepower[0]);
           Tlc.set(sequence1[channel1] + green, greenpower[0]);
           Tlc.set(sequence1[channel1] + red, redpower[0]);
           }
      
          if (channel == 8) {
          direction = 1;
          } 
          if (channel2 == 8) {
          direction2 = 1;
          } 
 
            Tlc.set(sequence[channel] + blue, bluepower[1]);
            Tlc.set(sequence[channel] + green, greenpower[1]);
            Tlc.set(sequence[channel] + red, redpower[1]);
      
            Tlc.set(sequence[channel2] + blue, bluepower[2]);
            Tlc.set(sequence[channel2] + green, greenpower[2]);
            Tlc.set(sequence[channel2] + red, redpower[2]);

          if (channel == 11) {
          channel = 0;
          choice2 = random(95);
          power(choice2, position[1]);
          }
          
          if (channel2 == 0) {
          channel2 = 11;
          choice3 = random(95);
          power(choice3, position[2]);
          } 
          if (choice1 > 95){
            choice1 = 0;
          }
      choice1++;
      power(choice1, position[0]); 
      Tlc.update();
      delay(wait);
      }
}
void combo1(int endcount, int wait){
   int direction = 1;
   int direction2 = -1;
   choice4 = random(95);
   power(choice4,3);
   int sequence[4]={0,3,12,15};
   int sequence2[]={1,5,9,13,14,10,6,2};
   int sequence3[]={7,6,5,4,8,9,10,11};
   for (int channel = 0, channel2 = 0, howmanytimes = 0; howmanytimes < endcount; channel++, channel2++, howmanytimes++) {
    Tlc.clear();
       for (int channel1 = 0; channel1 < 4; channel1++ ) {
           Tlc.set(sequence[channel1] + blue, bluepower[0]);
           Tlc.set(sequence[channel1] + green, greenpower[0]);
           Tlc.set(sequence[channel1] + red, redpower[0]);
           }
     
      if (channel > 7) {
          channel = 0;
          channel2 =0;
          choice2 = random(0,95);
          power(choice2, position[1]);
          choice3 = random(0,95);
          power(choice3, position[2]);
          }
            
            Tlc.set(channel + blue, bluepower[1]);
            Tlc.set(channel + green, greenpower[1]);
            Tlc.set(channel + red, redpower[1]);
      
            Tlc.set(channel2 + blue, bluepower[2]);
            Tlc.set(channel2 + green, greenpower[2]);
            Tlc.set(channel2 + red, redpower[2]);
            

          
          
                choice1++;
          if (choice1 > 95){
            choice1 = 0;
          }

      power(choice1, position[0]); 
      Tlc.update();
      delay(wait);
      }
}

  void power(int choice, int position){
  switch (choice) {
    case 0:
       bluepower[position] = 4095;
       greenpower[position] = 0;
       redpower[position] = 0;
      break;
    case 1:
       bluepower[position] = 4095;
       greenpower[position] = 300;
       redpower[position] = 0;
      break;
      case 2:
       bluepower[position] = 4095;
       greenpower[position] = 600;
       redpower[position] = 0;
      break;
      case 3:
       bluepower[position] = 4095;
       greenpower[position] = 900;
       redpower[position] = 0;
      break;
      case 4:
        bluepower[position] = 4095;
       greenpower[position] = 1200;
       redpower[position] = 0;
      break;
      case 5:
      bluepower[position] = 4095;
      greenpower[position] = 1500;
      redpower[position] = 0;
      break;
      case 6:
      bluepower[position] = 4095;
      greenpower[position] = 2000;
      redpower[position] = 0;
      break;
    case 7:
       bluepower[position] = 4095;
       greenpower[position] = 2400;
       redpower[position] = 0;
      break;
      case 8:
      bluepower[position] = 4095;
      greenpower[position] = 2700;
      redpower[position] = 0;
      break;
      case 9:
        bluepower[position] = 4095;
       greenpower[position] = 2900;
       redpower[position] = 0;
      break;
      case 10:
       bluepower[position] = 4095;
       greenpower[position] = 3100;
       redpower[position] = 0;
      break;
      case 11:
       bluepower[position] = 4095;
       greenpower[position] = 3400;
       redpower[position] = 0;
      break;
      case 12:
       bluepower[position] = 4095;
       greenpower[position] = 3550;
       redpower[position] = 0;
      break;
    case 13:
       bluepower[position] = 4095;
       greenpower[position] = 3700;
       redpower[position] = 0;
      break;
      case 14:
       bluepower[position] = 4095;
       greenpower[position] = 3900;
       redpower[position] = 0;
      break;
      case 15:
       bluepower[position] = 4095;
       greenpower[position] = 4000;
       redpower[position] = 0;
      break;
      case 16:
        bluepower[position] = 4095;
       greenpower[position] = 4095;
       redpower[position] = 0;
      break;
      case 17:
      bluepower[position] = 4000;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break; 
      case 18:
      bluepower[position] = 3700;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
      case 19:
      bluepower[position] = 3500;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
    case 20:
      bluepower[position] = 3100;
      greenpower[position] = 4095;
      redpower[position] = 0;
      case 21:
      bluepower[position] = 2900;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
      case 22:
      bluepower[position] = 2600;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
      case 23:
       bluepower[position] = 2300;
       greenpower[position] = 4095;
       redpower[position] = 0;
      break;
      case 24:
      bluepower[position] = 2000;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
      case 25:
      bluepower[position] = 1700;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
      case 26:
       bluepower[position] = 1400;
       greenpower[position] = 4095;
       redpower[position] = 0;
      break;
    case 27:
      bluepower[position] = 1200;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
      case 28:
      bluepower[position] = 900;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
      case 29:
      bluepower[position] = 700;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
      case 30:
      bluepower[position] = 400;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
      case 31:
      bluepower[position] = 100;
      greenpower[position] = 4095;
      redpower[position] = 0;
      break;
          case 32:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 0;
      break;
    case 33:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 100;
      break;
      case 34:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 300;
      break;
      case 35:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 350;
      break;
      case 36:
        bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 400;
      break;
      case 37:
      bluepower[position] = 0;
      greenpower[position] = 4095;
      redpower[position] = 500;
      break;
      case 38:
      bluepower[position] = 0;
      greenpower[position] = 4095;
      redpower[position] = 600;
      break;
    case 39:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 800;
      break;
      case 40:
      bluepower[position] = 0;
      greenpower[position] = 4095;
      redpower[position] = 900;
      break;
      case 41:
        bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 1000;
      break;
      case 42:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 1100;
      break;
      case 43:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 1200;
      break;
      case 44:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 1300;
      break;
    case 45:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 1400;
      break;
      case 46:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 1500;
      break;
      case 47:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 1600;
      break;
      case 48:
       bluepower[position] = 0;
       greenpower[position] = 4095;
       redpower[position] = 1700;
      break;
      case 49:
        bluepower[position] = 0;
       greenpower[position] = 3800;
       redpower[position] = 1895;
      break;
      case 50:
      bluepower[position] = 0;
      greenpower[position] = 3500;
      redpower[position] = 1995;
      break; 
      case 51:
      bluepower[position] = 0;
      greenpower[position] = 3200;
      redpower[position] = 2095;
      break;
      case 52:
      bluepower[position] = 0;
      greenpower[position] = 2900;
      redpower[position] = 2195;
      break;
    case 53:
      bluepower[position] = 0;
      greenpower[position] = 2700;
      redpower[position] = 2295;
      case 54:
      bluepower[position] = 0;
      greenpower[position] = 2500;
      redpower[position] = 2395;
      break;
      case 55:
      bluepower[position] = 0;
      greenpower[position] = 2300;
      redpower[position] = 2595;
      break;
      case 56:
       bluepower[position] = 0;
       greenpower[position] = 2000;
       redpower[position] = 2695;
      break;
      case 57:
      bluepower[position] = 0;
      greenpower[position] = 1700;
      redpower[position] = 2895;
      break;
      case 58:
      bluepower[position] = 0;
      greenpower[position] = 1500;
      redpower[position] = 2995;
      break;
      case 59:
       bluepower[position] = 0;
       greenpower[position] = 1300;
       redpower[position] = 3195;
      break;
    case 60:
      bluepower[position] = 0;
      greenpower[position] = 1000;
      redpower[position] = 3295;
      break;
      case 61:
      bluepower[position] = 0;
      greenpower[position] = 800;
      redpower[position] = 3395;
      break;
      case 62:
      bluepower[position] = 0;
      greenpower[position] = 400;
      redpower[position] = 3495;
      break;
      case 63:
      bluepower[position] = 0;
      greenpower[position] = 200;
      redpower[position] = 3595;
      break;
      case 64:
      bluepower[position] = 0;
      greenpower[position] = 0;
      redpower[position] = 4095;
      break;
          case 65:
       bluepower[position] = 200;
       greenpower[position] = 0;
       redpower[position] = 3895;
      break;
    case 66:
       bluepower[position] = 400;
       greenpower[position] = 0;
       redpower[position] = 3795;
      break;
      case 67:
       bluepower[position] = 700;
       greenpower[position] = 0;
       redpower[position] = 3695;
      break;
      case 68:
       bluepower[position] = 900;
       greenpower[position] = 0;
       redpower[position] = 3595;
      break;
      case 69:
        bluepower[position] = 1200;
       greenpower[position] = 0;
       redpower[position] = 3495;
      break;
      case 70:
      bluepower[position] = 1500;
      greenpower[position] = 0;
      redpower[position] = 3395;
      break;
      case 71:
      bluepower[position] = 1700;
      greenpower[position] = 0;
      redpower[position] = 3295;
      break;
    case 72:
       bluepower[position] = 2000;
       greenpower[position] = 0;
       redpower[position] = 3195;
      break;
      case 73:
      bluepower[position] = 2300;
      greenpower[position] = 0;
      redpower[position] = 3095;
      break;
      case 74:
        bluepower[position] = 2600;
       greenpower[position] = 0;
       redpower[position] = 2995;
      break;
      case 75:
       bluepower[position] = 2800;
       greenpower[position] = 0;
       redpower[position] = 2895;
      break;
      case 76:
       bluepower[position] = 3000;
       greenpower[position] = 0;
       redpower[position] = 2795;
      break;
      case 77:
       bluepower[position] = 3300;
       greenpower[position] = 0;
       redpower[position] = 2695;
      break;
    case 78:
       bluepower[position] = 3600;
       greenpower[position] = 0;
       redpower[position] = 2595;
      break;
      case 79:
       bluepower[position] = 3900;
       greenpower[position] = 0;
       redpower[position] = 2495;
      break;
      case 80:
       bluepower[position] = 4095;
       greenpower[position] = 0;
       redpower[position] = 2395;
      break;
      case 81:
        bluepower[position] = 4095;
       greenpower[position] = 0;
       redpower[position] = 2200;
      break;
      case 82:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 2100;
      break; 
      case 83:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 2000;
      break;
      case 84:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 1900;
      break;
    case 85:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 1800;
      case 86:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 1700;
      break;
      case 87:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 1600;
      break;
      case 88:
       bluepower[position] = 4095;
       greenpower[position] = 0;
       redpower[position] = 1500;
      break;
      case 89:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 1400;
      break;
      case 90:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 1300;
      break;
      case 91:
       bluepower[position] = 4095;
       greenpower[position] = 0;
       redpower[position] = 1200;
      break;
    case 92:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 1100;
      break;
      case 93:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 800;
      break;
      case 94:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 400;
      break;
      case 95:
      bluepower[position] = 4095;
      greenpower[position] = 0;
      redpower[position] = 200;
      break;
   
  }
   }

