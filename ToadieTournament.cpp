#include "raylib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#define STORAGE_DATA_FILE   "storage.data"

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING, FINISH, PG2, SCRAP } GameScreen;

typedef enum {
    STORAGE_POSITION_SCORE = 0,
    STORAGE_POSITION_HISCORE = 1,
    STORAGE_BAIT_CLASS = 2,
    STORAGE_VAPE_COUNT = 3,
    STORAGE_TOKEN_COUNT = 4,
    STORAGE_BOAT_CLASS = 5
} StorageData;

static bool SaveStorageValue(unsigned int position, int value);
static int LoadStorageValue(unsigned int position);

class ShopBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 45, GRAY);
        DrawText("SHOP", x, y, 30, WHITE);
    }
};
class vapeRepelBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 45, GRAY);
        DrawText("Repel?", x, y, 30, WHITE);
    }
};
class savBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 45, WHITE);
        DrawText("SAVE", x, y, 30, BLACK);
    }
};
class lodBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 45, BLACK);
        DrawText("LOAD", x, y, 30, WHITE);
    }
};

class AdvBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 45, RED);
        DrawText("SHOP", x, y, 30, WHITE);
    }
};

class charmBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 35, GRAY);
        DrawText("BUY", x, y, 30, WHITE);
    }
};

class exitBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 35, GRAY);
        DrawText("BUY", x, y, 30, WHITE);
    }
};
class convBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 35, GRAY);
        DrawText(" COP", x, y, 30, WHITE);
    }
};
class erodBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 35, GRAY);
        DrawText(" COP", x, y, 30, WHITE);
    }
};

class oilBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 35, GRAY);
        DrawText("BUY", x, y, 30, WHITE);
    }
};

class breadBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 35, GRAY);
        DrawText("BUY", x, y, 30, WHITE);
    }
};
class sinkerBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 35, GRAY);
        DrawText("BUY", x, y, 30, WHITE);
    }
};

class vapeBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 35, GRAY);
        DrawText("BUY", x, y, 30, WHITE);
    }
};

class mnmBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 35, GRAY);
        DrawText("BUY", x, y, 30, WHITE);
    }
};
class scrapBTN {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 80, 35, GRAY);
        DrawText(" COP", x, y, 30, WHITE);
    }
};

class MouseHitbox {
public:
    float x, y;
    void Draw() {
        DrawRectangle(x, y, 20, 20, YELLOW);
    }
};

class Toadie {
public:
    float x, y;
    float hitbox;
    int speed;
    void Spawn() {
        DrawRectangle(x, y, hitbox + 25, 10, WHITE);
    }
    void Update() {
        x += speed;
    }
};

class GoldenPuffer {
public:
    float x, y;
    float hitbox;
    int speed;
    void Spawn() {
        DrawRectangle(x, y, hitbox + 25, 10, WHITE);
    }
    void Update() {
        x += speed;
    }
};

class Rubbish {
public:
    float x, y;
    float hitbox;
    int speed;
    void Spawn() {
        DrawRectangle(x, y, hitbox, 20, WHITE);
    }
    void Update() {
        x += speed;
    }
};

class PygmyLeatherjacket {
public:
    float x, y;
    float hitbox;
    int speed;
    void Spawn() {
        DrawRectangle(x, y, hitbox + 25, 10, GREEN);
    }
    void Update() {
        x += speed;
    }
};
class mysteryFish {
public:
    float x, y;
    float hitbox;
    int speed;
    void Spawn() {
        DrawRectangle(x, y, hitbox + 25, 30, WHITE);
    }
    void Update() {
        y += speed;
    }
};
class trash {
public:
    float x, y;
    float hitbox;
    int speed;
    void Spawn() {
        DrawRectangle(x, y, hitbox, 10, RED);
    }
    void Update() {
        y += speed;
    }
};

class Hook {
public:
    float x, y;
    float hitbox;
    bool isHookedT;
    bool isHookedP;
    bool isHookedR;
    bool isHookedG;
    float speed;
    int reelSpeed;
    int lineY;
    int lineX;
    void Draw() {
        DrawRectangle(x, y, hitbox, 5, BLACK);
        DrawLine(lineX, lineY, x, y, BLACK);
    }
    void Update() {
        if (IsKeyDown(KEY_SPACE)) {
            y -= speed;
        }
        if (IsKeyDown(KEY_W)) {
            y -= reelSpeed;

        }
        if (y + hitbox >= 450) { 
            y = 450 - hitbox;
        }
        y += speed;
    }
};

