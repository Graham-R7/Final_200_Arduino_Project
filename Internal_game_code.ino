#include <TFT_eSPI.h>

//create the screen variable from the library
TFT_eSPI tft = TFT_eSPI();

// Set up variables.
float posX = 240.0;
float posY = 160.0;
int resetCount = 0;
int buttonCount = 0;
bool GameRun = false;
bool GamePaused = false;
bool GameOnMenu = false;
bool SelectedMenu = false;
bool GameOnCutscene = false;
int level = 0;
int MenuPos = 0;
int CutscenePos = 0;
bool U_collision = false;
bool D_collision = false;
bool L_collision = false;
bool R_collision = false;
int i;
int button_A;
int counter = 100;
int scoreG = 100;
int scoreY = 0;
int scoreO = 0;
int scoreR = 0;
int scoreB = 0;
int timerRound = 1;
int obscureCounter = 0;
int soupX = 200;
int soupY = 220;

int wall_1_1[4]={0,66,140,20};int wall_1_2[4]={44,22,260,20};int wall_1_3[4]={55,55,200,20};int wall_1_4[4]={110,22,160,80};int wall_1_5[4]={132,88,220,20};
int wall_1_6[4]={198,22,240,40};int wall_1_7[4]={198,22,190,30};int wall_1_8[4]={110,33,140,20};int wall_1_9[4]={143,22,100,60};int wall_1_10[4]={66,99,80,20};
int wall_1_11[4]={209,22,40,100};int wall_1_12[4]={286,22,40,140};int wall_1_13[4]={264,22,160,80};int wall_1_14[4]={286,160,220,20};int wall_1_15[4]={352,22,100,80};
int wall_1_16[4]={352,95,80,20};int wall_1_17[4]={374,66,140,20};int wall_1_18[4]={440,40,140,20};int wall_1_19[4]={231,10,80,20};int wall_1_20[4]={414,32,200,20};
int wall_1_21[4]={337,15,130,30};int wall_1_22[4]={0,36,70,20};

int wall_2_1[4]={0,70,80,20}; int wall_2_2[4]={115,20,250,30};int wall_2_3[4]={55,60,250,20};int wall_2_4[4]={55,20,140,110};
int wall_2_5[4]={75,60,140,20};int wall_2_6[4]={115,20,80,60};int wall_2_7[4]={135,50,80,20};int wall_2_8[4]={165,20,100,40};
int wall_2_9[4]={115,120,200,10};int wall_2_10[4]={170,20,210,30};int wall_2_11[4]={215,20,40,160};int wall_2_12[4]={235,80,185,15};
int wall_2_13[4]={235,40,130,20};int wall_2_14[4]={275,110,130,20};int wall_2_15[4]={305,20,80,50};int wall_2_16[4]={275,30,80,15};
int wall_2_17[4]={365,80,70,20};int wall_2_18[4]={355,20,150,90};int wall_2_19[4]={275,40,240,20};int wall_2_20[4]={295,20,260,20};
int wall_2_21[4]={225,20,250,30};int wall_2_22[4]={375,70,190,20};int wall_2_23[4]={420,60,130,20};int wall_2_24[4]={385,20,40,30};
int wall_2_25[4]={430,50,250,30};

int wall_3_1[4]={0,110,160,20};int wall_3_2[4]={90,20,140,20};int wall_3_3[4]={40,20,80,40};int wall_3_4[4]={60,100,80,20};int wall_3_5[4]={140,20,100,140};
int wall_3_6[4]={40,100,220,20};int wall_3_7[4]={220,20,240,40};int wall_3_8[4]={200,140,220,20};int wall_3_9[4]={340,10,200,40};int wall_3_10[4]={320,20,180,40};
int wall_3_11[4]={200,140,160,20};int wall_3_12[4]={310,30,140,20};int wall_3_13[4]={160,120,100,20};int wall_3_14[4]={200,20,40,20};int wall_3_15[4]={260,140,80,20};
int wall_3_16[4]={380,20,100,60};int wall_3_17[4]={380,60,160,20};int wall_3_18[4]={390,20,180,100};int wall_3_19[4]={450,30,220,20};int wall_3_20[4]={440,40,80,20};

int wall_4_1[4]={0,70,160,20};int wall_4_2[4]={70,20,140,100};int wall_4_3[4]={120,70,220,20};int wall_4_4[4]={120,20,100,120};int wall_4_5[4]={50,90,80,20};
int wall_4_6[4]={180,20,80,40};int wall_4_7[4]={200,40,80,20};int wall_4_8[4]={220,20,40,40};int wall_4_9[4]={140,120,160,20};int wall_4_10[4]={240,50,140,20};
int wall_4_11[4]={270,20,80,60};int wall_4_12[4]={290,160,80,20};int wall_4_13[4]={430,20,100,140};int wall_4_14[4]={380,20,140,140};int wall_4_15[4]={330,20,100,120};
int wall_4_16[4]={290,40,200,20};int wall_4_17[4]={230,80,220,20};int wall_4_18[4]={230,20,240,40};int wall_4_19[4]={340,40,260,20};

int wallCollision = 1;

// Setting the joystick pins here so we can easily change them
#define JOYSTICK_X_PIN A14
#define JOYSTICK_Y_PIN A15
#define JOYSTICK_BUTTON_PIN 34
#define BUTTON_A_PIN 41

// Define colours in 4-digit hex 
// RGB565 Format   
// https://github.com/newdigate/rgb565_colors               
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define ORANGE 0xFC60
#define GREEN1 0x4C88
#define GREEN2 0x2444
#define GREEN3 0x7DAC
#define GREEN4 0x4AE4
#define FLOWERBUD 0xDD24
#define MIDDLE 0x80A3
#define PETAL2 0xFFDD
#define PETAL3 0xC9B9
#define PETAL4 0x86DD
#define GRASS 0x1AC1
#define PETAL5 0xFA80
#define PETAL6 0xF3F7

#define CAVE1 0x530D
#define CAVE2 0x0208
#define CAVE3 0x52AA
#define CAVE4 0x534F
#define ROCK 	0x29A7
#define ROCKSHADE 0xBDF7
#define ASHGREY 0xB5F6
#define TOPSHADE1 0x9FFF
#define TOPSHADE2 0x4379
#define CARROTSTEM 0x0347
#define GEM1 0x07FD
#define GEM2 0x4C7C
#define GEM3 0x3256
#define ROCK1 	0x940F
#define ROCKSHADE1 0xBD76
#define GEMSPECS2 0xF7BF
#define ROCK2	0x49E6

#define MYSTIC1 0xB437
#define MYSTIC2 0x818F
#define MYSTIC3 0x8311
#define MYSTIC4 0xCB95
#define CRYSTAL1 0xE1EC
#define CRYSTAL2 0xC9AE
#define CRYSTAL3 	0xFA69
#define CRYSTAL4 0x598A
#define CRYSTAL5 0xF812
#define CRYSTAL6 0x6007
#define MUSHROOMSTEM 	0xF735
#define MUSHROOM 	0x23BF
#define MUSHROOMDOT 0x07FF
#define MUSHROOM1 0x05FF
#define MUSHROOMDOT1 0x0410
#define PLANTSTEM 	0x0400
#define PLANT 0xD990
#define PLANT1 0xF73E
#define CHICKEN1 0xCC28
#define CHICKEN2 0x9B23
#define CHICKEN3 0x8307
#define BONE1 0x9470
#define BONE2 0xE71B
#define TOPROCKS 0x4ACC

#define LAVA1 0xF840
#define LAVA2 0x8800
#define LAVA3 0xE8E4
#define LAVA4 0xFB44
#define NOODLES 0xF5E4
#define NOODLES1 0xF6EF
#define BOWL 0xF7BE
#define BOWL1 0x8DDD
#define STONE1 0x940F
#define STONE2 0x52AA
#define STONE3 0x94D2
#define PIXEL4STONE1 0xFAA9
#define PIXEL4STONE2 	0xBA8A
#define POOLBED 0x3860
#define POOL1 0xD9E5
#define POOL2 0xFCE0
#define POOL3 0xF6AD
#define VOLCANO1 0xB8A1
#define VOLCANO2 0xFC00
#define R2MED 0x8C31
#define R2MED1 0x8410
#define DRAGONBODY 0x47E0
#define DRAGONNOSE 0x3D8E
#define DRAGONWINGS 0x3666
#define DRAGONHIGHLIGHT 0x9772
#define DRAGONLEGS 0x32E7
#define DRAGONBLUE1 0x761F
#define DRAGONBLUE2 0x2272
#define FIRE1	0x9003
#define FIRE2 0xFB44
#define FIRE3 0xFD68
#define FIRE4 0xFEE0

#define SOUPB 0xAEDE
#define SOUPBSHADE 0x7517
#define SOUPBLIGHT 0xEFBF
#define TOMATO 	0xD9E6
#define CARROT 	0xFBA3
#define CHICKENCOOKED 0xCC28
#define CHICKENGRILL 0x9383



int background = BLACK;
int characterColour = WHITE;

