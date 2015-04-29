#include <MeggyJrSimple.h>

int mountains[] = {4, 5, 6, 5, 6, 5, 4, 3};
int PlayerY = 7;
int PlayerX;
int counter = 0;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop() {
 if (counter < 1000) counter++;
 else counter = 0;

 drawMountains(); //Draw the array
 DisplaySlate();
 delay(200);
 ClearSlate();
 DrawPx(1,PlayerY,5);
 
 if (counter%50 == 0)
  updateMountains(); //Update array

 CheckButtonsPress();

  if(Button_Up) { //Move Player Up
   if(PlayerY < 7)
    PlayerY++;
     Tone_Start(18182, 50);
   }
 
  if(Button_Down) { //Move Player Down
   if(PlayerY > 0)
    PlayerY--;
     Tone_Start(18182, 50);
   }
 
}

void updateMountains() {
 for(int i = 0; i < 7; i++) {
   mountains[i]=mountains[i+1];
 }
 
 if(random(3)==0)
 {
  if(mountains[7] < 7)
   mountains[7]+=2;
 }
 else {
  if(mountains[7] > 0)
   mountains[7]-=1;
 }
 
}

void drawMountains() {
  for(int i = 0; i < 8; i++) //iterate through the array (0 through 7)
   for(int j = 0; j < mountains[i]; j++) //iterate the number of times specified by the value at i
    DrawPx(i,j,2);
}

boolean collide() {
  if(PlayerY < mountains[PlayerX]) //if the player position matches an obstacle position
   return true; //return true
  else return false;//otherwise return false
}
  