Toadie toadie;
Hook hook;
MouseHitbox mHitbox;
ShopBTN shopbtn;
mnmBTN mnmbtn;
PygmyLeatherjacket pygLJ;
Rubbish rubbish;
breadBTN breadbtn;
GoldenPuffer goldenpuffer;
sinkerBTN sinkerbtn;
vapeBTN vapebtn;
charmBTN charmbtn;
oilBTN oilbtn;
exitBTN exitbtn;
AdvBTN advbtn;
savBTN savbtn;
lodBTN lodbtn;
vapeRepelBTN vaperepelbtn;
convBTN convbtn;
erodBTN erodbtn;
scrapBTN scrapbtn;
mysteryFish mysteryfish;
trash Trash;
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Toadie Tournament");

    GameScreen currentScreen = LOGO;

    InitAudioDevice();


    //Imports
    
    Music intro = LoadMusicStream("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/intro.mp3");
    Music forthenight = LoadMusicStream("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/forthenight.mp3");
    Music BgNoise = LoadMusicStream("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/bgnoise.mp3");
    Music lease = LoadMusicStream("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/lease.mp3");
    Image toadieIMG = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/toadfishsmooth2.png");
    Texture2D toadieImg = LoadTextureFromImage(toadieIMG);
    Image gigglesIMG = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/giggles.png");
    Texture2D gigglesImg = LoadTextureFromImage(gigglesIMG);
    Image TRASHIMG = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/trash_2.png");
    Texture2D TRASH_IMG = LoadTextureFromImage(TRASHIMG);
    Image bg = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/bgpier.png");
    Texture2D BG = LoadTextureFromImage(bg);
    Image MM = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/mm.png");
    Texture2D mm = LoadTextureFromImage(MM);
    Image bread = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/bread.png");
    Texture2D BREAD = LoadTextureFromImage(bread);
    Image hookImg = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/hook.png");
    Texture2D hookIMG = LoadTextureFromImage(hookImg);
    Image pygljimg = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/pygLJimg.png");
    Image vapeImg = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/vape.png");
    Texture2D vape = LoadTextureFromImage(vapeImg);
    Image bgTitle = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/bgTitle.png");
    Texture2D bgtitle = LoadTextureFromImage(bgTitle);
    Texture2D pygljimG = LoadTextureFromImage(pygljimg);
    Image goldenImg = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/puffergolden.png");
    Texture2D goldenIMG = LoadTextureFromImage(goldenImg);
    Image mysteryImg = LoadImage("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/mysteryfish.png");
    Texture2D mysteryIMG = LoadTextureFromImage(mysteryImg);
    Sound alarm = LoadSound("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/Downloads/alarm.mp3");
    Sound correct = LoadSound("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/correct.mp3");
    Sound uibtn = LoadSound("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/uibtn.mp3");
    Sound corAc = LoadSound("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/correctaction.mp3");
    Font font = LoadFontEx("C:/Users/info/source/repos/ToadieTournament/x64/ToadieTournament/lib/font.otf", 64, 0, NULL);
    int score = 0;
    //int comboRNG = GetRandomValue(1, 4);
    int comboRNG = 1;
    int framesCounter = 0;          

    int baitClass = 0;
    int upgdClass = 0;
    int vapeCount = 0;
    int tokenCount = 0;
    int boatClass = 0;
    int mysteryfishScore = 0;
    int streak = 0;
    int trashRng = GetRandomValue(1, 3);
    SetExitKey(KEY_NULL);

    hook.lineY = screenHeight / 3;
    hook.lineX = screenWidth / 4;

    bool boughtMNM = false;
    bool boughtBREAD = false;
    bool boughtSINKER = false;
    bool boughtVAPE = false;
    bool boughtCHARM = false;
    bool boughtOIL = false;
    bool boughtEXIT = false;
    bool boughtEROD = false;
    bool boughtSCRAP = false;
    SetTargetFPS(60);               
    bool trashSpawn = false;
    //Set class variable values
    // trash
    Trash.x = -10;
    Trash.y = -20;
    Trash.hitbox = 25;
    Trash.speed = 7;
    
    // mystery fish
    mysteryfish.x = screenWidth / 2;
    mysteryfish.y = -20;
    mysteryfish.hitbox = 25;
    mysteryfish.speed = 7;
    //toadie
    toadie.x = GetRandomValue(10 + toadie.hitbox, 700 + toadie.hitbox);
    toadie.y = toadie.y = GetRandomValue(450 / 2, 415 + toadie.hitbox);
    toadie.hitbox = 20;
    toadie.speed = 5;
    //Rubbish
    rubbish.hitbox = 10;
    rubbish.speed = 4;
    rubbish.x = GetRandomValue(10 + rubbish.hitbox, 700 + rubbish.hitbox);
    rubbish.y = GetRandomValue(450 / 2, 415 + rubbish.hitbox);
    //Pygmy LeatehrJacket
    pygLJ.hitbox = 15;
    pygLJ.speed = 3;
    pygLJ.x = GetRandomValue(10 + pygLJ.hitbox, 700 + pygLJ.hitbox);
    pygLJ.y = GetRandomValue(450 / 2, 415 + pygLJ.hitbox);
    //Golden Puffer
    goldenpuffer.hitbox = 35;
    goldenpuffer.speed = 4;
    goldenpuffer.x = GetRandomValue(10 + goldenpuffer.hitbox, 700 + goldenpuffer.hitbox);
    goldenpuffer.y = GetRandomValue(450 / 2, 400 - goldenpuffer.hitbox);
    //Hook
    hook.x = screenWidth / 4;
    hook.y = screenHeight / 3;
    hook.speed = 1;
    hook.hitbox = 20;
    hook.isHookedT = false;
    hook.isHookedP = false;
    hook.isHookedG = false;
    hook.reelSpeed = 2;
    bool landed = false;
    bool antiRepel = false;
    //Texture stuff
    toadieImg.width = 100;
    toadieImg.height = 50;
    pygljimG.width = 75;
    pygljimG.height = 50;
    vape.width = 50;
    vape.height = 50;
    BG.width = screenWidth;
    BG.height = screenHeight;
    goldenIMG.width = 100;
    goldenIMG.height = 50;
    bgtitle.width = screenWidth;
    bgtitle.height = screenHeight;
    BREAD.width = 25;
    BREAD.height = 25;
    mm.width = 25;
    mm.height = 25;
    mysteryIMG.width = 100;
    mysteryIMG.height = 75;
    gigglesImg.width = 45;
    gigglesImg.height = 70;
    bool rubbishSpawn = false;
    // shop btn
    shopbtn.x = screenWidth - 85;
    shopbtn.y = 20;
    advbtn.x = screenWidth - 85;
    advbtn.y = 70;
    // sav btn
    savbtn.x = screenWidth / 3;
    savbtn.y = 400;
    lodbtn.x = screenWidth / 2;
    lodbtn.y = 400;
    // vape btn
    vaperepelbtn.x = screenWidth - 85;
    vaperepelbtn.y = 125;
    while (!WindowShouldClose())    
    {

        switch (currentScreen)
        {
        case LOGO:
        {
            // TODO: Update LOGO screen variables here!

            framesCounter++;    // Count frames

            UpdateMusicStream(intro);
            PlayMusicStream(intro);

            // Wait for 2 seconds (120 frames) before jumping to TITLE screen
            if (framesCounter > 255)
            {
                currentScreen = TITLE;
            }
        } break;
        case TITLE:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = GAMEPLAY;
            }
        } break;
        case GAMEPLAY:
        {
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ shopbtn.x, shopbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
                currentScreen = ENDING;
                PlaySound(uibtn);
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ advbtn.x, advbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && upgdClass >= 4) {
                currentScreen = FINISH;
                PlaySound(uibtn);
            }
            UpdateMusicStream(BgNoise);
            PlayMusicStream(BgNoise);
        } break;
        case ENDING:
        {
            if (IsKeyPressed(KEY_ESCAPE))
            {
                currentScreen = GAMEPLAY;
            }
        } break;
        case FINISH: 
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = GAMEPLAY;
            }
        } break;
        case PG2:
        {
            mHitbox.x = GetMouseX();
            mHitbox.y = GetMouseY();
        } break;
        case SCRAP:
        {
            mHitbox.x = GetMouseX();
            mHitbox.y = GetMouseY();
            hook.lineY = 0;
            hook.lineX = GetMouseX();
            hook.x = GetMouseX();
            hook.y = GetMouseY();
        }
        default: break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        switch (currentScreen)
        {
        case LOGO:
        {
            DrawText("Gretch Ware", screenWidth / 5, screenHeight / 2, 75, GREEN);
            if (framesCounter >= 90) {
                DrawText("Presents...", screenWidth / 4, screenHeight / 3, 75, GREEN);
            }
            if (framesCounter >= 125) {
                DrawText("Presents...", screenWidth / 5, screenHeight / 5, 75, RED);
            }
            if (framesCounter >= 155) {
                DrawText("Presents...", screenWidth / 12, screenHeight / 12, 75, BLUE);
            }
            if (framesCounter >= 200) {
                DrawTexture(toadieImg, screenWidth /5, screenHeight-100, WHITE);
            }

        } break;
        case TITLE:
        {
            mHitbox.x = GetMouseX();
            mHitbox.y = GetMouseY();
            // TODO: Draw TITLE screen here!
            DrawTexture(bgtitle, 0, 0, WHITE);
            DrawText("TOADIE TOURNAMENT", 20, 20, 40, BLACK);
            DrawText("PRESS ENTER TO PLAY", 120, 220, 20, BLACK);
            UpdateMusicStream(lease);
            PlayMusicStream(lease);
            framesCounter = 0;
            savbtn.Draw();
            lodbtn.Draw();
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ savbtn.x, savbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
                SaveStorageValue(STORAGE_POSITION_SCORE, score);
                SaveStorageValue(STORAGE_POSITION_HISCORE, upgdClass);
                SaveStorageValue(STORAGE_BAIT_CLASS, baitClass);
                SaveStorageValue(STORAGE_VAPE_COUNT, vapeCount);
                SaveStorageValue(STORAGE_TOKEN_COUNT, tokenCount);
                SaveStorageValue(STORAGE_BOAT_CLASS, boatClass);
                PlaySound(uibtn);
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ lodbtn.x, lodbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
                score = LoadStorageValue(STORAGE_POSITION_SCORE);
                upgdClass = LoadStorageValue(STORAGE_POSITION_HISCORE);
                baitClass = LoadStorageValue(STORAGE_BAIT_CLASS);
                vapeCount = LoadStorageValue(STORAGE_VAPE_COUNT);
                tokenCount = LoadStorageValue(STORAGE_TOKEN_COUNT);
                boatClass = LoadStorageValue(STORAGE_BOAT_CLASS);
                PlaySound(uibtn);
            }

        } break;
        case GAMEPLAY:
        {

            if (score < 0) {
                score == 0;
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                currentScreen = TITLE;
            }
            bool hit1 = false;
            bool hit2 = false;
            bool pygLJspawn = false;
            bool goldenSpawn = false;

            if (baitClass >= 1) {
                pygLJspawn = true;
                rubbishSpawn = true;
            }

            if (baitClass >= 2){
                pygLJspawn = true;
                rubbishSpawn = true;
                goldenSpawn = true;
            }

            if (upgdClass >= 1 && IsKeyDown(KEY_S)) {
                hook.y += 3;
            }
            if (upgdClass >= 2 && antiRepel == false) {
                rubbish.x = -10;
                rubbish.y = -10;
            }
            mHitbox.x = GetMouseX();
            mHitbox.y = GetMouseY();

            framesCounter++;

            if (upgdClass >= 4) {
                if (framesCounter == 120) {
                    score++;
                }
            }

            //Anything above the rectangle func will be invisible!
            DrawTexture(BG, 0, 0, WHITE);
            DrawText(TextFormat("Balance: %i",score), 20, 20, 40, BLACK);
            hook.Draw();
            hook.Update();
            toadie.Update();
            toadie.Spawn();
            shopbtn.Draw();
            DrawTexture(toadieImg, toadie.x - 25, toadie.y - 25, WHITE);

            if (IsKeyDown(KEY_W) && boughtEROD == true) {
                hook.y -= 3;
            }
            if (IsKeyPressed(KEY_L) && boatClass == 1) {
                currentScreen = SCRAP;
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ vaperepelbtn.x, vaperepelbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && upgdClass >= 2 && antiRepel == false) {
                antiRepel = true;
                rubbish.x = GetRandomValue(10 + rubbish.hitbox, 700 + rubbish.hitbox);
                rubbish.y = GetRandomValue(450 / 2, 415 + rubbish.hitbox);
                DrawText("ACTIVATED", screenWidth / 2, screenHeight / 2, 30, WHITE);
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ vaperepelbtn.x, vaperepelbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) == true && upgdClass >= 2 && antiRepel == true) {
                antiRepel = false;
                DrawText("DEACTIVATED", screenWidth / 2, screenHeight / 2, 30, WHITE);
            }
            rubbish.Spawn();
            if (upgdClass >= 2) {
                vaperepelbtn.Draw();
            }

            if (baitClass == 1) {
                DrawTexture(BREAD, hook.x, hook.y-15, WHITE);
            }
            if (baitClass == 2) {
                DrawTexture(mm, hook.x, hook.y-15, WHITE);
            }

            if (upgdClass >= 4) {
                advbtn.Draw();
            }

            if (toadie.x >= screenWidth) {
                toadie.x = 0;
            }

            if (pygLJ.x >= screenWidth) {
                pygLJ.x = 0;
            }
            if (rubbish.x >= screenWidth) {
                rubbish.x = 0;
            }

            if (goldenpuffer.x >= screenWidth) {
                goldenpuffer.x = 0;
            }

            if (rubbishSpawn == true || antiRepel == true) {
                DrawTexture(vape, rubbish.x - 25, rubbish.y - 25, WHITE);
                rubbish.x += rubbish.speed;
            }

            if (goldenSpawn == true && comboRNG == 3 && upgdClass <= 3) {
                DrawTexture(goldenIMG, goldenpuffer.x - 25, goldenpuffer.y - 25, WHITE);
                goldenpuffer.x += goldenpuffer.speed;
            }
            if (upgdClass >= 3) {
                DrawTexture(goldenIMG, goldenpuffer.x - 25, goldenpuffer.y - 25, WHITE);
                goldenpuffer.x += goldenpuffer.speed;
                DrawTexture(pygljimG, pygLJ.x - 25, pygLJ.y - 25, WHITE);
                pygLJ.x += pygLJ.speed;
            }

            //spawning of pygLJ
            if (pygLJspawn == true && comboRNG >= 2) {
                DrawTexture(pygljimG, pygLJ.x - 25, pygLJ.y - 25, WHITE);
                pygLJ.x += pygLJ.speed;
            }

            if (landed == false && hook.isHookedP == true && comboRNG == 4) {
                DrawText("[!] LET LINE OUT [!]", screenWidth / 2, screenHeight / 2, 25, WHITE);
                if (framesCounter <= 60 && IsKeyPressed(KEY_DOWN)) {
                    DrawText("Well Done!", screenWidth / 2, screenHeight / 2, 100, BLACK);
                    landed = true;
                    score++;
                    PlaySound(corAc);
                }
                if (framesCounter >= 60) {
                    DrawText("Failure", screenWidth / 2, screenHeight / 2, 100, BLACK);
                    PlaySound(alarm);
                    score += -3;
                    landed = true;
                }
            }

            if (framesCounter >= 65 && landed == false && hook.isHookedT == true && comboRNG == 1 || framesCounter >= 50 && landed == false && hook.isHookedP == true && comboRNG == 1 || framesCounter >= 50 && landed == false && hook.isHookedG == true && comboRNG == 1) {
                score += -3;
                DrawText("Failure", screenWidth / 2, screenHeight / 2, 100, BLACK);
                landed = true;
                PlaySound(alarm);               
            }

            if (comboRNG == 1 && landed == false && hook.isHookedT == true || comboRNG == 1 && landed == false && hook.isHookedP == true || framesCounter >= 50 && landed == false && hook.isHookedG == true && comboRNG == 1) {
                DrawText("[!] PULL UP [!]", screenWidth / 2, screenHeight / 2, 25, WHITE);
                if (framesCounter <= 60 && IsKeyPressed(KEY_UP)) {
                    DrawText("Well Done!", screenWidth / 2, screenHeight / 2, 100, BLACK);
                    score++;
                    PlaySound(corAc);
                    landed = true;
                }
            }

            if (framesCounter >= 65 && landed == false && hook.isHookedT == true && comboRNG == 2 || framesCounter >= 50 && landed == false && hook.isHookedP == true && comboRNG == 2 || framesCounter >= 50 && landed == false && hook.isHookedG == true && comboRNG == 1) {
                score += -3;
                DrawText("Failure", screenWidth / 2, screenHeight / 2, 100, BLACK);
                landed = true;
                PlaySound(alarm);
            }

            if (comboRNG == 2 && landed == false && hook.isHookedT == true || comboRNG == 2 && landed == false && hook.isHookedP == true || framesCounter >= 50 && landed == false && hook.isHookedG == true && comboRNG == 1) {
                DrawText("[!] PULL LEFT [!]", screenWidth / 2, screenHeight / 2, 25, WHITE);
                if (framesCounter <= 60 && IsKeyPressed(KEY_LEFT)) {
                    DrawText("Well Done!", screenWidth / 2, screenHeight / 2, 100, BLACK);
                    score++;
                    PlaySound(corAc);
                    landed = true;
                }
            }

            if (framesCounter >= 65 && landed == false && hook.isHookedT == true && comboRNG == 3 || framesCounter >= 50 && landed == false && hook.isHookedP == true && comboRNG == 3 || framesCounter >= 50 && landed == false && hook.isHookedG == true && comboRNG == 1) {
                score += -3;
                DrawText("Failure", screenWidth / 2, screenHeight / 2, 100, BLACK);
                landed = true;
                PlaySound(alarm);
            }

            if (comboRNG == 3 && landed == false && hook.isHookedT == true || comboRNG == 3 && landed == false && hook.isHookedP == true || framesCounter >= 50 && landed == false && hook.isHookedG == true && comboRNG == 1) {
                DrawText("[!] PULL RIGHT [!]", screenWidth / 2, screenHeight / 2, 25, WHITE);
                if (framesCounter <= 60 && IsKeyPressed(KEY_RIGHT)) {
                    DrawText("Well Done!", screenWidth / 2, screenHeight / 2, 100, BLACK);
                    score++;
                    PlaySound(corAc);
                    landed = true;
                }
            }

            if (framesCounter == 120) {
                framesCounter = 0;
            }
            //Collisions
            if (CheckCollisionRecs(Rectangle {toadie.x, toadie.y, toadie.hitbox + 25, 10}, Rectangle{hook.x, hook.y, hook.hitbox, 5})) {
                toadie.x = hook.x;
                toadie.y = hook.y;
                if (hook.isHookedT == false) {
                    framesCounter = 0;
                    hook.isHookedT = true;
                }               
            }

            if (CheckCollisionRecs(Rectangle{ pygLJ.x, pygLJ.y, pygLJ.hitbox + 25, 10 }, Rectangle{ hook.x, hook.y, hook.hitbox, 5 })) {
                pygLJ.x = hook.x;
                pygLJ.y = hook.y;
                if (hook.isHookedP == false) {
                    framesCounter = 0;
                    hook.isHookedP = true;
                }
            }

            if (CheckCollisionRecs(Rectangle{ rubbish.x, rubbish.y, rubbish.hitbox + 25, 10 }, Rectangle{ hook.x, hook.y, hook.hitbox, 5 })) {
                rubbish.x = hook.x;
                rubbish.y = hook.y;
                if (hook.isHookedR == false) {
                    framesCounter = 0;
                    hook.isHookedR = true;
                }
            }

            if (CheckCollisionRecs(Rectangle{ goldenpuffer.x, goldenpuffer.y, goldenpuffer.hitbox + 25, 10 }, Rectangle{ hook.x, hook.y, hook.hitbox, 5 })) {
                goldenpuffer.x = hook.x;
                goldenpuffer.y = hook.y;
                if (hook.isHookedG == false) {
                    framesCounter = 0;
                    hook.isHookedG = true;
                }
            }
            if (hook.y <= screenHeight / 3) {
                hook.y = screenHeight / 3;
            }

            if (hook.y <= screenHeight / 3 && hook.isHookedG == true) {
                hook.y = screenHeight / 3;
                score += 6;
                goldenpuffer.x = GetRandomValue(10 + goldenpuffer.hitbox, 750 + goldenpuffer.hitbox);
                goldenpuffer.y = GetRandomValue(450 / 2, 400 - goldenpuffer.hitbox);
                hook.isHookedG = false;
                landed = false;
                comboRNG = GetRandomValue(1, 4);
                PlaySound(correct);
            }

            if (hook.y <= screenHeight / 3 && hook.isHookedP == true) {
                hook.y = screenHeight / 3;
                score += 3;
                pygLJ.x = GetRandomValue(10 + pygLJ.hitbox, 750 + pygLJ.hitbox);
                pygLJ.y = GetRandomValue(450 / 2, 415 + pygLJ.hitbox);
                hook.isHookedP = false;
                landed = false;
                comboRNG = GetRandomValue(1, 4);
                PlaySound(correct);
            }
            if (hook.y <= screenHeight / 3 && hook.isHookedT == true) {
                hook.y = screenHeight / 3;
                score += 1;
                toadie.x = GetRandomValue(10 + toadie.hitbox, 750 + toadie.hitbox);
                toadie.y = GetRandomValue(450 / 2, 415 + toadie.hitbox);
                hook.isHookedT = false;
                landed = false;
                comboRNG = GetRandomValue(1, 4);
                PlaySound(correct);
            }

            if (hook.y <= screenHeight / 3 && hook.isHookedR == true) {
                hook.y = screenHeight / 3;
                score += -3;
                vapeCount += 1;
                rubbish.x = GetRandomValue(10 + rubbish.hitbox, 750 + rubbish.hitbox);;
                rubbish.y = GetRandomValue(450 / 2, 415 + rubbish.hitbox);
                hook.isHookedR = false;
                landed = false;
                comboRNG = GetRandomValue(1, 4);
                PlaySound(alarm);
            }
        } break;
        case ENDING:
        {
            framesCounter++;
            DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);

            DrawText(TextFormat("Balance: %i", score), 385, 10, 35, WHITE);

            mHitbox.x = GetMouseX();
            mHitbox.y = GetMouseY();

            //button stuff (btn)

            mnmbtn.x = 350;
            mnmbtn.y = 130;
            mnmbtn.Draw();

            breadbtn.x = 350;
            breadbtn.y = 170;
            breadbtn.Draw();

            sinkerbtn.x = 375;
            sinkerbtn.y = 240;
            sinkerbtn.Draw();

            vapebtn.x = 550;
            vapebtn.y = 280;
            vapebtn.Draw();

            charmbtn.y = 320;
            charmbtn.x = 500;
            charmbtn.Draw();

            oilbtn.y = 360;
            oilbtn.x = 450;
            oilbtn.Draw();

            exitbtn.x = 490;
            exitbtn.y = 400;
            exitbtn.Draw();
            //Logic stuff

            if (framesCounter == 61) {
                framesCounter = 0;
            }

            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ mnmbtn.x, mnmbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && score >= 10 && boughtMNM == false) {
                score += -10;
                framesCounter = 0;
                baitClass = 1;
                boughtMNM = true;
                PlaySound(uibtn);
                
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("Bought M&M's!", screenWidth / 3, screenHeight - 50, 40, DARKGREEN);
                    framesCounter++;
                
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ breadbtn.x, breadbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && score >= 25 && boughtBREAD == false && boughtMNM == true) {
                score += -25;
                framesCounter = 0;
                baitClass = 2;
                boughtBREAD = true;
                PlaySound(uibtn);
                
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("Bought Bread!", screenWidth / 3, screenHeight - 50, 40, DARKGREEN);
                    framesCounter++;
                
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ sinkerbtn.x, sinkerbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && score >= 50 && boughtSINKER == false) {
                score += -50;
                framesCounter = 0;
                upgdClass = 1;
                boughtSINKER = true;
                PlaySound(uibtn);
                
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("Bought SINKER!", screenWidth / 3, screenHeight - 50, 40, DARKGREEN);
                    framesCounter++;
                
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ vapebtn.x, vapebtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && score >= 75 && boughtVAPE == false && boughtSINKER == true) {
                score += -75;
                framesCounter = 0;
                upgdClass = 2;
                boughtVAPE = true;
                PlaySound(uibtn);
                
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("Bought VAPE!", screenWidth / 3, screenHeight - 50, 40, DARKGREEN);
                    framesCounter++;
                
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ charmbtn.x, charmbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && score >= 100 && boughtVAPE == true && boughtSINKER == true && boughtCHARM == false) {
                score += -100;
                framesCounter = 0;
                upgdClass = 3;
                boughtCHARM = true;
                PlaySound(uibtn);
                
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("Bought CHARM!", screenWidth / 3, screenHeight - 50, 40, DARKGREEN);
                    framesCounter++;
                
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ oilbtn.x, oilbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && score >= 135 && boughtVAPE == true && boughtSINKER == true && boughtCHARM == true && boughtOIL == false) {
                score += -135;
                framesCounter = 0;
                upgdClass = 4;
                boughtOIL = true;
                PlaySound(uibtn);
                
                DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                DrawText("Bought an Oil Rig lol!", screenWidth / 3, screenHeight - 50, 40, DARKGREEN);
                framesCounter++;
                
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ exitbtn.x, exitbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && score >= 200 && boughtVAPE == true && boughtSINKER == true && boughtCHARM == true && boughtOIL == true) {
                score += -200;
                framesCounter = 0;
                upgdClass = 4;
                boughtEXIT = true;
                PlaySound(uibtn);
                
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("Bought an Oil Rig lol!", screenWidth / 3, screenHeight - 50, 40, DARKGREEN);
                    framesCounter++;
                
            }

            DrawText("Old Mates Tackle", 20, 20, 40, DARKBLUE);
            DrawText("BAITS: ", screenWidth / 5, 80, 35, WHITE);
            DrawText("Bread :: $10 ", screenWidth / 5, 130, 30, WHITE);
            DrawText("M&M's :: $25 ", screenWidth / 5, 170, 30, WHITE);
            DrawText("UPGRADES: ", screenWidth / 5, 200, 35, WHITE);
            DrawText("Sinker :: $50", screenWidth / 5, 240, 35, WHITE);
            DrawText("Vape Repellent :: $75", screenWidth / 5, 280, 35, WHITE);
            DrawText("Lucky Charm :: $100", screenWidth / 5, 320, 30, WHITE);
            DrawText("Oil Rig :: $135", screenWidth / 5, 360, 30, WHITE);
            DrawText("Boat Liscense :: $300", screenWidth / 5, 400, 30, WHITE);
            DrawText("-= Press Esc to exit shop =- ", screenWidth / 3, 425, 20, WHITE);


        } break;
        case FINISH:
        {
            tokenCount += 10;
            mHitbox.x = GetMouseX();
            mHitbox.y = GetMouseY();
            scrapbtn.x = 450;
            scrapbtn.y = 170;

            UpdateMusicStream(forthenight);
            PlayMusicStream(forthenight);
            DrawRectangle(0, 0, screenWidth, screenHeight, RED);
            DrawText("Giggles' Boats & Doohickeys - Page 1", 20, 20, 40, BLACK);
            DrawText("BOATS: ", screenWidth / 5, 80, 35, WHITE);
            DrawText("Scrap Metal with Mast :: $75 & 5 Giggle Tokens ", 20, 130, 30, WHITE);
            //("Tinny :: $250 ", screenWidth / 5, 170, 30, WHITE);
            //DrawText("Sail Boat :: 350", screenWidth / 5, 200, 30, WHITE);
            scrapbtn.Draw();
            DrawText("-= Press Right Arrow Key for Page 2  =- ", screenWidth / 4, 425, 20, WHITE);
            if (IsKeyPressed(KEY_RIGHT)) {
                currentScreen = PG2;
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ scrapbtn.x, scrapbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && score >= 75 && tokenCount >= 10 && boughtSCRAP == false) {
                tokenCount += -10;
                score += -75;
                boughtSCRAP = true;
                boatClass = 1;
                framesCounter = 0;
                PlaySound(uibtn);
                if (framesCounter <= 60) {
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    framesCounter++;
                }
            }
            framesCounter = 0;
        } break;
        case PG2:
        {
            convbtn.x = 510;
            convbtn.y = 180;

            erodbtn.x = 500;
            erodbtn.y = 220;

            UpdateMusicStream(forthenight);
            PlayMusicStream(forthenight);
            DrawRectangle(0, 0, screenWidth, screenHeight, RED);
            DrawTexture(gigglesImg, 20, 60, WHITE);
            DrawText("- Im always down to trade in Vapes for my Giggle Tokens!", 50, 60, 15, WHITE);
            DrawText("They allow you to buy special items only from me! Hectic lad bahh...", 65, 75, 15, WHITE);
            DrawText(TextFormat("You currently have %i", vapeCount), 65, 90, 15, WHITE);
            DrawText(TextFormat("Giggle Tokens: %i", tokenCount), screenWidth / 3, 400, 25, WHITE);
            DrawText("Not bad bah!", 240, 90, 15, WHITE);
            DrawText("Giggles' Boats & Doohickeys - Page 2", 20, 20, 40, BLACK);
            DrawText("Doohickeys: ", screenWidth / 5, 140, 35, WHITE);
            DrawText("Vape -> Giggle Token :: 2 Vapes ", screenWidth / 5, 180, 20, WHITE);
            DrawText("Electric Rod :: 5 Tokens ", screenWidth / 5, 220, 20, WHITE);
            DrawText("-= Press Left Arrow Key for Page 1  =- ", screenWidth / 4, 425, 20, WHITE);

            convbtn.Draw();
            erodbtn.Draw();

            if (IsKeyPressed(KEY_LEFT)) {
                currentScreen = FINISH;
            }
            if (IsKeyPressed(KEY_ENTER)) {
                currentScreen = GAMEPLAY;
            }
            framesCounter = 0;

            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ convbtn.x, convbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && vapeCount >= 2) {
                tokenCount += 1;
                vapeCount += -2;
                framesCounter = 0;
                PlaySound(uibtn);
                if (framesCounter <= 60) {
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    framesCounter++;
                }
            }
            if (CheckCollisionRecs(Rectangle{ mHitbox.x, mHitbox.y, 20, 20 }, Rectangle{ erodbtn.x, erodbtn.y, 80, 45 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true && tokenCount >= 10 && boughtEROD == false) {
                tokenCount += -10;
                boughtEROD = true;
                framesCounter = 0;
                PlaySound(uibtn);
                if (framesCounter <= 60) {
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    framesCounter++;
                }
            }

        }break;
        case SCRAP:
        {
            framesCounter++;
            DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
            DrawTexture(mysteryIMG, mysteryfish.x-25, mysteryfish.y-25, WHITE);
            DrawTexture(hookIMG, hook.x-10, hook.y, WHITE);
            DrawTexture(TRASH_IMG, Trash.x, Trash.y, WHITE);
            DrawLine(GetMouseX(), 0, hook.x, hook.y, BLACK);
            mysteryfish.Spawn();
            mysteryfish.Update();
            if (trashRng >= 2) {
                trashSpawn == true;
                Trash.Spawn();
                Trash.Update();
                if (Trash.y >= screenHeight) {
                    Trash.y = -20;
                    Trash.x = GetRandomValue(50, 750);
                    trashRng = GetRandomValue(1, 3);
                }
            }
            if (Trash.x == mysteryfish.x) {
                Trash.x += 20;
            }
            if (trashSpawn == true) {
                Trash.x = GetRandomValue(50, 750);
                trashSpawn = false;
            }
            if (framesCounter >= 120) {
                framesCounter = 0;
            }
            if (framesCounter == 119) {
                trashRng = GetRandomValue(1, 3);
            }
            if (mysteryfish.y >= screenHeight) {
                streak -= streak;
                mysteryfish.y = -20;
                mysteryfish.x = GetRandomValue(50, 750);
            }
            if (CheckCollisionRecs(Rectangle{ mysteryfish.x, mysteryfish.y, mysteryfish.hitbox + 25, 10 }, Rectangle{ hook.x, hook.y, hook.hitbox, 5 })) {
                mysteryfish.x = GetRandomValue(50, 750);
                mysteryfish.y = -10;
                PlaySound(correct);
                mysteryfishScore++;
                streak++;
                if (streak >= 20 && streak <= 35) {
                    mysteryfishScore * 2;
                }
            }
            if (CheckCollisionRecs(Rectangle{ Trash.x, Trash.y, Trash.hitbox + 25, 10 }, Rectangle{ hook.x, hook.y, hook.hitbox, 5 })) {
                Trash.x = GetRandomValue(50, 750);
                Trash.y = -20;
                PlaySound(alarm);
                mysteryfishScore += -5;
                streak = 0;
            }
            if (CheckCollisionRecs(Rectangle{ Trash.x, Trash.y, Trash.hitbox + 25, 10 }, Rectangle{ mysteryfish.x, mysteryfish.y, mysteryfish.hitbox, 5 })) {
                Trash.x += 10;
            }
            DrawText(TextFormat("Score: %i", mysteryfishScore), 20, 20, 40, BLACK);
            DrawText(TextFormat("Streak: %i", streak), 20, 50, 40, BLACK);
            if (streak >= 10 && streak < 20) {
                mysteryfish.speed = 8;
                DrawTextEx(font, "Not Bad Lad!", Vector2{ screenWidth / 5, screenHeight / 2 }, 40, 0, BLACK);
                Trash.speed = 8;
            }
            if (streak == 0) {
                mysteryfish.speed = 7;
                Trash.speed = 7;
            }
            if (streak >= 20 && streak < 30) {
                mysteryfish.speed = 9;
                DrawTextEx(font, "Go on...", Vector2{ screenWidth / 5, screenHeight / 2 }, 40, 0, ORANGE);
                Trash.speed = 9;
            }
            if (streak >= 30) {
                mysteryfish.speed = 12;
                DrawTextEx(font, "DEMON TIME", Vector2{ screenWidth / 5, screenHeight / 2 }, 40, 0, DARKPURPLE);
                Trash.speed = 12;
            }
            if (IsKeyPressed(KEY_ESCAPE)) {
                currentScreen = GAMEPLAY;
            }
        }
        default: break;
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded data (textures, fonts, audio) here!
    UnloadMusicStream(BgNoise);
    UnloadMusicStream(intro);
    UnloadMusicStream(lease);
    UnloadSound(alarm);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    //UnloadMusicStream(intro);
    return 0;
}