// Set up functions and lists.
int createMenu(int(type)){
  if (type == 0){
    tft.fillScreen(0x000B);
    tft.setTextColor(0xAD55);
    tft.setTextSize(5);
    tft.drawString("Untitled", 120, 30);
    tft.drawString("Cat Game!", 110, 90);
    tft.fillRoundRect(140, 170, 200, 60, 15, 0x4228);
    tft.fillRoundRect(110, 250, 120, 40, 15, 0x4228);
    tft.fillRoundRect(250, 250, 120, 40, 15, 0x4228);
    counter = 100;
    scoreG = 100;
    scoreY = 0;
    scoreO = 0;
    scoreR = 0;
    scoreB = 0;
    timerRound = 1;
    obscureCounter = 0;
  }
  else if (type == 1){
    tft.fillScreen(0xE38F);
    tft.fillRect(0, 0, 480, 20, 0xFC08);
    tft.fillRect(0, 0, 20, 320, 0xFC08);
    tft.fillRect(460, 0, 20, 360, 0xFC08);
    tft.fillRect(0, 300, 480, 20, 0xFC08);
    tft.fillRect(40, 180, 60, 80, 0xFC08);
    tft.fillRect(125, 180, 60, 80, 0xFC08);
    tft.fillRect(210, 180, 60, 80, 0xFC08);
    tft.fillRect(295, 180, 60, 80, 0xFC08);
    tft.fillRect(380, 180, 60, 80, 0xFC08);
    tft.drawRect(40, 180, 60, 80, BLACK);
    tft.drawRect(125, 180, 60, 80, BLACK);
    tft.drawRect(210, 180, 60, 80, BLACK);
    tft.drawRect(295, 180, 60, 80, BLACK);
    tft.drawRect(380, 180, 60, 80, BLACK);
    tft.setTextColor(0xB8A1);
    tft.setTextSize(7);
    tft.drawString("PAUSED", 120, 40);
    tft.setTextColor(0x71B0);
    tft.setTextSize(2);
    tft.drawString("Where would you like to go?:", 80, 120);
    tft.setTextColor(BLACK);
    tft.setTextSize(6);
    tft.drawString("M", 55, 203);
    tft.drawString("1", 140, 203);
    tft.drawString("2", 225, 203);
    tft.drawString("3", 310, 203);
    tft.drawString("4", 395, 203);
  }
  else if (type == 2){
    tft.fillScreen(CYAN);
    tft.fillRect(0, 160, 480, 160, GREEN2);
    tft.setTextSize(5);
    tft.drawString("Yay you did it!", 20, 20);
    //Main Cat
    characterColour = WHITE;
    tft.fillRect(int(150-22), int(200-22), 44, 44, characterColour);
    tft.fillRect(int(150-16), int(200-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(150+6), int(200-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(150-2), int(200+6), 4, 4, MAGENTA); //CUSTOMIZATION NOSE
    tft.fillRect(int(150-14), int(200-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.fillRect(int(150+8), int(200-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.drawFastHLine(int(150-10), int(200+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawFastHLine(int(150+4), int(200+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawPixel(int(150-12), int(200+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(150+10), int(200+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(150-4), int(200+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(150+2), int(200+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.fillTriangle(int(150-22), int(200-24), int(150-12), int(200-34),int(150-2), int(200-24), characterColour);
    tft.fillTriangle(int(150), int(200-24), int(150+10), int(200-34),int(150+20), int(200-24), characterColour);
    tft.fillTriangle(int(150-16), int(200-24), int(150-12), int(200-28),int(150-8), int(200-24), MAGENTA); //CUSTOMIZATION EAR
    tft.fillTriangle(int(150+6), int(200-24), int(150+10), int(200-28),int(150+14), int(200-24), MAGENTA); //CUSTOMIZATION EAR
    //Friend Cat #1 Brown
    characterColour = 0x7A00;
    tft.fillRect(int(50-22), int(240-22), 44, 44, characterColour);
    tft.fillRect(int(50-16), int(240-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(50+6), int(240-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(50-2), int(240+6), 4, 4, MAGENTA); //CUSTOMIZATION NOSE
    tft.fillRect(int(50-14), int(240-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.fillRect(int(50+8), int(240-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.drawFastHLine(int(50-10), int(240+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawFastHLine(int(50+4), int(240+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawPixel(int(50-12), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(50+10), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(50-4), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(50+2), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.fillTriangle(int(50-22), int(240-24), int(50-12), int(240-34),int(50-2), int(240-24), characterColour);
    tft.fillTriangle(int(50), int(240-24), int(50+10), int(240-34),int(50+20), int(240-24), characterColour);
    tft.fillTriangle(int(50-16), int(240-24), int(50-12), int(240-28),int(50-8), int(240-24), MAGENTA); //CUSTOMIZATION EAR
    tft.fillTriangle(int(50+6), int(240-24), int(50+10), int(240-28),int(50+14), int(240-24), MAGENTA); //CUSTOMIZATION EAR
    //Friend Cat #2 Orange
    characterColour = 0xFCCC;
    tft.fillRect(int(330-22), int(200-22), 44, 44, characterColour);
    tft.fillRect(int(330-16), int(200-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(330+6), int(200-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(330-2), int(200+6), 4, 4, MAGENTA); //CUSTOMIZATION NOSE
    tft.fillRect(int(330-14), int(200-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.fillRect(int(330+8), int(200-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.drawFastHLine(int(330-10), int(200+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawFastHLine(int(330+4), int(200+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawPixel(int(330-12), int(200+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(330+10), int(200+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(330-4), int(200+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(330+2), int(200+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.fillTriangle(int(330-22), int(200-24), int(330-12), int(200-34),int(330-2), int(200-24), characterColour);
    tft.fillTriangle(int(330), int(200-24), int(330+10), int(200-34),int(330+20), int(200-24), characterColour);
    tft.fillTriangle(int(330-16), int(200-24), int(330-12), int(200-28),int(330-8), int(200-24), MAGENTA); //CUSTOMIZATION EAR
    tft.fillTriangle(int(330+6), int(200-24), int(330+10), int(200-28),int(330+14), int(200-24), MAGENTA); //CUSTOMIZATION EAR
    //Friend Cat #3 Gray
    characterColour = ASHGREY;
    tft.fillRect(int(430-22), int(240-22), 44, 44, characterColour);
    tft.fillRect(int(430-16), int(240-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(430+6), int(240-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(430-2), int(240+6), 4, 4, MAGENTA); //CUSTOMIZATION NOSE
    tft.fillRect(int(430-14), int(240-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.fillRect(int(430+8), int(240-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.drawFastHLine(int(430-10), int(240+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawFastHLine(int(430+4), int(240+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawPixel(int(430-12), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(430+10), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(430-4), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(430+2), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.fillTriangle(int(430-22), int(240-24), int(430-12), int(240-34),int(430-2), int(240-24), characterColour);
    tft.fillTriangle(int(430), int(240-24), int(430+10), int(240-34),int(430+20), int(240-24), characterColour);
    tft.fillTriangle(int(430-16), int(240-24), int(430-12), int(240-28),int(430-8), int(240-24), MAGENTA); //CUSTOMIZATION EAR
    tft.fillTriangle(int(430+6), int(240-24), int(430+10), int(240-28),int(430+14), int(240-24), MAGENTA); //CUSTOMIZATION EAR
    //soup bowl
    tft.fillRect(int(soupX+20),int(soupY-8),56,36, NOODLES);
    tft.fillRect(int(soupX+8),int(soupY),12,12, NOODLES);
    tft.fillRect(int(soupX+76),int(soupY),12,16, NOODLES);
    tft.fillRect(int(soupX),int(soupY),4,20, BLACK);
    tft.fillRect(int(soupX+4),int(soupY-4),8,4, BLACK);
    tft.fillRect(int(soupX+12),int(soupY-8),8,4, BLACK);
    tft.fillRect(int(soupX+20),int(soupY-12),12,4, BLACK);
    tft.fillRect(int(soupX+32),int(soupY-16),32,4, BLACK);
    tft.fillRect(int(soupX+64),int(soupY-12),12,4, BLACK);
    tft.fillRect(int(soupX+76),int(soupY-8),8,4, BLACK);
    tft.fillRect(int(soupX+84),int(soupY-4),8,4, BLACK);
    tft.fillRect(int(soupX+92),int(soupY),4,20, BLACK);
    tft.fillRect(int(soupX+4),int(soupY+20),4,8, BLACK);
    tft.fillRect(int(soupX+8),int(soupY+28),4,4, BLACK);
    tft.fillRect(int(soupX+12),int(soupY+32),8,4, BLACK);
    tft.fillRect(int(soupX+20),int(soupY+36),4,4, BLACK);
    tft.fillRect(int(soupX+24),int(soupY+40),48,4, BLACK);
    tft.fillRect(int(soupX+72),int(soupY+36),4,4, BLACK);
    tft.fillRect(int(soupX+76),int(soupY+32),8,4, BLACK);
    tft.fillRect(int(soupX+84),int(soupY+28),4,4, BLACK);
    tft.fillRect(int(soupX+88),int(soupY+20),4,8, BLACK);
    tft.fillRect(int(soupX+4),int(soupY),4,20, SOUPB);
    tft.fillRect(int(soupX+8),int(soupY),8,4, SOUPB);  
    tft.fillRect(int(soupX+12),int(soupY-4),12,4, SOUPB);  
    tft.fillRect(int(soupX+20),int(soupY-8),12,4, SOUPB);
    tft.fillRect(int(soupX+32),int(soupY-12),32,4, SOUPB);
    tft.fillRect(int(soupX+64),int(soupY-8),12,4, SOUPB);
    tft.fillRect(int(soupX+72),int(soupY-4),12,4, SOUPB);
    tft.fillRect(int(soupX+80),int(soupY),8,4, SOUPB);
    tft.fillRect(int(soupX+88),int(soupY),4,20, SOUPB);
    tft.fillRect(int(soupX+12),int(soupY+8),4,4, NOODLES1);
    tft.fillRect(int(soupX+8),int(soupY+12),8,4, NOODLES1);
    tft.fillRect(int(soupX+8),int(soupY+16),8,4, SOUPBLIGHT);
    tft.fillRect(int(soupX+8),int(soupY+20),16,8, SOUPB);
    tft.fillRect(int(soupX+12),int(soupY+28),24,4, SOUPB);
    tft.fillRect(int(soupX+16),int(soupY+20),8,4, SOUPBLIGHT);
    tft.fillRect(int(soupX+24),int(soupY+24),12,4, SOUPBLIGHT);
    tft.fillRect(int(soupX+24),int(soupY+32),48,4, SOUPB);
    tft.fillRect(int(soupX+20),int(soupY+32),4,4, SOUPBSHADE);
    tft.fillRect(int(soupX+24),int(soupY+36),48,4, SOUPBSHADE);
    tft.fillRect(int(soupX+72),int(soupY+32),4,4, SOUPBSHADE);
    tft.fillRect(int(soupX+36),int(soupY+28),24,4, SOUPBLIGHT);
    tft.fillRect(int(soupX+60),int(soupY+28),20,4, SOUPB);  
    tft.fillRect(int(soupX+60),int(soupY+24),12,4, SOUPBLIGHT); 
    tft.fillRect(int(soupX+80),int(soupY+28),4,4, SOUPBSHADE);  
    tft.fillRect(int(soupX+84),int(soupY+24),4,4, SOUPBSHADE); 
    tft.fillRect(int(soupX+36),int(soupY+24),12,4, NOODLES1); 
    tft.fillRect(int(soupX+72),int(soupY+24),12,4, SOUPB); 
    tft.fillRect(int(soupX+40),int(soupY+20),12,4, NOODLES1);
    tft.fillRect(int(soupX+52),int(soupY+20),8,4, TOMATO);
    tft.fillRect(int(soupX+72),int(soupY+20),16,4, SOUPBLIGHT);
    tft.fillRect(int(soupX+16),int(soupY+16),4,4, NOODLES);
    tft.fillRect(int(soupX+20),int(soupY+8),24,8, CHICKENCOOKED);
    tft.fillRect(int(soupX+32),int(soupY-8),12,12, CHICKENCOOKED);
    tft.fillRect(int(soupX+24),int(soupY+16),16,4, CHICKENCOOKED);
    tft.fillRect(int(soupX+32),int(soupY+16),4,4, CHICKENGRILL);
    tft.fillRect(int(soupX+44),int(soupY+16),4,4, NOODLES1);
    tft.fillRect(int(soupX+48),int(soupY+16),16,4, TOMATO);
    tft.fillRect(int(soupX+72),int(soupY+16),8,4, NOODLES1);
    tft.fillRect(int(soupX+80),int(soupY+16),8,4, SOUPBLIGHT);
    tft.fillRect(int(soupX+16),int(soupY+12),4,4, CHICKENCOOKED);
    tft.fillRect(int(soupX+24),int(soupY+12),4,4, CHICKENGRILL);
    tft.fillRect(int(soupX+36),int(soupY+12),4,4, CHICKENGRILL);
    tft.fillRect(int(soupX+48),int(soupY+12),8,4, TOMATO);
    tft.fillRect(int(soupX+60),int(soupY+12),12,4, NOODLES1);
    tft.fillRect(int(soupX+16),int(soupY+4),4,8, TOMATO);
    tft.fillRect(int(soupX+28),int(soupY+8),4,4, CHICKENGRILL);
    tft.fillRect(int(soupX+40),int(soupY+8),4,4, CHICKENGRILL);
    tft.fillRect(int(soupX+44),int(soupY+8),8,4, NOODLES1);
    tft.fillRect(int(soupX+72),int(soupY+8),4,4, NOODLES1);
    tft.fillRect(int(soupX+76),int(soupY+8),8,4, CARROT);
    tft.fillRect(int(soupX+20),int(soupY+4),4,4, NOODLES1);
    tft.fillRect(int(soupX+24),int(soupY+4),8,4, CHICKENCOOKED);
    tft.fillRect(int(soupX+36),int(soupY+4),12,4, CHICKENCOOKED);
    tft.fillRect(int(soupX+40),int(soupY+4),4,4, CHICKENGRILL);   
    tft.fillRect(int(soupX+60),int(soupY+4),8,4, CARROT);
    tft.fillRect(int(soupX+68),int(soupY+4),8,4, NOODLES1); 
    tft.fillRect(int(soupX+80),int(soupY+4),4,4,CARROT);
    tft.fillRect(int(soupX+32),int(soupY),4,4, CHICKENGRILL);
    tft.fillRect(int(soupX+44),int(soupY),4,4, CHICKENGRILL);
    tft.fillRect(int(soupX+48),int(soupY),4,4, CHICKENCOOKED);
    tft.fillRect(int(soupX+56),int(soupY),16,4, CARROT);
    tft.fillRect(int(soupX+24),int(soupY-4),8,4, NOODLES1);
    tft.fillRect(int(soupX+36),int(soupY-4),4,4, CHICKENGRILL);
    tft.fillRect(int(soupX+44),int(soupY-4),4,4, CHICKENCOOKED);
    tft.fillRect(int(soupX+48),int(soupY-4),4,4, CHICKENGRILL);
    tft.fillRect(int(soupX+52),int(soupY-4),4,4, NOODLES1);
    tft.fillRect(int(soupX+56),int(soupY-4),8,4, CARROT);
    tft.fillRect(int(soupX+40),int(soupY-8),4,4, CHICKENGRILL);
    tft.fillRect(int(soupX+48),int(soupY-8),16,4, NOODLES1);

  }
  else if (type == 3){
    tft.fillScreen(BLACK);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.drawString("How to play:", 70, 10);
    tft.setTextSize(2);
    tft.drawString("Press \"A\" to return to continue", 60, 300);
    tft.setTextSize(2);
    tft.setTextColor(0xAD55);
    tft.drawString("You are Soup Cat", 140, 60);
    tft.drawString("Move Joystick to move Soup Cat", 60, 90);
    tft.drawString("Walls stop Soup Cat from moving", 55, 120);
    tft.drawString("Push Joystick button down", 90, 150);
    tft.drawString("to pause the game", 140, 180);
    tft.drawString("Press \"A\" button to select things", 40, 210);
    tft.drawString("There are four levels and your goal", 30, 240);
    tft.drawString("is to collect an ingredient in each maze", 0, 270);
  }
  else if (type == 4){
    tft.fillScreen(BLACK);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.drawString("Chloe Choi", 10, 80);
    tft.drawString("Siya Chokshi", 10, 120);
    tft.drawString("Vivian Breton", 10, 160);
    tft.drawString("Ryan Graham", 10, 200);
  }
  else if (type == 5){
    tft.fillScreen(BLACK);
    tft.setTextColor(RED);
    tft.setTextSize(8);
    tft.drawString("GAME", 160, 70);
    tft.drawString("OVER", 160, 150);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.drawString("Press \"A\" to return to Main Menu", 50, 260);
    counter = 100;
    scoreG = 100;
    scoreY = 0;
    scoreO = 0;
    scoreR = 0;
    scoreB = 0;
    timerRound = 1;
    obscureCounter = 0;
  }
  else if (type == 6){
    tft.fillScreen(BLACK);
    tft.setTextColor(WHITE);
    tft.setTextSize(5);
    tft.drawString("How to play:", 70, 10);
    tft.setTextSize(2);
    tft.drawString("Press \"A\" to return to Menu", 75, 300);
    tft.setTextColor(0xAD55);
    tft.drawString("When playing there will be a timer in", 20, 65);
    tft.drawString("the bottom right corner which will drop", 5, 85);
    tft.drawString("This timer has five bars that will each", 5, 105);
    tft.drawString("drop faster than the previous one", 40, 125);
    tft.drawString("Green, yellow, orange, red and black", 25, 145);
    tft.drawString("IF THE TIMER TURNS FULLY BLACK, YOU LOSE", 0, 175);
    tft.drawString("But be careful, the walls are sticky!", 20, 205);
    tft.drawString("When you stop moving, time moves faster", 5, 225);
    tft.drawString("Beat the game through all 4 levels", 30, 245);
    tft.drawString("before the timer fully ends to win!", 30, 265);
  }
}
int flowersHA(int(wall[4])){
  tft.fillRect(wall[0]+7,wall[2]+4,2,3,PETAL3); //type 1 petal
  tft.fillRect(wall[0]+9,wall[2]+4,5,5,FLOWERBUD); //type 1 bud
  tft.drawPixel(wall[0]+11,wall[2]+6,MIDDLE); // type 1 middle
  tft.fillRect(wall[0]+9,wall[2]+9,3,2,PETAL3); // type 1 petal
  tft.fillRect(wall[0]+14,wall[2]+6,2,3,PETAL3); //type 1 petal
  tft.fillRect(wall[0]+11,wall[2]+2,3,2,PETAL3); //type 1 petal

  tft.fillRect(wall[0]+20,wall[2]+10,2,2,PETAL3); //type 2 petal
  tft.fillRect(wall[0]+20,wall[2]+12,2,2,FLOWERBUD); //type 2 bud
  tft.fillRect(wall[0]+22,wall[2]+12,2,2,PETAL3); //type 2 petal

  tft.fillRect(wall[0]+25,wall[2]+5,2,2,PETAL4); //type 3 petal
  tft.fillRect(wall[0]+27,wall[2]+3,2,2,PETAL4); //type 3 petal
  tft.fillRect(wall[0]+27,wall[2]+5,2,2,FLOWERBUD); //type 3 bud
  tft.fillRect(wall[0]+27,wall[2]+7,2,2,PETAL4); //type 3 petal
  tft.fillRect(wall[0]+29,wall[2]+5,2,2,PETAL4); //type 3 petal
 }
int flowersHB(int(wall[4])){
  tft.fillRect(wall[0]+10,wall[2]+14,2,2,GRASS); //type 4
  tft.fillRect(wall[0]+12,wall[2]+16,2,2,GRASS); //type 4
  tft.fillRect(wall[0]+14,wall[2]+14,2,2,GRASS); //type 4

  tft.fillRect(wall[0]+28,wall[2]+4,2,3,PETAL2); //type 1 petal
  tft.fillRect(wall[0]+30,wall[2]+4,5,5,FLOWERBUD); //type 1 bud
  tft.drawPixel(wall[0]+32,wall[2]+6,MIDDLE); //type 1 middle
  tft.fillRect(wall[0]+30,wall[2]+9,3,2,PETAL2); //type 1 petal
  tft.fillRect(wall[0]+35,wall[2]+6,2,3,PETAL2); //type 1 petal
  tft.fillRect(wall[0]+32,wall[2]+2,3,2,PETAL2); //type 1 petal

  tft.fillRect(wall[0]+47,wall[2]+6,2,2,PETAL2); //type 3 petal
  tft.fillRect(wall[0]+49,wall[2]+4,2,2,PETAL2); //type 3 petal
  tft.fillRect(wall[0]+49,wall[2]+6,2,2,FLOWERBUD); //type 3 bud
  tft.fillRect(wall[0]+49,wall[2]+8,2,2,PETAL2); //type 3 petal
  tft.fillRect(wall[0]+51,wall[2]+6,2,2,PETAL2); //type 3 petal
 }
int flowersHC(int(wall[4])){ 
  tft.fillRect(wall[0]+18,wall[2]+6,2,2,GRASS); //type 4
  tft.fillRect(wall[0]+20,wall[2]+8,2,2,GRASS); //type 4
  tft.fillRect(wall[0]+22,wall[2]+6,2,2,GRASS); //type 4

  tft.fillRect(wall[0]+36,wall[2]+9,2,2,GRASS); //type 4
  tft.fillRect(wall[0]+38,wall[2]+11,2,2,GRASS); //type 4
  tft.fillRect(wall[0]+40,wall[2]+9,2,2,GRASS); //type 4

  tft.fillRect(wall[0]+54,wall[2]+10,2,2,PETAL5); //type 3 petal
  tft.fillRect(wall[0]+56,wall[2]+8,2,2,PETAL5); //type 3 petal
  tft.fillRect(wall[0]+56,wall[2]+10,2,2,FLOWERBUD); //type 3 bud
  tft.fillRect(wall[0]+56,wall[2]+12,2,2,PETAL5); //type 3 petal
  tft.fillRect(wall[0]+58,wall[2]+10,2,2,PETAL5); //type 3 petal  
  
  tft.fillRect(wall[0]+60,wall[2]+7,2,2,PETAL5); //type 3 petal
  tft.fillRect(wall[0]+62,wall[2]+5,2,2,PETAL5); //type 3 petal
  tft.fillRect(wall[0]+62,wall[2]+7,2,2,FLOWERBUD); //type 3 bud
  tft.fillRect(wall[0]+62,wall[2]+9,2,2,PETAL5); //type 3 petal
  tft.fillRect(wall[0]+64,wall[2]+7,2,2,PETAL5); //type 3 petal  
  
  tft.fillRect(wall[0]+82,wall[2]+12,2,2,PETAL6); //type 2 petal
  tft.fillRect(wall[0]+82,wall[2]+14,2,2,FLOWERBUD); //type 2 bud
  tft.fillRect(wall[0]+84,wall[2]+14,2,2,PETAL6); //type 2 petal
  }
int graphic2VA(int(wall[4])){
  tft.fillRect(wall[0]+3,wall[2]+15,2,4,ROCKSHADE); //R-1
  tft.fillRect(wall[0]+8,wall[2]+8,1,5,ROCKSHADE); // R-2
  tft.fillRect(wall[0]+9,wall[2]+8,4,2,ROCKSHADE); //R-3
  tft.fillRect(wall[0]+9,wall[2]+10,4,3,ROCK); //R-4
  tft.fillRect(wall[0]+6,wall[2]+12,2,2,ROCKSHADE); //R-5
  tft.fillRect(wall[0]+8,wall[2]+13,6,1,ROCK); //R-6
  tft.fillRect(wall[0]+5,wall[2]+14,2,2,ROCKSHADE); //R-7
  tft.fillRect(wall[0]+7,wall[2]+14,7,2,ROCK); //R-8
  tft.fillRect(wall[0]+7,wall[2]+9,1,3,ROCKSHADE); //R-9
  tft.fillRect(wall[0]+5,wall[2]+16,11,3,ROCK); //R-10

  tft.fillRoundRect(wall[0]+6, wall[2]+48, 7, 5, 1, GEM1);//G-1
  tft.fillTriangle(wall[0]+6,wall[2]+49,wall[0]+9, wall[2]+44, wall[0]+12, wall[2]+49,GEM1);//G-2
  tft.fillRect(wall[0]+5, wall[2]+52,4,2, GEM3);//G-3
  tft.fillRoundRect(wall[0]+11, wall[2]+50,4,3, 1, GEM2);//G-4
  tft.fillRect(wall[0]+10,wall[2]+47,2,2,GEMSPECS2); // G-5

  tft.fillRect(wall[0]+5,wall[2]+84,2,4,ROCKSHADE1); //R-1
  tft.fillRect(wall[0]+10,wall[2]+77,1,5,ROCKSHADE1); // R-2
  tft.fillRect(wall[0]+11,wall[2]+77,4,2,ROCKSHADE1); //R-3
  tft.fillRect(wall[0]+11,wall[2]+79,4,3,ROCK1); //R-4
  tft.fillRect(wall[0]+8,wall[2]+81,2,2,ROCKSHADE1); //R-5
  tft.fillRect(wall[0]+10,wall[2]+82,6,1,ROCK1); //R-6
  tft.fillRect(wall[0]+7,wall[2]+83,2,2,ROCKSHADE1); //R-7
  tft.fillRect(wall[0]+9,wall[2]+83,7,2,ROCK1); //R-8
  tft.fillRect(wall[0]+9,wall[2]+78,1,3,ROCKSHADE1); //R-9
  tft.fillRect(wall[0]+7,wall[2]+85,11,3,ROCK1); //R-10

 }
int graphic2HB(int(wall[4])){

  tft.fillTriangle(wall[0]+8,wall[2]+16,wall[0]+14, wall[2]+10, wall[0]+20, wall[2]+16,ROCK); //T-1
  tft.drawLine(wall[0]+11,wall[2]+16,wall[0]+14, wall[2]+13,ROCKSHADE); //T-3
  tft.drawLine(wall[0]+12,wall[2]+16,wall[0]+14, wall[2]+14,ROCKSHADE); //T-4

  tft.fillRoundRect(wall[0]+31, wall[2]+6, 7, 5, 1, GEM1);//G-1
  tft.fillTriangle(wall[0]+31,wall[2]+7,wall[0]+34, wall[2]+2, wall[0]+37, wall[2]+7,GEM1);//G-2
  tft.fillRect(wall[0]+30, wall[2]+10,4,2, GEM2);//G-3
  tft.fillRoundRect(wall[0]+36, wall[2]+8,4,3, 1, GEM3);//G-4
  tft.fillRect(wall[0]+35,wall[2]+5,2,2,GEMSPECS2); // G-5

  tft.fillRoundRect(wall[0]+48, wall[2]+11,4,6, 1, GEM1);//A-1
    tft.fillRect(wall[0]+51, wall[2]+14,3,4, GEM2);//A-2
 }
int graphic2VC(int(wall[4])){
  tft.fillTriangle(wall[0]+2,wall[2]+7,wall[0]+5, wall[2]+4, wall[0]+8, wall[2]+7,ROCK1); //S

  tft.fillRect(wall[0]+5,wall[2]+25,2,4,ROCKSHADE); //R-1
  tft.fillRect(wall[0]+10,wall[2]+18,1,5,ROCKSHADE); // R-2
  tft.fillRect(wall[0]+11,wall[2]+18,4,2,ROCKSHADE); //R-3
  tft.fillRect(wall[0]+11,wall[2]+20,4,3,ROCK2); //R-4
  tft.fillRect(wall[0]+8,wall[2]+22,2,2,ROCKSHADE); //R-5
  tft.fillRect(wall[0]+10,wall[2]+23,6,1,ROCK2); //R-6
  tft.fillRect(wall[0]+7,wall[2]+24,2,2,ROCKSHADE); //R-7
  tft.fillRect(wall[0]+9,wall[2]+24,7,2,ROCK2); //R-8
  tft.fillRect(wall[0]+9,wall[2]+19,1,3,ROCKSHADE); //R-9
  tft.fillRect(wall[0]+7,wall[2]+26,11,3,ROCK2); //R-10
 }
int graphic3HA(int(wall[4])){
  tft.fillRect(wall[0]+12,wall[2]+8,3,5,CRYSTAL4);//C1-1
  tft.fillTriangle(wall[0]+12,wall[2]+7,wall[0]+13,wall[2]+6,wall[0]+14,wall[2]+7,CRYSTAL4);//C1-2
  tft.fillRect(wall[0]+15,wall[2]+5,5,8,CRYSTAL2);//C1-3
  tft.fillTriangle(wall[0]+15,wall[2]+4,wall[0]+17,wall[2]+2,wall[0]+19,wall[2]+4,CRYSTAL2);//C1-4
  tft.fillRect(wall[0]+19,wall[2]+9,4,4,CRYSTAL3);//C1-5
  tft.fillCircle(wall[0]+16,wall[2]+13,2,CRYSTAL3);//C1-6
  
  tft.fillCircle(wall[0]+35,wall[2]+9,2,CRYSTAL3);//C2-1
  tft.fillRoundRect(wall[0]+31,wall[2]+8,8,4,1,CRYSTAL3);//C2-2
  tft.fillRect(wall[0]+29,wall[2]+11,4,3,CRYSTAL6);//C2-3
  tft.fillRoundRect(wall[0]+32,wall[2]+13,6,3,1,CRYSTAL2);//C2-4
  tft.fillRect(wall[0]+33,wall[2]+12,4,1,CRYSTAL2);//C2-5
  tft.fillRect(wall[0]+34,wall[2]+11,2,1,CRYSTAL2);//C2-6

  tft.fillRect(wall[0]+71,wall[2]+7,4,5,MUSHROOMSTEM);//M-1
  tft.fillRoundRect(wall[0]+69,wall[2]+4,8,4,1,MUSHROOM);//M-2
  tft.fillRect(wall[0]+70,wall[2]+3,6,1,MUSHROOM);//M-3
  tft.fillRect(wall[0]+71,wall[2]+2,4,1,MUSHROOM);//M-4
  tft.fillRect(wall[0]+70,wall[2]+5,2,2,MUSHROOMDOT);//M-5
  tft.fillRect(wall[0]+76,wall[2]+5,1,2,MUSHROOMDOT);//M-6
  tft.fillRect(wall[0]+73,wall[2]+3,2,2,MUSHROOMDOT);//M-7

  tft.fillRect(wall[0]+92,wall[2]+11,3,5,PLANTSTEM);//P-1
  tft.fillTriangle(wall[0]+92,wall[2]+11,wall[0]+89,wall[2]+7,wall[0]+94,wall[2]+11,PLANT1);//P-2
  tft.fillTriangle(wall[0]+92,wall[2]+11,wall[0]+94,wall[2]+6,wall[0]+95,wall[2]+11,PLANT1);//P-3
  tft.fillTriangle(wall[0]+94,wall[2]+11,wall[0]+98,wall[2]+9,wall[0]+95,wall[2]+11,PLANT1);//P-4  
 }
int graphic3HB(int(wall[4])){
  tft.fillRect(wall[0]+17,wall[2]+9,4,5,MUSHROOMSTEM);//M-1
  tft.fillRoundRect(wall[0]+15,wall[2]+6,8,4,1,MUSHROOM1);//M-2
  tft.fillRect(wall[0]+16,wall[2]+5,6,1,MUSHROOM1);//M-3
  tft.fillRect(wall[0]+17,wall[2]+4,4,1,MUSHROOM1);//M-4
  tft.fillRect(wall[0]+16,wall[2]+7,2,2,MUSHROOMDOT1);//M-5
  tft.fillRect(wall[0]+22,wall[2]+7,1,2,MUSHROOMDOT1);//M-6
  tft.fillRect(wall[0]+19,wall[2]+5,2,2,MUSHROOMDOT1);//M-7

  tft.fillRect(wall[0]+30,wall[2]+13,4,5,MUSHROOMSTEM);//M-1
  tft.fillRoundRect(wall[0]+28,wall[2]+10,8,4,1,MUSHROOM);//M-2
  tft.fillRect(wall[0]+29,wall[2]+9,6,1,MUSHROOM);//M-3
  tft.fillRect(wall[0]+30,wall[2]+8,4,1,MUSHROOM);//M-4
  tft.fillRect(wall[0]+29,wall[2]+11,2,2,MUSHROOMDOT);//M-5
  tft.fillRect(wall[0]+35,wall[2]+11,1,2,MUSHROOMDOT);//M-6
  tft.fillRect(wall[0]+32,wall[2]+9,2,2,MUSHROOMDOT);//M-7

  tft.fillRect(wall[0]+56,wall[2]+8,3,5,PLANTSTEM);//P-1
  tft.fillTriangle(wall[0]+56,wall[2]+8,wall[0]+53,wall[2]+4,wall[0]+58,wall[2]+8,PLANT);//P-2
  tft.fillTriangle(wall[0]+56,wall[2]+8,wall[0]+58,wall[2]+3,wall[0]+59,wall[2]+8,PLANT);//P-3
  tft.fillTriangle(wall[0]+58,wall[2]+8,wall[0]+62,wall[2]+6,wall[0]+59,wall[2]+8,PLANT);//P-4  

  tft.fillRect(wall[0]+81,wall[2]+10,3,5,CRYSTAL6);//C1-1
  tft.fillTriangle(wall[0]+81,wall[2]+9,wall[0]+82,wall[2]+8,wall[0]+83,wall[2]+9,CRYSTAL6);//C1-2
  tft.fillRect(wall[0]+84,wall[2]+7,5,8,CRYSTAL2);//C1-3
  tft.fillTriangle(wall[0]+84,wall[2]+6,wall[0]+86,wall[2]+4,wall[0]+88,wall[2]+6,CRYSTAL2);//C1-4
  tft.fillRect(wall[0]+88,wall[2]+11,4,4,CRYSTAL6);//C1-5
  tft.fillCircle(wall[0]+85,wall[2]+15,2,CRYSTAL1);//C1-6

  }
int graphic3VC(int(wall[4])){
  tft.fillCircle(wall[0]+8,wall[2]+6,2,CRYSTAL4);//C2-1
  tft.fillRoundRect(wall[0]+4,wall[2]+5,8,4,1,CRYSTAL4);//C2-2
  tft.fillRect(wall[0]+2,wall[2]+8,4,3,CRYSTAL6);//C2-3
  tft.fillRoundRect(wall[0]+5,wall[2]+10,6,3,1,CRYSTAL5);//C2-4
  tft.fillRect(wall[0]+6,wall[2]+9,4,1,CRYSTAL2);//C2-5
  tft.fillRect(wall[0]+7,wall[2]+8,2,1,CRYSTAL3);//C2-6
  }
int graphic3HD(int(wall[4])){
  tft.fillRect(wall[0]+12,wall[2]+8,3,5,CRYSTAL4);//C1-1
  tft.fillTriangle(wall[0]+12,wall[2]+7,wall[0]+13,wall[2]+6,wall[0]+14,wall[2]+7,CRYSTAL4);//C1-2
  tft.fillRect(wall[0]+15,wall[2]+5,5,8,CRYSTAL2);//C1-3
  tft.fillTriangle(wall[0]+15,wall[2]+4,wall[0]+17,wall[2]+2,wall[0]+19,wall[2]+4,CRYSTAL2);//C1-4
  tft.fillRect(wall[0]+19,wall[2]+9,4,4,CRYSTAL3);//C1-5
  tft.fillCircle(wall[0]+16,wall[2]+13,2,CRYSTAL3);//C1-6

  tft.fillRect(wall[0]+30,wall[2]+13,4,5,MUSHROOMSTEM);//M-1
  tft.fillRoundRect(wall[0]+28,wall[2]+10,8,4,1,MUSHROOM);//M-2
  tft.fillRect(wall[0]+29,wall[2]+9,6,1,MUSHROOM);//M-3
  tft.fillRect(wall[0]+30,wall[2]+8,4,1,MUSHROOM);//M-4
  tft.fillRect(wall[0]+29,wall[2]+11,2,2,MUSHROOMDOT);//M-5
  tft.fillRect(wall[0]+35,wall[2]+11,1,2,MUSHROOMDOT);//M-6
  tft.fillRect(wall[0]+32,wall[2]+9,2,2,MUSHROOMDOT);//M-7  
 }
int graphic4VA(int(wall[4])){
  tft.fillRect(wall[0]+4,wall[2]+21,9,3,STONE1);//R1-1
  tft.fillRect(wall[0]+4,wall[2]+16,5,5,STONE1);//R1-2
  tft.fillRect(wall[0]+5,wall[2]+15,4,1,STONE1);//R1-3
  tft.fillRect(wall[0]+6,wall[2]+14,3,1,STONE1);//R1-4
  tft.fillRect(wall[0]+9,wall[2]+17,2,1,STONE1);//R1-5
  tft.fillRect(wall[0]+9,wall[2]+18,3,3,STONE1);//R1-6
  tft.fillRect(wall[0]+10,wall[2]+22,2,2,PIXEL4STONE1);//R1-7
  tft.fillRect(wall[0]+10,wall[2]+20,1,2,PIXEL4STONE2);//R1-8
  tft.fillRect(wall[0]+5,wall[2]+17,3,1,PIXEL4STONE1);//R1-9
  tft.fillRect(wall[0]+5,wall[2]+20,2,3,PIXEL4STONE2);//R1-10
  tft.fillRect(wall[0]+4,wall[2]+18,1,2,STONE1);//R1-11

  tft.fillRect(wall[0]+7,wall[2]+75,2,4,POOLBED);//L-1
  tft.fillRect(wall[0]+7,wall[2]+70,1,2,POOLBED);//L-2
  tft.fillRect(wall[0]+8,wall[2]+70,8,7,POOL1);//L-3
  tft.fillRect(wall[0]+7,wall[2]+69,8,1,POOLBED);//L-4
  tft.fillRect(wall[0]+16,wall[2]+70,2,5,POOLBED);//L-5
  tft.fillRect(wall[0]+16,wall[2]+75,2,1,POOLBED);//L-6
  tft.fillRect(wall[0]+9,wall[2]+77,6,1,POOLBED);//L-7
  tft.fillRect(wall[0]+8,wall[2]+76,5,1,POOL2);//L-8
  tft.fillRect(wall[0]+9,wall[2]+73,7,3,POOL2);//L-9
  tft.fillRect(wall[0]+10,wall[2]+72,6,1,POOL2);//L-10
  tft.fillRect(wall[0]+10,wall[2]+71,5,1,POOL2);//L-11
  tft.fillRect(wall[0]+11,wall[2]+72,2,1,POOL3);//L-12
  tft.fillRect(wall[0]+10,wall[2]+74,2,2,POOL3);//L-13
  tft.fillRect(wall[0]+13,wall[2]+74,2,1,POOL3);//L-14

  tft.fillRect(wall[0]+2,wall[2]+110,9,2,STONE1);//V-1
  tft.fillRect(wall[0]+3,wall[2]+108,7,2,STONE1);//V-2
  tft.fillRect(wall[0]+4,wall[2]+106,5,2,STONE1);//V-3
  tft.fillRect(wall[0]+5,wall[2]+105,3,1,STONE1);//V-4
  tft.fillRect(wall[0]+5,wall[2]+104,3,1,VOLCANO1);//V-5
  tft.fillRect(wall[0]+5,wall[2]+106,2,1,VOLCANO1);//V-6
  tft.drawPixel(wall[0]+5,wall[2]+107,VOLCANO2);//V-7
  tft.drawPixel(wall[0]+4,wall[2]+108,VOLCANO2);//V-8
  tft.drawPixel(wall[0]+4,wall[2]+111,VOLCANO1);//V-9
  tft.fillRect(wall[0]+5,wall[2]+109,1,2,VOLCANO2);//V-10
  tft.fillRect(wall[0]+5,wall[2]+106,1,2,VOLCANO2);//V-11
  tft.drawPixel(wall[0]+8,wall[2]+109,VOLCANO1);//V-12

 }
int graphic4HB(int(wall[4])){
  tft.fillRect(wall[0]+92,wall[2]+14,9,2,STONE2);//V-1
  tft.fillRect(wall[0]+93,wall[2]+12,7,2,STONE2);//V-2
  tft.fillRect(wall[0]+94,wall[2]+10,5,2,STONE2);//V-3
  tft.fillRect(wall[0]+95,wall[2]+9,3,1,STONE2);//V-4
  tft.fillRect(wall[0]+95,wall[2]+8,3,1,STONE2);//V-5
  tft.fillRect(wall[0]+95,wall[2]+10,2,1,VOLCANO1);//V-6
  tft.drawPixel(wall[0]+95,wall[2]+11,VOLCANO2);//V-7
  tft.drawPixel(wall[0]+94,wall[2]+12,VOLCANO2);//V-8
  tft.drawPixel(wall[0]+94,wall[2]+15,VOLCANO1);//V-9
  tft.fillRect(wall[0]+95,wall[2]+13,1,2,VOLCANO2);//V-10
  tft.fillRect(wall[0]+97,wall[2]+10,1,2,VOLCANO2);//V-11
  tft.drawPixel(wall[0]+98,wall[2]+13,VOLCANO1);//V-12

  tft.fillRoundRect(wall[0]+10,wall[2]+3,8,7,1,STONE2);//R2-1
  tft.fillRoundRect(wall[0]+17,wall[2]+6,4,4,1,STONE1);//R2-2

  tft.fillRoundRect(wall[0]+34,wall[2]+11,8,7,1,R2MED);//R2-1
  tft.fillRoundRect(wall[0]+41,wall[2]+14,4,4,1,STONE2);//R2-2
 }
int graphic4HC(int(wall[4])){  
  tft.fillRect(wall[0]+20,wall[2]+11,9,2,STONE2);//V-1
  tft.fillRect(wall[0]+21,wall[2]+9,7,2,STONE2);//V-2
  tft.fillRect(wall[0]+22,wall[2]+7,5,2,STONE2);//V-3
  tft.fillRect(wall[0]+23,wall[2]+6,3,1,STONE2);//V-4
  tft.fillRect(wall[0]+23,wall[2]+5,3,1,STONE2);//V-5
  tft.fillRect(wall[0]+23,wall[2]+7,2,1,VOLCANO1);//V-6
  tft.drawPixel(wall[0]+23,wall[2]+8,VOLCANO2);//V-7
  tft.drawPixel(wall[0]+22,wall[2]+9,VOLCANO2);//V-8
  tft.drawPixel(wall[0]+22,wall[2]+12,VOLCANO1);//V-9
  tft.fillRect(wall[0]+23,wall[2]+10,1,2,VOLCANO2);//V-10
  tft.fillRect(wall[0]+25,wall[2]+7,1,2,VOLCANO2);//V-11
  tft.drawPixel(wall[0]+27,wall[2]+11,VOLCANO1);//V-13

  tft.fillRoundRect(wall[0]+50,wall[2]+12,8,7,1,R2MED1);//R2-1
  tft.fillRoundRect(wall[0]+57,wall[2]+15,4,4,1,STONE2);//R2-2
 }
int graphic4HD(int(wall[4])){
  tft.fillRect(wall[0]+20,wall[2]+12,9,3,STONE3);//R1-1
  tft.fillRect(wall[0]+20,wall[2]+7,5,5,STONE3);//R1-2
  tft.fillRect(wall[0]+21,wall[2]+6,4,1,STONE3);//R1-3
  tft.fillRect(wall[0]+22,wall[2]+5,3,1,STONE3);//R1-4
  tft.fillRect(wall[0]+25,wall[2]+8,2,1,STONE3);//R1-5
  tft.fillRect(wall[0]+25,wall[2]+9,3,3,STONE3);//R1-6
  tft.fillRect(wall[0]+26,wall[2]+13,2,2,PIXEL4STONE2);//R1-7
  tft.fillRect(wall[0]+26,wall[2]+11,1,2,PIXEL4STONE1);//R1-8
  tft.fillRect(wall[0]+21,wall[2]+8,3,1,PIXEL4STONE2);//R1-9
  tft.fillRect(wall[0]+21,wall[2]+11,2,3,PIXEL4STONE1);//R1-10
  tft.fillRect(wall[0]+20,wall[2]+9,1,2,STONE3);//R1-11
 }
int graphic4VE(int(wall[4])){
  tft.fillRect(wall[0]+8,wall[2]+67,9,3,STONE2);//R1-1
  tft.fillRect(wall[0]+8,wall[2]+62,5,5,STONE2);//R1-2
  tft.fillRect(wall[0]+9,wall[2]+61,4,1,STONE2);//R1-3
  tft.fillRect(wall[0]+10,wall[2]+60,3,1,STONE2);//R1-4
  tft.fillRect(wall[0]+13,wall[2]+63,2,1,STONE2);//R1-5
  tft.fillRect(wall[0]+13,wall[2]+64,3,3,STONE2);//R1-6
  tft.fillRect(wall[0]+14,wall[2]+68,2,2,PIXEL4STONE2);//R1-7
  tft.fillRect(wall[0]+14,wall[2]+66,1,2,PIXEL4STONE1);//R1-8
  tft.fillRect(wall[0]+9,wall[2]+63,3,1,PIXEL4STONE2);//R1-9
  tft.fillRect(wall[0]+9,wall[2]+66,2,3,PIXEL4STONE1);//R1-10
  tft.fillRect(wall[0]+8,wall[2]+64,1,2,STONE2);//R1-11

  tft.fillRect(wall[0]+2,wall[2]+26,2,4,POOLBED);//L-1
  tft.fillRect(wall[0]+2,wall[2]+21,1,2,POOLBED);//L-2
  tft.fillRect(wall[0]+3,wall[2]+21,8,7,POOL1);//L-3
  tft.fillRect(wall[0]+2,wall[2]+20,8,1,POOLBED);//L-4
  tft.fillRect(wall[0]+11,wall[2]+21,2,5,POOLBED);//L-5
  tft.fillRect(wall[0]+11,wall[2]+26,2,1,POOLBED);//L-6
  tft.fillRect(wall[0]+4,wall[2]+28,6,1,POOLBED);//L-7
  tft.fillRect(wall[0]+3,wall[2]+27,5,1,POOL2);//L-8
  tft.fillRect(wall[0]+4,wall[2]+24,7,3,POOL2);//L-9
  tft.fillRect(wall[0]+5,wall[2]+23,6,1,POOL2);//L-10
  tft.fillRect(wall[0]+5,wall[2]+22,5,1,POOL2);//L-11
  tft.fillRect(wall[0]+6,wall[2]+23,2,1,POOL3);//L-12
  tft.fillRect(wall[0]+5,wall[2]+25,2,2,POOL3);//L-13
  tft.fillRect(wall[0]+8,wall[2]+25,2,1,POOL3);//L-14
 }  
int createLevel(int(type)){ 
  if (type == 1){ //grassy field biome
    posX = 390;
    posY = 120;
    tft.fillScreen(BLACK);
    background = BLACK;
    characterColour = WHITE;
    tft.fillRect(0, 0, 480, 40, 0x347C);
    tft.fillRect(0, 280, 480, 40, GREEN2);
    tft.fillCircle(166,263,12,RED); // tomato
    tft.fillRect(165,247,4,9, GREEN4); // TOMATO stem
    tft.setTextSize(3);
    tft.drawString("Level 1", 10, 10);
    tft.drawString("Find the Tomato!", 10, 290);
    tft.fillRect(0, 140,66,20, GREEN1); // wall 1
    tft.fillRect(44,260,22,20, GREEN2); // wall 2
    tft.fillRect(55,200,55,20, GREEN1); // wall 3
    tft.fillRect(110,160,22,80, GREEN4); // wall 4
    tft.fillRect(132,220,88,20, GREEN1); // wall 5
    tft.fillRect(198,240,22,40, GREEN3); // wall 6
    tft.fillRect(198,190,22,30, GREEN1); // wall 7
    tft.fillRect(110,140,33,20, GREEN2); // wall 8
    tft.fillRect(143,100,22,60, GREEN3); // wall 9
    tft.fillRect(66,80,99,20, GREEN2); // wall 10
    tft.fillRect(209,40,22,100, GREEN1); // wall 11
    tft.fillRect(286,40,22,140, GREEN4); // wall 12
    tft.fillRect(264,160,22,80, GREEN3); // wall 13
    tft.fillRect(286,220,160,20, GREEN4); // wall 14
    tft.fillRect(352,100,22,80, GREEN3); // wall 15
    tft.fillRect(352,80,95,20, GREEN2); // wall 16
    tft.fillRect(374,140,66,20, GREEN1); // wall 17
    tft.fillRect(440,140,40,20,GREEN1); // wall 18
    tft.fillRect(231,80,10,20, GREEN2); // wall 19
    tft.fillRect(414,200,32,20, GREEN3); // wall 20
    tft.fillRect(337,130,15,30, GREEN2); // wall 21
    tft.fillRect(0,70,36,20, GREEN4); // wall 22

    flowersHA(wall_1_20); // calls flower functions to make flowers on specific maze walls
    flowersHA(wall_1_22);
    flowersHA(wall_1_8);
    flowersHA(wall_1_18);
    flowersHB(wall_1_1); 
    flowersHB(wall_1_17);
    flowersHB(wall_1_3);
    flowersHC(wall_1_10);
    flowersHC(wall_1_5);
    flowersHC(wall_1_14);
    flowersHC(wall_1_16);
   
    tft.fillRect(167,7,15,5,WHITE);//cloud 1
    tft.fillRect(157,12,30,5,WHITE);
    tft.fillRect(142,17,40,5,WHITE); 
    tft.fillRect(182,17,5,5,0x530D); 
    tft.fillRect(157,22,20,5,WHITE);
    tft.fillRect(142,22,15,5,0x530D);
    tft.fillRect(177,22,5,5,0x530D);
    tft.fillRect(157,27,20,5,0x530D);

    tft.fillRect(247,2,15,5,WHITE);//cloud 2
    tft.fillRect(242,7,25,5,WHITE);
    tft.fillRect(237,12,35,5,WHITE);
    tft.fillRect(242,17,30,5,WHITE);
    tft.fillRect(242,22,30,5,WHITE);
    tft.fillRect(257,27,10,5,WHITE);
    tft.fillRect(237,17,5,5,0x530D);
    tft.fillRect(242,27,15,5,0x530D);
    tft.fillRect(267,27,5,5,0x530D);
    tft.fillRect(257,28,10,5,0x530D);

    tft.fillRect(347,5,15,5,WHITE);// cloud 3
    tft.fillRect(337,10,35,5,WHITE);
    tft.fillRect(337,15,25,5,WHITE);
    tft.fillRect(332,20,25,5,WHITE);
    tft.fillRect(362,15,10,5,0x530D);
    tft.fillRect(357,20,5,5,0x530D);
    tft.fillRect(332,25,25,5,0x530D);

    tft.fillRect(442,7,10,5,WHITE); // cloud 4
    tft.fillRect(432,12,30,5,WHITE);
    tft.fillRect(427,17,40,5,WHITE);
    tft.fillRect(427,22,40,5,WHITE);
    tft.fillRect(422,27,30,5,WHITE);
    tft.fillRect(422,32,30,5,0x530D);
    tft.fillRect(452,27,15,5,0x530D);
  }
  else if (type == 2){ // cave biome
    posX = 40;
    posY = 180;
    tft.fillScreen(BLACK);
    background = BLACK;
    characterColour = WHITE;
    tft.fillRect(0, 0, 480, 40, CAVE2); 
    tft.fillRect(0, 280, 480, 40, CAVE2);
    tft.fillTriangle(279, 106, 298,106, 289, 121, 0xFBE0); // carrot
    tft.fillRect(284,102,2,1,CARROTSTEM);//carrot stem 1
    tft.fillRect(285,103,2,1,CARROTSTEM);//carrot stem 2
    tft.fillRect(286,104,2,1,CARROTSTEM);//carrot stem 3
    tft.fillRect(287,105,4,1,CARROTSTEM);//carrot stem 4
    tft.fillRect(288,103,2,2,CARROTSTEM);//carrot stem 5
    tft.fillRect(290,104,2,1,CARROTSTEM);//carrot stem 6
    tft.fillRect(291,103,2,1,CARROTSTEM);//carrot stem 7
    tft.fillRect(292,102,2,1,CARROTSTEM);//carrot stem 8
    tft.setTextSize(3);
    tft.drawString("Level 2", 10, 10);
    tft.drawString("Find the Carrot!", 10, 290);
    tft.fillRect(0, 80, 70, 20, CAVE1); // wall 1
    tft.fillRect(115, 250, 20, 30, CAVE2);// wall 2
    tft.fillRect(55,250,60,20, CAVE1);// wall 3
    tft.fillRect(55,140,20,110, CAVE3);// wall 4
    tft.fillRect(75,140,60,20, CAVE2);// wall 5
    tft.fillRect(115,80,20,60, CAVE1);// wall 6
    tft.fillRect(135,80,50,20, CAVE4);// wall 7
    tft.fillRect(165,100,20,40, CAVE1);// wall 8
    tft.fillRect(115,200,120,10, CAVE4);// wall 9
    tft.fillRect(170,210,20,30, CAVE2);// wall 10
    tft.fillRect(215,40,20,160, CAVE1);// wall 11
    tft.fillRect(235,185,80,15, CAVE3);// wall 12
    tft.fillRect(235,130,40,20, CAVE1);// wall 13
    tft.fillRect(275,130,110,20, CAVE2);// wall 14 
    tft.fillRect(305,80,20,50, CAVE4);// wall 15 
    tft.fillRect(275,80,30,15, CAVE1);// wall 16     
    tft.fillRect(365,70,80,20, CAVE1);// wall 17
    tft.fillRect(355,150,20,90, CAVE4);// wall 18
    tft.fillRect(275,240,40,20, CAVE3);// wall 19
    tft.fillRect(295,260,20,20, CAVE2);// wall 20
    tft.fillRect(225,250,20,30, CAVE1);// wall 21   
    tft.fillRect(375,190,70,20, CAVE3);// wall 22
    tft.fillRect(420,130,60,20, CAVE4);// wall 23
    tft.fillRect(385,40,20,30, CAVE1);// wall 24
    tft.fillRect(430,250,50,30, CAVE3);// wall 25

    graphic2VA(wall_2_4);
    graphic2VA(wall_2_18);
    graphic2VA(wall_2_11);

    graphic2HB(wall_2_3); 
    graphic2HB(wall_2_1);
    graphic2HB(wall_2_22);
    graphic2HB(wall_2_23);
 
    graphic2VC(wall_2_10);
    graphic2VC(wall_2_21);
    graphic2VC(wall_2_24);
    graphic2VC(wall_2_15);
    graphic2VC(wall_2_8);

    tft.fillRect(230,10,15,5,BLACK); //bat 1
    tft.fillRect(235,15,45,5,BLACK); //bat 2
    tft.fillRect(240,20,5,5,BLACK); //bat 3
    tft.fillRect(250,20,15,5,BLACK); //bat 4
    tft.fillRect(255,25,5,3,BLACK); //bat 5
    tft.fillRect(270,20,5,5,BLACK); //bat 6
    tft.fillRect(270,10,15,5,BLACK); //bat 7
    tft.fillRect(250,10,15,5,BLACK); //bat 8
    tft.fillRect(250,5,5,5,BLACK); //bat 9
    tft.fillRect(260,5,5,5,BLACK); //bat 10
    tft.fillRect(252,14,3,3,0xB8A1); //bat  11
    tft.fillRect(260,14,3,3,0xB8A1); //bat 12

    tft.fillRect(400,10,15,5,BLACK); //bat 1
    tft.fillRect(405,15,45,5,BLACK); //bat 2
    tft.fillRect(410,20,5,5,BLACK); //bat 3
    tft.fillRect(420,20,15,5,BLACK); //bat 4
    tft.fillRect(425,25,5,3,BLACK); //bat 5
    tft.fillRect(440,20,5,5,BLACK); //bat 6
    tft.fillRect(440,10,15,5,BLACK); //bat 7
    tft.fillRect(420,10,15,5,BLACK); //bat 8
    tft.fillRect(420,5,5,5,BLACK); //bat 9
    tft.fillRect(430,5,5,5,BLACK); //bat 10
    tft.fillRect(422,14,3,3,0xB8A1); //bat  11
    tft.fillRect(430,14,3,3,0xB8A1); //bat 12

    tft.fillRect(309,0,54,27,CAVE1);//top rock
    tft.fillRect(300,0,9,18,TOPSHADE1);
    tft.fillRect(309,9,9,9,TOPSHADE2);
    tft.fillRect(309,18,9,9,CAVE2);
    tft.fillRect(318,18,18,9,TOPSHADE2);
    tft.fillRect(336,27,9,9,TOPSHADE1);
    tft.fillRect(354,18,9,9,TOPSHADE1);
    tft.fillRect(363,9,9,9,TOPSHADE1);
    tft.fillRect(363,0,18,9,TOPSHADE2);    
  }
  else if (type == 3){ // crystal tavern biome
    posX = 430;
    posY = 260;
    tft.fillScreen(BLACK);
    background = BLACK;
    characterColour = WHITE;
    tft.fillRect(0, 0, 480, 40, MYSTIC1);
    tft.fillRect(0, 280, 480, 40, MYSTIC1);
    tft.fillRect(262,270,4,2,BONE1); // chicken 1
    tft.fillRect(266,268,2,2,BONE1); // chicken 2
    tft.fillRect(268,266,2,2,BONE1); // chicken 3
    tft.fillRect(270,264,2,2,BONE1); // chicken 4
    tft.fillRect(272,262,2,2,BONE1); // chicken 5
    tft.fillRect(266,270,2,4,BONE2); // chicken 6
    tft.fillRect(268,268,2,2,BONE2); // chicken 7
    tft.fillRect(270,266,2,2,BONE2); // chicken 8
    tft.fillRect(272,264,2,2,BONE2); // chicken 9
    tft.fillRect(272,254,2,8,CHICKEN1); // chicken 10
    tft.fillRect(274,252,2,14,CHICKEN2); // chicken 11
    tft.fillRect(276,250,10,14,CHICKEN2); // chicken 12
    tft.fillRect(276,252,6,6,CHICKEN1); // chicken 13
    tft.fillRect(286,254,4,6,CHICKEN3); // chicken 14
    tft.fillRect(286,252,2,2,CHICKEN2); // chicken 15
    tft.fillRect(286,260,2,2,CHICKEN3); // chicken 16  
    tft.fillRect(276,260,10,4,CHICKEN3); // chicken 17  
    tft.setTextSize(3);
    tft.drawString("Level 3", 10, 10);
    tft.drawString("Find the Chicken!", 10, 290);
    tft.fillRect(0,160,110,20, MYSTIC4); // wall 1
    tft.fillRect(90,140,20,20, MYSTIC2); // wall 2
    tft.fillRect(40,80,20,40, MYSTIC3); // wall 3
    tft.fillRect(60,80,100,20, MYSTIC4); // wall 4
    tft.fillRect(140,100,20,140, MYSTIC1); // wall 5
    tft.fillRect(40,220,100,20, MYSTIC2); // wall 6
    tft.fillRect(220,240,20,40, MYSTIC4); // wall 7
    tft.fillRect(200,220,140,20, MYSTIC1); // wall 8
    tft.fillRect(340,200,10,40, MYSTIC3); // wall 9
    tft.fillRect(320,180,20,40, MYSTIC1); // wall 10
    tft.fillRect(200,160,140,20, MYSTIC4); // wall 11
    tft.fillRect(310,140,30,20, MYSTIC2); // wall 12
    tft.fillRect(160,100,120,20,MYSTIC2); // wall 13
    tft.fillRect(200,40,20,20, MYSTIC3); // wall 14
    tft.fillRect(260,80,140,20, MYSTIC1); // wall 15
    tft.fillRect(380,100,20,60, MYSTIC4); // wall 16
    tft.fillRect(380,160,60,20, MYSTIC2); // wall 17
    tft.fillRect(390,180,20,100, MYSTIC3); // wall 18
    tft.fillRect(450,220,30,20, MYSTIC2); // wall 19
    tft.fillRect(440,80,40,20, MYSTIC3); // wall 20

    graphic3HA(wall_3_1);
    graphic3HA(wall_3_13);
    graphic3HA(wall_3_8);

    graphic3HB(wall_3_4);
    graphic3HB(wall_3_6);
    graphic3HB(wall_3_11);
    graphic3HB(wall_3_15);

    graphic3VC(wall_3_2);
    graphic3VC(wall_3_14);
    graphic3VC(wall_3_7);
    graphic3VC(wall_3_12);
    graphic3VC(wall_3_19);

    graphic3HD(wall_3_20);
    graphic3HD(wall_3_17);

    tft.fillRect(220,0,70,10, TOPROCKS); // TOPROCK1-1
    tft.fillRect(230,10,50,10, TOPROCKS); // TOPROCK1-2
    tft.fillRect(250,20,10,20, TOPROCKS); // TOPROCK1-3
    tft.fillRect(260,20,20,10, TOPROCKS); // TOPROCK1-4
    tft.fillRect(230,15,15,5, CRYSTAL1); // TOPROCK1-5
    tft.fillRect(250,30,5,10, CRYSTAL5); // TOPROCK1-6
    tft.fillRect(260,25,10,5, CRYSTAL1); // TOPROCK1-7
    tft.fillRect(275,10,5,15, CRYSTAL5); // TOPROCK1-8
    tft.fillRect(280,5,10,5, CRYSTAL1); // TOPROCK1-9
    tft.fillRect(220,0,5,10, CRYSTAL5); // TOPROCK1-10

    tft.fillRect(330,0,50,20, TOPROCKS); // TOPROCK2-1
    tft.fillRect(380,0,10,10, TOPROCKS); // TOPROCK2-2
    tft.fillRect(340,20,30,10, TOPROCKS); // TOPROCK2-3
    tft.fillRect(330,10,5,10, CRYSTAL1); // TOPROCK2-4
    tft.fillRect(340,20,5,10, CRYSTAL2); // TOPROCK2-5
    tft.fillRect(345,25,5,5, CRYSTAL3); // TOPROCK2-6
    tft.fillRect(365,15,5,10, CRYSTAL3); // TOPROCK2-7
    tft.fillRect(370,15,10,5, CRYSTAL1); // TOPROCK2-8
    tft.fillRect(380,5,10,5, CRYSTAL1); // TOPROCK2-9
    tft.fillRect(330,10,5,5, CRYSTAL2); // TOPROCK2-10
    tft.fillRect(330,5,5,5, CRYSTAL3); // TOPROCK2-11

    tft.fillRect(420,0,10,10, TOPROCKS); // TOPROCK3-1
    tft.fillRect(430,0,40,30, TOPROCKS); // TOPROCK3-2
    tft.fillRect(470,0,10,20, TOPROCKS); // TOPROCK3-3
    tft.fillRect(440,30,10,10, TOPROCKS); // TOPROCK3-4
    tft.fillRect(420,5,15,5, CRYSTAL3); // TOPROCK3-5
    tft.fillRect(430,10,5,5, CRYSTAL2); // TOPROCK3-6
    tft.fillRect(430,15,5,5, CRYSTAL5); // TOPROCK3-7
    tft.fillRect(430,25,10,5, CRYSTAL5); // TOPROCK3-8
    tft.fillRect(445,30,5,10, CRYSTAL1); // TOPROCK3-9
    tft.fillRect(455,25,15,5, CRYSTAL2); // TOPROCK3-10
    tft.fillRect(475,0,5,20, CRYSTAL3); // TOPROCK3-11
    tft.fillRect(465,15,5,5, CRYSTAL2); // TOPROCK3-12


  }
  else if (type == 4){ //lava biome
    posX = 310;
    posY = 125;
    tft.fillScreen(BLACK);
    background = BLACK;
    characterColour = WHITE;
    tft.fillRect(0, 0, 480, 40, LAVA1);
    tft.fillRect(0, 280, 480, 40, LAVA1);
    tft.fillRect(264, 262, 22, 4, BOWL); // noodles 2
    tft.fillRect(266, 266, 18, 2, BOWL); // noodles 3
    tft.fillRect(268, 268, 14, 2, BOWL); // noodles 4
    tft.fillRect(264, 256, 2, 4, NOODLES); // noodles 5
    tft.fillRect(266, 254, 2, 4, NOODLES); // noodles 6
    tft.fillRect(268, 252, 2, 4, NOODLES); // noodles 7
    tft.fillRect(270, 250, 10, 8, NOODLES); // noodles 8
    tft.fillRect(280, 252, 2, 4, NOODLES); // noodles 9
    tft.fillRect(282, 254, 2, 2, NOODLES); // noodles 10
    tft.fillRect(284, 256, 2, 2, NOODLES); // noodles 11
    tft.fillRect(268, 256, 2, 2, NOODLES1); // noodles 12
    tft.fillRect(270, 254, 6, 2, NOODLES1); // noodles 13
    tft.fillRect(276, 252, 2, 2, NOODLES1); // noodles 14
    tft.fillRect(270, 250, 4, 2, NOODLES1); // noodles 15
    tft.fillRect(278, 256, 6, 2, NOODLES1); // noodles 16
    tft.fillRect(262, 260, 26, 2, BOWL1); // noodles 17
    tft.fillRect(262, 258, 26, 2, BOWL); // noodles 1
    tft.setTextSize(3);
    tft.drawString("Level 4", 10, 10);
    tft.drawString("Find the Noodles!", 10, 290);
    tft.fillRect(0,160,70,20, LAVA1); // wall 1
    tft.fillRect(70,140,20,100, LAVA2); // wall 2
    tft.fillRect(120,220,70,20, LAVA1); // wall 3
    tft.fillRect(120,100,20,120, LAVA3); // wall 4
    tft.fillRect(50,80,90,20, LAVA4); // wall 5
    tft.fillRect(180,80,20,40, LAVA1); // wall 6
    tft.fillRect(200,80,40,20, LAVA4); // wall 7
    tft.fillRect(220,40,20,40, LAVA2); // wall 8
    tft.fillRect(140,160,120,20, LAVA3); // wall 9
    tft.fillRect(240,140,50,20, LAVA1); // wall 10
    tft.fillRect(270,80,20,60, LAVA2); // wall 11
    tft.fillRect(290,80,160,20, LAVA3); // wall 12
    tft.fillRect(430,100,20,140, LAVA4); // wall 13
    tft.fillRect(380,140,20,140, LAVA3); // wall 14
    tft.fillRect(330,100,20,120, LAVA4); // wall 15
    tft.fillRect(290,200,40,20, LAVA2); // wall 16
    tft.fillRect(230,220,80,20, LAVA4); // wall 17
    tft.fillRect(230,240,20,40, LAVA2); // wall 18
    tft.fillRect(340,260,40,20, LAVA3); // wall 19 

    graphic4VA(wall_4_4);
    graphic4VA(wall_4_15);
    graphic4VA(wall_4_13);
    graphic4HB(wall_4_9);
    graphic4HB(wall_4_12);
    graphic4HC(wall_4_5);
    graphic4HC(wall_4_3);
    graphic4HC(wall_4_17);
    graphic4HD(wall_4_19);
    graphic4HD(wall_4_7);
    graphic4HD(wall_4_10);
    graphic4HD(wall_4_1);
    graphic4VE(wall_4_2);
    graphic4VE(wall_4_14);

   tft.fillRect(362,18,14,8, DRAGONBODY); // dragon
   tft.fillRect(376,18,12,12, DRAGONBODY);
   tft.fillRect(388,24,2,10, DRAGONBODY);
   tft.fillRect(390,24,4,2, DRAGONBODY);
   tft.fillRect(380,6,4,12, DRAGONWINGS);
   tft.fillRect(384,12,6,2, DRAGONWINGS);
   tft.fillRect(384,16,2,2, DRAGONWINGS);
   tft.fillRect(382,18,2,4, DRAGONWINGS);
   tft.fillRect(372,14,2,2, DRAGONBLUE1);
   tft.fillRect(374,14,4,2, DRAGONBLUE2);
   tft.fillRect(372,16,2,2, DRAGONBLUE2);
   tft.fillRect(374,16,2,2, DRAGONNOSE);
   tft.fillRect(376,16,2,2, DRAGONBLUE1);   
   tft.fillRect(378,16,2,2, DRAGONBLUE2);
   tft.fillRect(376,18,2,2, DRAGONNOSE);
   tft.fillRect(378,18,2,2, DRAGONBLUE1);
   tft.fillRect(380,18,2,2, DRAGONLEGS);
   tft.fillRect(384,18,4,2, BLACK);
   tft.fillRect(384,20,4,2, DRAGONHIGHLIGHT);
   tft.fillRect(388,20,2,2, BLACK);
   tft.fillRect(388,22,2,2, DRAGONHIGHLIGHT);
   tft.fillRect(390,22,4,2, BLACK);
   tft.fillRect(394,22,2,4, BLACK);
   tft.fillRect(378,8,2,8, BLACK);
   tft.fillRect(380,6,2,2, BLACK);
   tft.fillRect(382,4,2,2, BLACK);
   tft.fillRect(380,10,2,2, DRAGONHIGHLIGHT);
   tft.fillRect(380,12,2,2, BLACK);
   tft.fillRect(380,14,2,2, DRAGONLEGS);
   tft.fillRect(382,10,10,2,BLACK);
   tft.fillRect(382,16,2,2, DRAGONHIGHLIGHT);
   tft.fillRect(384,14,4,2, DRAGONHIGHLIGHT);
   tft.fillRect(382,8,2,2, DRAGONHIGHLIGHT);
   tft.fillRect(360,20,2,4,BLACK);
   tft.fillRect(362,18,4,2,BLACK);
   tft.fillRect(366,16,2,2,BLACK);
   tft.fillRect(368,14,4,2,BLACK);
   tft.fillRect(368,16,4,2,DRAGONHIGHLIGHT);
   tft.fillRect(372,12,4,2,BLACK);
   tft.fillRect(370,18,6,2,DRAGONHIGHLIGHT);
   tft.fillRect(370,20,2,2,BLACK);
   tft.fillRect(372,20,2,2,0xBDF7);
   tft.fillRect(370,22,2,2,0x7412);
   tft.fillRect(372,22,2,2,WHITE);
   tft.fillRect(376,20,4,2,BLACK);
   tft.fillRect(378,22,2,2,DRAGONLEGS);
   tft.fillRect(376,24,2,2,BLACK);
   tft.fillRect(362,24,2,2,BLACK);
   tft.fillRect(364,26,12,2,BLACK);
   tft.fillRect(370,28,2,2,BLACK);
   tft.fillRect(374,28,2,2,BLACK);
   tft.fillRect(372,28,2,2,DRAGONLEGS);
   tft.fillRect(372,30,4,2,BLACK);
   tft.fillRect(376,30,4,2,DRAGONHIGHLIGHT);
   tft.fillRect(376,32,4,2,BLACK);
   tft.fillRect(378,28,2,2,DRAGONHIGHLIGHT);
   tft.fillRect(380,26,2,6,BLACK);
   tft.fillRect(382,26,2,2,DRAGONWINGS);
   tft.fillRect(382,28,2,2,BLACK);
   tft.fillRect(384,28,2,2,DRAGONWINGS);
   tft.fillRect(384,30,2,4,BLACK);
   tft.fillRect(386,30,2,4,DRAGONLEGS);
   tft.fillRect(386,34,4,2,BLACK);
   tft.fillRect(390,28,2,6,BLACK);
   tft.fillRect(390,26,2,2,DRAGONWINGS);
   tft.fillRect(392,26,2,2,BLACK);
   tft.fillRect(364,22,2,2,DRAGONNOSE);

   tft.fillRect(340,18,2,2,FIRE1);
   tft.fillRect(342,22,2,2,FIRE1);
   tft.fillRect(344,20,2,4,FIRE1);
   tft.fillRect(346,20,2,4,FIRE2);
   tft.fillRect(346,18,2,2,FIRE1);   
   tft.fillRect(346,24,4,2,FIRE1);
   tft.fillRect(350,24,4,2,FIRE2);
   tft.fillRect(350,26,6,2,FIRE1);
   tft.fillRect(342,28,2,2,FIRE1);
   tft.fillRect(344,30,2,2,FIRE1);
   tft.fillRect(348,18,6,2,FIRE2);
   tft.fillRect(348,20,4,2,FIRE4);
   tft.fillRect(348,22,4,2,FIRE3);
   tft.fillRect(350,16,4,2,FIRE1);
   tft.fillRect(354,18,2,2,FIRE1);
   tft.fillRect(354,20,2,2,FIRE2);
   tft.fillRect(356,20,2,2,FIRE1);
   tft.fillRect(356,22,2,2,FIRE4);
   tft.fillRect(356,24,2,2,FIRE1);
   tft.fillRect(352,20,2,4,FIRE4);
   tft.fillRect(354,22,2,4,FIRE4);

  }
}
int beginCutscene(int(type)){
  tft.fillScreen(BLACK);
  if (type == 0){
    for (int i = 0; i <= 480; ++i){
      tft.drawFastVLine((0+1*i), 0, 64, WHITE);
      tft.drawFastVLine((480-1*i), 64, 64, WHITE);
      tft.drawFastVLine((0+1*i), 128, 64, WHITE);
      tft.drawFastVLine((480-1*i), 192, 64, WHITE);
      tft.drawFastVLine((0+1*i), 256, 64, WHITE);
    }
    for (int i = 0; i <= 320; ++i){
      tft.drawFastHLine(0, (0+1*i), 96, 0x000B);
      tft.drawFastHLine(96, (320-1*i), 96, 0x000B);
      tft.drawFastHLine(192, (0+1*i), 96, 0x000B);
      tft.drawFastHLine(288, (320-1*i), 96, 0x000B);
      tft.drawFastHLine(384, (0+1*i), 96, 0x000B);
    }
    createMenu(0);
    GameOnMenu = true;
  }
  if (type == 1){
    tft.fillScreen(0xE38F);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.drawString("This is Soup Cat", 100, 20);
    tft.drawString("He is a cat who makes", 50, 130);
    tft.drawString("soup for all his friends!", 20, 170);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.drawString("Press \"A\" to continue", 50, 280);
    //Main Cat
    characterColour = WHITE;
    tft.fillRect(int(240-22), int(90-22), 44, 44, characterColour);
    tft.fillRect(int(240-16), int(90-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(240+6), int(90-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(240-2), int(90+6), 4, 4, MAGENTA); //CUSTOMIZATION NOSE
    tft.fillRect(int(240-14), int(90-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.fillRect(int(240+8), int(90-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.drawFastHLine(int(240-10), int(90+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawFastHLine(int(240+4), int(90+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawPixel(int(240-12), int(90+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(240+10), int(90+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(240-4), int(90+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(240+2), int(90+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.fillTriangle(int(240-22), int(90-24), int(240-12), int(90-34),int(240-2), int(90-24), characterColour);
    tft.fillTriangle(int(240), int(90-24), int(240+10), int(90-34),int(240+20), int(90-24), characterColour);
    tft.fillTriangle(int(240-16), int(90-24), int(240-12), int(90-28),int(240-8), int(90-24), MAGENTA); //CUSTOMIZATION EAR
    tft.fillTriangle(int(240+6), int(90-24), int(240+10), int(90-28),int(240+14), int(90-24), MAGENTA); //CUSTOMIZATION EAR
    //Friend Cat #1 Brown
    characterColour = 0x7A00;
    tft.fillRect(int(120-22), int(240-22), 44, 44, characterColour);
    tft.fillRect(int(120-16), int(240-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(120+6), int(240-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(120-2), int(240+6), 4, 4, MAGENTA); //CUSTOMIZATION NOSE
    tft.fillRect(int(120-14), int(240-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.fillRect(int(120+8), int(240-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.drawFastHLine(int(120-10), int(240+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawFastHLine(int(120+4), int(240+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawPixel(int(120-12), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(120+10), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(120-4), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(120+2), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.fillTriangle(int(120-22), int(240-24), int(120-12), int(240-34),int(120-2), int(240-24), characterColour);
    tft.fillTriangle(int(120), int(240-24), int(120+10), int(240-34),int(120+20), int(240-24), characterColour);
    tft.fillTriangle(int(120-16), int(240-24), int(120-12), int(240-28),int(120-8), int(240-24), MAGENTA); //CUSTOMIZATION EAR
    tft.fillTriangle(int(120+6), int(240-24), int(120+10), int(240-28),int(120+14), int(240-24), MAGENTA); //CUSTOMIZATION EAR
    //Friend Cat #2 Orange
    characterColour = 0xFCCC;
    tft.fillRect(int(240-22), int(240-22), 44, 44, characterColour);
    tft.fillRect(int(240-16), int(240-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(240+6), int(240-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(240-2), int(240+6), 4, 4, MAGENTA); //CUSTOMIZATION NOSE
    tft.fillRect(int(240-14), int(240-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.fillRect(int(240+8), int(240-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.drawFastHLine(int(240-10), int(240+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawFastHLine(int(240+4), int(240+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawPixel(int(240-12), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(240+10), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(240-4), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(240+2), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.fillTriangle(int(240-22), int(240-24), int(240-12), int(240-34),int(240-2), int(240-24), characterColour);
    tft.fillTriangle(int(240), int(240-24), int(240+10), int(240-34),int(240+20), int(240-24), characterColour);
    tft.fillTriangle(int(240-16), int(240-24), int(240-12), int(240-28),int(240-8), int(240-24), MAGENTA); //CUSTOMIZATION EAR
    tft.fillTriangle(int(240+6), int(240-24), int(240+10), int(240-28),int(240+14), int(240-24), MAGENTA); //CUSTOMIZATION EAR
    //Friend Cat #3 Gray
    characterColour = ASHGREY;
    tft.fillRect(int(360-22), int(240-22), 44, 44, characterColour);
    tft.fillRect(int(360-16), int(240-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(360+6), int(240-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(360-2), int(240+6), 4, 4, MAGENTA); //CUSTOMIZATION NOSE
    tft.fillRect(int(360-14), int(240-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.fillRect(int(360+8), int(240-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.drawFastHLine(int(360-10), int(240+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawFastHLine(int(360+4), int(240+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawPixel(int(360-12), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(360+10), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(360-4), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(360+2), int(240+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.fillTriangle(int(360-22), int(240-24), int(360-12), int(240-34),int(360-2), int(240-24), characterColour);
    tft.fillTriangle(int(360), int(240-24), int(360+10), int(240-34),int(360+20), int(240-24), characterColour);
    tft.fillTriangle(int(360-16), int(240-24), int(360-12), int(240-28),int(360-8), int(240-24), MAGENTA); //CUSTOMIZATION EAR
    tft.fillTriangle(int(360+6), int(240-24), int(360+10), int(240-28),int(360+14), int(240-24), MAGENTA); //CUSTOMIZATION EAR
    characterColour = WHITE;
  }
  if (type == 2){
    tft.fillScreen(0xE38F);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.drawString("Then one day, Soup Cat woke up", 60, 20);
    tft.drawString("to all his ingredients missing!", 60, 50);
    tft.drawString("The evil Cat Wizard had stolen", 60, 80);
    tft.drawString("all of Soup Cat's ingredients", 60, 110);
    tft.drawString("and hid them in his evil maze!", 60, 140);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.drawString("Press \"A\" to continue", 50, 280);
    //Evil Wizard Cat
    characterColour = BLACK;
    tft.fillRect(int(240-22), int(220-22), 44, 44, characterColour);
    tft.fillRect(int(240-16), int(220-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(240+6), int(220-12), 10, 10, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(240-2), int(220+6), 4, 4, MAGENTA); //CUSTOMIZATION NOSE
    tft.fillRect(int(240-14), int(220-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.fillRect(int(240+8), int(220-10), 4, 4, WHITE); // CUSTOMIZATION EYE
    tft.drawFastHLine(int(240-10), int(220+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawFastHLine(int(240+4), int(220+12), 6, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawPixel(int(240-12), int(220+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(240+10), int(220+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(240-4), int(220+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(240+2), int(220+10), MAGENTA); // CUSTOMIZATION NOSE
    tft.fillTriangle(int(240-22), int(220-24), int(240-12), int(220-34),int(240-2), int(220-24), characterColour);
    tft.fillTriangle(int(240), int(220-24), int(240+10), int(220-34),int(240+20), int(220-24), characterColour);
    tft.fillTriangle(int(240-16), int(220-24), int(240-12), int(220-28),int(240-8), int(220-24), MAGENTA); //CUSTOMIZATION EAR
    tft.fillTriangle(int(240+6), int(220-24), int(240+10), int(220-28),int(240+14), int(220-24), MAGENTA); //CUSTOMIZATION EAR
    characterColour = WHITE;
  }
  if (type == 3){
    tft.fillScreen(0xE38F);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.drawString("Without Soup Cat's soup, his", 10, 50);
    tft.drawString("friends have nothing to eat!", 10, 90);
    tft.drawString("It's up to Soup Cat to find", 10, 130);
    tft.drawString("the missing ingredients before", 10, 170);
    tft.drawString("the day ends and save the day!", 10, 210);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.drawString("Press \"A\" to continue", 50, 280);
  }
}
int checkCollision(int(wall[4]), int i, int e){
  if (int(posX+12)>=wall[0] && int(posX+12)<=(wall[0]+(wall[1]/2)) && int(posY-18)<=(wall[2]+wall[3]) && int(posY+12)>=wall[2]){R_collision = true;}
  else {R_collision = false;}
  if (int(posX-12)>=(wall[0]+(wall[1])/2) && int(posX-12)<=(wall[0]+wall[1]) && int(posY-18)<=(wall[2]+wall[3]) && int(posY+12)>=wall[2]){L_collision = true;}
  else {L_collision = false;}
  if (int(posX+12)>=wall[0] && int(posX-12)<=(wall[0]+wall[1]) && int(posY-18)<=(wall[2]+wall[3]) && int(posY-18)>=(wall[2]+(wall[3]/2))){U_collision = true;}
  else {U_collision = false;}
  if (int(posX+12)>=wall[0] && int(posX-12)<=(wall[0]+wall[1]) && int(posY+12)<=(wall[2]+(wall[3]/2)) && int(posY+12)>=wall[2]){D_collision = true;}
  else {D_collision = false;}
  if (R_collision == true || L_collision == true || U_collision == true || D_collision == true){wallCollision = i;}
  else if (e != 0){wallCollision = i + 1;}
  else {wallCollision = 1;}
}

void setup() {

  // Initalize the screen and set the orientation correctly.
  tft.begin();
  tft.setRotation(1);
  pinMode(BUTTON_A_PIN, INPUT);

  // Creates the Main Menu.
  beginCutscene(0);

  // Tell the arduino that the joystick button is on pin 9 and write it high so it gets set to 0 when pushed.
  // If you'd like to learn more about this check out the Elegoo documentation on the Joystick.
  pinMode(JOYSTICK_BUTTON_PIN, INPUT);
  digitalWrite(JOYSTICK_BUTTON_PIN, HIGH);
}

void loop() {
  // Read input and map change the range from 0 - 1023 to -0.5 to 0.5. map() only creates integers. 
  float JoyStickX = map(analogRead(JOYSTICK_X_PIN), 0, 1023, -1000, 1000)/1000.0;
  float JoyStickY = map(analogRead(JOYSTICK_Y_PIN), 0, 1023, -1000, 1000)/1000.0;

  // Update cursor position
  if (GameRun == true){
    if (JoyStickY < -0.1 && U_collision == false){posY = posY + JoyStickY;}
    if (JoyStickY > 0.1 && D_collision == false){posY = posY + JoyStickY;}
    if (JoyStickX < -0.1 && L_collision == false){posX = posX + JoyStickX;}
    if (JoyStickX > 0.1 && R_collision == false){posX = posX + JoyStickX;}
  }

  // Limit the cursor to the bounds of where the player is allowed to go.
  // Actual bounds are X(0-480) Y(0-320)
  posX = constrain(posX, 12, 468);
  posY = constrain(posY, 58, 268);

  // Read the pin for the button in the joystick, and if pressed add one to resetCount. Otherwise, reset it to 0.
  if (digitalRead(JOYSTICK_BUTTON_PIN) == 0) resetCount += 1;
  else resetCount = 0;
  button_A = digitalRead(BUTTON_A_PIN);

  // If the button has been held for around 2 seconds, enter Sub Menu.
  if (resetCount > 100) {
    GamePaused = true;
    GameOnMenu = false;
    GameRun = false;
    createMenu(1);
  }
  // Selector for Main Menu UI
  if (GameOnMenu == true){
    if (MenuPos == 0){
      tft.drawRoundRect(140, 170, 200, 60, 15, WHITE);
      tft.drawRoundRect(139, 169, 202, 62, 15, WHITE);
      tft.drawRoundRect(110, 250, 120, 40, 15, BLACK);
      tft.drawRoundRect(109, 249, 122, 42, 15, BLACK);
      tft.drawRoundRect(250, 250, 120, 40, 15, BLACK);
      tft.drawRoundRect(249, 249, 122, 42, 15, BLACK);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.drawString("Start Game", 150, 190);
      tft.setTextColor(BLACK);
      tft.setTextSize(2);
      tft.drawString("Controls", 122, 265);
      tft.drawString("Credits", 268, 265);
      if (JoyStickY > 0.4){
        MenuPos = 1;
        delay(500);
      }
      if (button_A == 1){
        beginCutscene(1);
        GameOnMenu = false;
        GameOnCutscene = true;
        CutscenePos = 1;
        level = 1;
      }
    }
    else if (MenuPos == 1){
      tft.drawRoundRect(140, 170, 200, 60, 15, BLACK);
      tft.drawRoundRect(139, 169, 202, 62, 15, BLACK);
      tft.drawRoundRect(110, 250, 120, 40, 15, WHITE);
      tft.drawRoundRect(109, 249, 122, 42, 15, WHITE);
      tft.drawRoundRect(250, 250, 120, 40, 15, BLACK);
      tft.drawRoundRect(249, 249, 122, 42, 15, BLACK);
      tft.setTextColor(BLACK);
      tft.setTextSize(3);
      tft.drawString("Start Game", 150, 190);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      tft.drawString("Controls", 122, 265);
      tft.setTextColor(BLACK);
      tft.drawString("Credits", 268, 265);
      if (JoyStickY < -0.4){MenuPos = 0; delay(500);}
      else if (JoyStickX > 0.4){MenuPos = 2; delay(500);}
      if (button_A == 1){
        GameOnMenu = false;
        createMenu(3);
        SelectedMenu = true;
      }
    }
    else if (MenuPos == 2){
      tft.drawRoundRect(140, 170, 200, 60, 15, BLACK);
      tft.drawRoundRect(139, 169, 202, 62, 15, BLACK);
      tft.drawRoundRect(110, 250, 120, 40, 15, BLACK);
      tft.drawRoundRect(109, 249, 122, 42, 15, BLACK);
      tft.drawRoundRect(250, 250, 120, 40, 15, WHITE);
      tft.drawRoundRect(249, 249, 122, 42, 15, WHITE);
      tft.setTextColor(BLACK);
      tft.setTextSize(3);
      tft.drawString("Start Game", 150, 190);
      tft.setTextSize(2);
      tft.drawString("Controls", 122, 265);
      tft.setTextColor(WHITE);
      tft.drawString("Credits", 268, 265);
      if (JoyStickY < -0.4){
        MenuPos = 0;
        delay(500);
      }
      else if (JoyStickX < -0.4){
        MenuPos = 1;
        delay(500);
      }
      if (button_A == 1){
        GameOnMenu = false;
        createMenu(4);
        SelectedMenu = true;
      }
    }
  }
  // Rereads the button value to prevent looping
  button_A = digitalRead(BUTTON_A_PIN);
  // Logic needed for menu movement
  if (SelectedMenu == true){
    if (button_A == 1 && (MenuPos == 2 || MenuPos == 3)){
      createMenu(0);
      GameOnMenu = true;
      SelectedMenu = false;
      if (MenuPos == 3){MenuPos = 1;}
    }
  }
  if (SelectedMenu == true && MenuPos == 1){
    if (button_A == 1){
      createMenu(6);
      MenuPos = 3;      
    }
  }
  // Selector for Sub Menu UI.                                                                                                                      `
  if (GamePaused == true){
    if (level == 0){
      tft.drawRect(40, 180, 60, 80, WHITE);
      tft.drawRect(125, 180, 60, 80, BLACK);
      tft.setTextColor(WHITE);
      tft.setTextSize(6);
      tft.drawString("M", 55, 203);
      tft.setTextColor(BLACK);
      tft.drawString("1", 140, 203);
      if (JoyStickX > 0.4){
        level = 1;
        delay(500);
      }
      if (button_A == 1){
        createMenu(0);
        GamePaused = false;
        GameOnMenu = true;
        MenuPos = 0;
        level = 0;
        delay(500);
      }
    }
    else if (level == 1){
      tft.drawRect(40, 180, 60, 80, BLACK);
      tft.drawRect(125, 180, 60, 80, WHITE);
      tft.drawRect(210, 180, 60, 80, BLACK);
      tft.setTextColor(BLACK);
      tft.setTextSize(6);
      tft.drawString("M", 55, 203);
      tft.drawString("2", 225, 203);
      tft.setTextColor(WHITE);
      tft.drawString("1", 140, 203);
      if (JoyStickX < -0.4){
        level = 0;
        delay(500);
      }
      else if (JoyStickX > 0.4){
        level = 2;
        delay(500);
      }
      if (button_A == 1){
        createLevel(1);
        GamePaused = false;
        GameRun = true;
        level = 1;
      }
    }
    else if (level == 2){
      tft.drawRect(125, 180, 60, 80, BLACK);
      tft.drawRect(210, 180, 60, 80, WHITE);
      tft.drawRect(295, 180, 60, 80, BLACK);
      tft.setTextColor(BLACK);
      tft.setTextSize(6);
      tft.drawString("1", 140, 203);
      tft.drawString("3", 310, 203);
      tft.setTextColor(WHITE);
      tft.drawString("2", 225, 203);
      if (JoyStickX < -0.4){
        level = 1;
        delay(500);
      }
      else if (JoyStickX > 0.4){
        level = 3;
        delay(500);
      }
      if (button_A == 1){
        createLevel(2);
        GamePaused = false;
        GameRun = true;
        level = 2;
      }
    }
    else if (level == 3){
      tft.drawRect(210, 180, 60, 80, BLACK);
      tft.drawRect(295, 180, 60, 80, WHITE);
      tft.drawRect(380, 180, 60, 80, BLACK);
      tft.setTextColor(BLACK);
      tft.setTextSize(6);
      tft.drawString("2", 225, 203);
      tft.drawString("4", 395, 203);
      tft.setTextColor(WHITE);
      tft.drawString("3", 310, 203);
      if (JoyStickX < -0.4){
        level = 2;
        delay(500);
      }
      else if (JoyStickX > 0.4){
        level = 4;
        delay(500);
      }
      if (button_A == 1){
        createLevel(3);
        GamePaused = false;
        GameRun = true;
        level = 3;
      }
    }
    else if (level == 4){
      tft.drawRect(295, 180, 60, 80, BLACK);
      tft.drawRect(380, 180, 60, 80, WHITE);
      tft.setTextColor(BLACK);
      tft.setTextSize(6);
      tft.drawString("3", 310, 203);
      tft.setTextColor(WHITE);
      tft.drawString("4", 395, 203);
      if (JoyStickX < -0.4){
        level = 3;
        delay(500);
      }
      if (button_A == 1){
        createLevel(4);
        GamePaused = false;
        GameRun = true;
        level = 4;
      }      
    }
  }
  if (GameOnCutscene == true){
    if (CutscenePos == 1){
      if (button_A == 1){
        beginCutscene(2);
        CutscenePos = 2;
      }      
    }
    button_A = digitalRead(BUTTON_A_PIN);
    if (CutscenePos == 2){
      if (button_A == 1){
        beginCutscene(3);
        CutscenePos = 3;
      }      
    }
    button_A = digitalRead(BUTTON_A_PIN);
    if (CutscenePos == 3){
      if (button_A == 1){
        createLevel(1);
        GameRun = true;
        GameOnCutscene = false;
        CutscenePos = 0;
      }
    }
  }
  if (timerRound == 5){
    GameRun = false;
    createMenu(5);
    timerRound = 6;
  }
  if (timerRound == 6 && button_A == 1){
    createMenu(0);
    GameOnMenu = true;
  }
if (GameRun == true){
  // Draw the main character wherever the cursor is on screen. If statements help prevent overdrawing and drift.
  if (JoyStickX > 0.1 || JoyStickY > 0.1 || JoyStickX < -0.1 || JoyStickY < -0.1){
    tft.fillRect(int(posX-11), int(posY-11),22,22,characterColour);
    tft.fillRect(int(posX-8), int(posY-6), 5,5, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(posX+3), int(posY-6), 5,5, BLACK); //CUSTOMIZATION EYE
    tft.fillRect(int(posX-1), int(posY+3), 2,2, MAGENTA); //CUSTOMIZATION NOSE
    tft.fillRect(int(posX-7), int(posY-5),2,2, WHITE); // CUSTOMIZATION EYE
    tft.fillRect(int(posX+4), int(posY-5),2,2, WHITE); // CUSTOMIZATION EYE
    tft.drawFastHLine(int(posX-5), int(posY+6), 3, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawFastHLine(int(posX+2), int(posY+6), 3, MAGENTA); //CUSTOMIZATION NOSE
    tft.drawPixel(int(posX-6), int(posY+5), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(posX+5), int(posY+5), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(posX-2), int(posY+5), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawPixel(int(posX+1), int(posY+5), MAGENTA); // CUSTOMIZATION NOSE
    tft.drawFastHLine(int(posX-12), int(posY+11), 24, background); 
    tft.drawFastVLine(int(posX-12), int(posY-13), 25, background);
    tft.drawFastVLine(int(posX+11), int(posY-13), 25, background);
    tft.fillTriangle(int(posX-11), int(posY-12), int(posX-6), int(posY-17),int(posX-1), int(posY-12), characterColour);
    tft.fillTriangle(int(posX), int(posY-12), int(posX +5 ), int(posY - 17),int(posX+10), int(posY-12), characterColour);
    tft.fillTriangle(int(posX-8), int(posY-12), int(posX -6), int(posY - 14),int(posX-4), int(posY-12), MAGENTA); //CUSTOMIZATION EAR
    tft.fillTriangle(int(posX+3), int(posY-12), int(posX +5), int(posY - 14),int(posX+7), int(posY-12), MAGENTA); //CUSTOMIZATION EAR
    tft.drawLine(int(posX-11), int(posY-13), int(posX-6), int(posY-18), background);
    tft.drawLine(int(posX-11), int(posY-14), int(posX-7), int(posY-18), background);
    tft.drawLine(int(posX-5), int(posY-17), int(posX-1), int(posY-13), background);
    tft.drawLine(int(posX-5), int(posY-18), int(posX-1), int(posY-14), background);
    tft.drawLine(int(posX), int(posY-13), int(posX+5), int(posY-18), background);
    tft.drawLine(int(posX), int(posY-14), int(posX+4), int(posY-18), background);
    tft.drawLine(int(posX+6), int(posY-17), int(posX+10), int(posY-13), background);
    tft.drawLine(int(posX+6), int(posY-18), int(posX+10), int(posY-14), background);
  }
  if (counter > 0){
    counter -= 1;
  }
  else if (timerRound == 1){
    scoreG -= 1;
    scoreY += 1;
    obscureCounter += 1;
    if (obscureCounter == 4){
      scoreO += 1;
      obscureCounter = 0;
    }
    if (scoreY == 100){
      timerRound = 2;
    }
    counter = 44;
  }
    else if (timerRound == 2){
    scoreY -= 1;
    scoreO += 1;
    obscureCounter += 1;
    if (obscureCounter == 3){
      scoreR += 1;
      obscureCounter = 0;
    }
    if (scoreO == 100){
      timerRound = 3;
    }
    counter = 33;
  }
    else if (timerRound == 3){
    scoreO -= 1;
    scoreR += 1;
    obscureCounter += 1;
    if (obscureCounter == 2){
      scoreB += 1;
      obscureCounter = 0;
    }
    if (scoreR == 100){
      timerRound = 4;
    }
    counter = 25;
  }
    else if (timerRound == 4){
    scoreR -= 1;
    scoreB += 1;
    if (scoreB == 101){
      timerRound = 5;
    }
    counter = 20;
  }
  if (timerRound == 1){
    tft.fillRect(370, 290, scoreG, 20, GREEN);
    tft.fillRect(370+(100-(scoreY)), 290, scoreY-scoreO, 20, YELLOW);
    tft.fillRect(370+(100-(scoreO)), 290, scoreO, 20, ORANGE);
  }
  if (timerRound == 2){
    tft.fillRect(370, 290, scoreY-scoreO, 20, YELLOW);
    tft.fillRect(370+(100-(scoreO)), 290, scoreO-scoreR, 20, ORANGE);
    tft.fillRect(370+(100-(scoreR)), 290, scoreR, 20, RED);
  }
  if (timerRound == 3){
    tft.fillRect(370, 290, scoreO-scoreR, 20, ORANGE);
    tft.fillRect(370+(100-(scoreR)), 290, scoreR-scoreB, 20, RED);
    tft.fillRect(370+(100-(scoreB)), 290, scoreB, 20, BLACK);
  }
  if (timerRound == 4){
    tft.fillRect(370, 290, scoreR-scoreB, 20, RED);
    tft.fillRect(370+(100-(scoreB)), 290, scoreB, 20, BLACK);
  }
  if (level == 1){
    if (int(posX+12) > 156 && int(posX-12) < 176 && int(posY+12) > 250 && int(posY-18) < 275){ // Change to wear final tomato is
      createLevel(2);
      level = 2;
      // change for level 2
    }
    if (wallCollision == 1){checkCollision(wall_1_1, 1, 1);}
    if (wallCollision == 2){checkCollision(wall_1_2, 2, 1);}
    if (wallCollision == 3){checkCollision(wall_1_3, 3, 1);}  // DONT FORGET 0 AT END
    if (wallCollision == 4){checkCollision(wall_1_4, 4, 1);}
    if (wallCollision == 5){checkCollision(wall_1_5, 5, 1);}
    if (wallCollision == 6){checkCollision(wall_1_6, 6, 1);}
    if (wallCollision == 7){checkCollision(wall_1_7, 7, 1);}
    if (wallCollision == 8){checkCollision(wall_1_8, 8, 1);}
    if (wallCollision == 9){checkCollision(wall_1_9, 9, 1);}
    if (wallCollision == 10){checkCollision(wall_1_10, 10, 1);}
    if (wallCollision == 11){checkCollision(wall_1_11, 11, 1);}
    if (wallCollision == 12){checkCollision(wall_1_12, 12, 1);}
    if (wallCollision == 13){checkCollision(wall_1_13, 13, 1);}
    if (wallCollision == 14){checkCollision(wall_1_14, 14, 1);}
    if (wallCollision == 15){checkCollision(wall_1_15, 15, 1);}
    if (wallCollision == 16){checkCollision(wall_1_16, 16, 1);}
    if (wallCollision == 17){checkCollision(wall_1_17, 17, 1);}
    if (wallCollision == 18){checkCollision(wall_1_18, 18, 1);}
    if (wallCollision == 19){checkCollision(wall_1_19, 19, 1);}
    if (wallCollision == 20){checkCollision(wall_1_20, 20, 1);}
    if (wallCollision == 21){checkCollision(wall_1_21, 21, 1);}
    if (wallCollision == 22){checkCollision(wall_1_22, 22, 0);}

  }
  if (level == 2){
    if (wallCollision == 1){checkCollision(wall_2_1, 1, 1);}
    if (wallCollision == 2){checkCollision(wall_2_2, 2, 1);}
    if (wallCollision == 3){checkCollision(wall_2_3, 3, 1);}
    if (wallCollision == 4){checkCollision(wall_2_4, 4, 1);}
    if (wallCollision == 5){checkCollision(wall_2_5, 5, 1);}
    if (wallCollision == 6){checkCollision(wall_2_6, 6, 1);}
    if (wallCollision == 7){checkCollision(wall_2_7, 7, 1);}
    if (wallCollision == 8){checkCollision(wall_2_8, 8, 1);}
    if (wallCollision == 9){checkCollision(wall_2_9, 9, 1);}
    if (wallCollision == 10){checkCollision(wall_2_10, 10, 1);}
    if (wallCollision == 11){checkCollision(wall_2_11, 11, 1);}
    if (wallCollision == 12){checkCollision(wall_2_12, 12, 1);}
    if (wallCollision == 13){checkCollision(wall_2_13, 13, 1);}
    if (wallCollision == 14){checkCollision(wall_2_14, 14, 1);}
    if (wallCollision == 15){checkCollision(wall_2_15, 15, 1);}
    if (wallCollision == 16){checkCollision(wall_2_16, 16, 1);}
    if (wallCollision == 17){checkCollision(wall_2_17, 17, 1);}
    if (wallCollision == 18){checkCollision(wall_2_18, 18, 1);}
    if (wallCollision == 19){checkCollision(wall_2_19, 19, 1);}
    if (wallCollision == 20){checkCollision(wall_2_20, 20, 1);}
    if (wallCollision == 21){checkCollision(wall_2_21, 21, 1);}
    if (wallCollision == 22){checkCollision(wall_2_22, 22, 1);}
    if (wallCollision == 23){checkCollision(wall_2_23, 23, 1);}
    if (wallCollision == 24){checkCollision(wall_2_24, 24, 1);}
    if (wallCollision == 25){checkCollision(wall_2_25, 25, 0);}
    if (int(posX+12) > 279 && int(posX-12) < 299 && int(posY+12) > 106 && int(posY-18) < 126){
      createLevel(3);
      level = 3;
    }
  }
  if (level == 3){
    if (int(posX+12) > 260 && int(posX-12) < 290 && int(posY+12) > 250 && int(posY-18) < 274){
      createLevel(4);
      level = 4;
    }
    if (wallCollision == 1){checkCollision(wall_3_1, 1, 1);}
    if (wallCollision == 2){checkCollision(wall_3_2, 2, 1);}
    if (wallCollision == 3){checkCollision(wall_3_3, 3, 1);}
    if (wallCollision == 4){checkCollision(wall_3_4, 4, 1);}
    if (wallCollision == 5){checkCollision(wall_3_5, 5, 1);}
    if (wallCollision == 6){checkCollision(wall_3_6, 6, 1);}
    if (wallCollision == 7){checkCollision(wall_3_7, 7, 1);}
    if (wallCollision == 8){checkCollision(wall_3_8, 8, 1);}
    if (wallCollision == 9){checkCollision(wall_3_9, 9, 1);}
    if (wallCollision == 10){checkCollision(wall_3_10, 10, 1);}
    if (wallCollision == 11){checkCollision(wall_3_11, 11, 1);}
    if (wallCollision == 12){checkCollision(wall_3_12, 12, 1);}
    if (wallCollision == 13){checkCollision(wall_3_13, 13, 1);}
    if (wallCollision == 14){checkCollision(wall_3_14, 14, 1);}
    if (wallCollision == 15){checkCollision(wall_3_15, 15, 1);}
    if (wallCollision == 16){checkCollision(wall_3_16, 16, 1);}
    if (wallCollision == 17){checkCollision(wall_3_17, 17, 1);}
    if (wallCollision == 18){checkCollision(wall_3_18, 18, 1);}
    if (wallCollision == 19){checkCollision(wall_3_19, 19, 1);}
    if (wallCollision == 20){checkCollision(wall_3_20, 20, 0);}
  }
  if (level == 4){
    if (int(posX+12) > 260 && int(posX-12) < 288 && int(posY+12) > 250 && int(posY-18) < 270){
      createMenu(2);
      GameRun = false;
    }
    if (wallCollision == 1){checkCollision(wall_4_1, 1, 1);}
    if (wallCollision == 2){checkCollision(wall_4_2, 2, 1);}
    if (wallCollision == 3){checkCollision(wall_4_3, 3, 1);}
    if (wallCollision == 4){checkCollision(wall_4_4, 4, 1);}
    if (wallCollision == 5){checkCollision(wall_4_5, 5, 1);}
    if (wallCollision == 6){checkCollision(wall_4_6, 6, 1);}
    if (wallCollision == 7){checkCollision(wall_4_7, 7, 1);}
    if (wallCollision == 8){checkCollision(wall_4_8, 8, 1);}
    if (wallCollision == 9){checkCollision(wall_4_9, 9, 1);}
    if (wallCollision == 10){checkCollision(wall_4_10, 10, 1);}
    if (wallCollision == 11){checkCollision(wall_4_11, 11, 1);}
    if (wallCollision == 12){checkCollision(wall_4_12, 12, 1);}
    if (wallCollision == 13){checkCollision(wall_4_13, 13, 1);}
    if (wallCollision == 14){checkCollision(wall_4_14, 14, 1);}
    if (wallCollision == 15){checkCollision(wall_4_15, 15, 1);}
    if (wallCollision == 16){checkCollision(wall_4_16, 16, 1);}
    if (wallCollision == 17){checkCollision(wall_4_17, 17, 1);}
    if (wallCollision == 18){checkCollision(wall_4_18, 18, 1);}
    if (wallCollision == 19){checkCollision(wall_4_19, 19, 0);}
  }
  }
}  