// Save integer value to storage file (to defined position)
// NOTE: Storage positions is directly related to file memory layout (4 bytes each integer)
bool SaveStorageValue(unsigned int position, int value)
{
    bool success = false;
    int dataSize = 0;
    unsigned int newDataSize = 0;
    unsigned char* fileData = LoadFileData(STORAGE_DATA_FILE, &dataSize);
    unsigned char* newFileData = NULL;

    if (fileData != NULL)
    {
        if (dataSize <= (position * sizeof(int)))
        {
            // Increase data size up to position and store value
            newDataSize = (position + 1) * sizeof(int);
            newFileData = (unsigned char*)RL_REALLOC(fileData, newDataSize);

            if (newFileData != NULL)
            {
                // RL_REALLOC succeded
                int* dataPtr = (int*)newFileData;
                dataPtr[position] = value;
            }
            else
            {
                // RL_REALLOC failed
                TraceLog(LOG_WARNING, "FILEIO: [%s] Failed to realloc data (%u), position in bytes (%u) bigger than actual file size", STORAGE_DATA_FILE, dataSize, position * sizeof(int));

                // We store the old size of the file
                newFileData = fileData;
                newDataSize = dataSize;
            }
        }
        else
        {
            // Store the old size of the file
            newFileData = fileData;
            newDataSize = dataSize;

            // Replace value on selected position
            int* dataPtr = (int*)newFileData;
            dataPtr[position] = value;
        }

        success = SaveFileData(STORAGE_DATA_FILE, newFileData, newDataSize);
        RL_FREE(newFileData);

        TraceLog(LOG_INFO, "FILEIO: [%s] Saved storage value: %i", STORAGE_DATA_FILE, value);
    }
    else
    {
        TraceLog(LOG_INFO, "FILEIO: [%s] File created successfully", STORAGE_DATA_FILE);

        dataSize = (position + 1) * sizeof(int);
        fileData = (unsigned char*)RL_MALLOC(dataSize);
        int* dataPtr = (int*)fileData;
        dataPtr[position] = value;

        success = SaveFileData(STORAGE_DATA_FILE, fileData, dataSize);
        UnloadFileData(fileData);

        TraceLog(LOG_INFO, "FILEIO: [%s] Saved storage value: %i", STORAGE_DATA_FILE, value);
    }

    return success;
}

// Load integer value from storage file (from defined position)
// NOTE: If requested position could not be found, value 0 is returned
int LoadStorageValue(unsigned int position)
{
    int value = 0;
    int dataSize = 0;
    unsigned char* fileData = LoadFileData(STORAGE_DATA_FILE, &dataSize);

    if (fileData != NULL)
    {
        if (dataSize < ((int)(position * 4))) TraceLog(LOG_WARNING, "FILEIO: [%s] Failed to find storage position: %i", STORAGE_DATA_FILE, position);
        else
        {
            int* dataPtr = (int*)fileData;
            value = dataPtr[position];
        }

        UnloadFileData(fileData);

        TraceLog(LOG_INFO, "FILEIO: [%s] Loaded storage value: %i", STORAGE_DATA_FILE, value);
    }

    return value;
}
