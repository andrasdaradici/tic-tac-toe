#include "raylib.h"

int main(void)
{
    const int screenWidth = 300;
    const int screenHeight = 400;

    int Scene = 1;
    int Squares[9] = {0,0,0,
                  0,0,0,
                  0,0,0};
    
    Image WindowLogo = LoadImage("resources/LogoPng.png");
    InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe");
    SetWindowIcon(WindowLogo);
    SetTargetFPS(60);
    Vector2 mousePos;
    
    //SFX
    InitAudioDevice();
    Sound BtnPress = LoadSound("resources/BtnPress.wav");  
    Sound Place = LoadSound("resources/Place.wav");
    Sound Win = LoadSound("resources/Win.wav");    
    //Main Menu
    Texture2D BackgroundImageLight = LoadTexture("resources/BackgroundLight.png");
    Texture2D BackgroundImageDark = LoadTexture("resources/BackgroundDark.png");
    
    Texture2D MenuTitleLight = LoadTexture("resources/MenuTitleLight.png");
    Texture2D MenuTitleDark = LoadTexture("resources/MenuTitleDark.png");
    
    Texture2D ButtonLight = LoadTexture("resources/ButtonLight.png");
    Texture2D ButtonDark = LoadTexture("resources/ButtonDark.png");
    bool DarkMode = false;
    bool Pressed;
    //Game Scene
    bool GameOver = false;
    int turn = 1;
    int Winner = 0;
    Texture2D BlankTile = LoadTexture("resources/BlankTile.png");
    Texture2D Cross = LoadTexture("resources/Cross.png");
    Texture2D Circle = LoadTexture("resources/Circle.png");
    
    while (!WindowShouldClose())
    {
        mousePos = GetMousePosition();
        BeginDrawing();
        if(Scene == 1){
            //Draw Textures for the UI
            if(!DarkMode){
                DrawTexture(BackgroundImageLight, 0, 0, WHITE);
                DrawTexture(MenuTitleLight, 0, 0, WHITE);
                
                //Play
                DrawTexture(ButtonLight, 50, 100, WHITE);
                DrawText("PLAY", 110, 112, 30, BLACK);
            
                //Options
                DrawTexture(ButtonLight, 50, 175, WHITE);
                DrawText("DARK MODE", 60, 187, 30, BLACK);
            
                //Credit
                DrawTexture(ButtonLight, 50, 250, WHITE);
                DrawText("CREDITS", 85, 262, 30, BLACK);
            
                //Exit
                DrawTexture(ButtonLight, 50, 325, WHITE);
                DrawText("EXIT", 113, 337, 30, BLACK);
            }
            if(DarkMode){
                DrawTexture(BackgroundImageDark, 0, 0, WHITE);
                DrawTexture(MenuTitleDark, 0, 0, WHITE);
                
                //Play
                DrawTexture(ButtonDark, 50, 100, WHITE);
                DrawText("PLAY", 110, 112, 30, WHITE);
            
                //Options
                DrawTexture(ButtonDark, 50, 175, WHITE);
                DrawText("LIGHT MODE", 60, 187, 29, WHITE);
            
                //Credit
                DrawTexture(ButtonDark, 50, 250, WHITE);
                DrawText("CREDITS", 85, 262, 30, WHITE);
            
                //Exit
                DrawTexture(ButtonDark, 50, 325, WHITE);
                DrawText("EXIT", 113, 337, 30, WHITE);
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(mousePos.x >= 50 && mousePos.x <= 250 && mousePos.y >= 100 && mousePos.y <= 150){
                    Scene = 2;
                    Pressed = true;
                    PlaySound(BtnPress);
                }
                if(mousePos.x >= 50 && mousePos.x <= 250 && mousePos.y >= 175 && mousePos.y <= 225){
                    DarkMode = !DarkMode;
                }
                if(mousePos.x >= 50 && mousePos.x <= 250 && mousePos.y >= 250 && mousePos.y <= 300){
                    Scene = 3;
                    PlaySound(BtnPress);
                }
                if(mousePos.x >= 50 && mousePos.x <= 250 && mousePos.y >= 325 && mousePos.y <= 375){
                    CloseWindow();
                }
            }
        }
        if(Scene == 2){
            //ClearBackground(RAYWHITE);
            if(!DarkMode){
                DrawTexture(BackgroundImageLight, 0, 0, WHITE);
                //DrawText(turn, 70, 20, 50, BLACK); 
                if(!GameOver){
                    if(turn == 1) 
                    {
                        DrawText("X Turn", 70, 5, 50, BLACK); 
                    }
                    if(turn == 2) 
                    {
                        DrawText("0 Turn", 70, 5, 50, BLACK); 
                    }
                }
                else{
                    if(Winner == 1)
                    {
                        DrawText("X Wins", 70, 5, 50, BLACK); 
                    }
                    if(Winner == 2)
                    {
                        DrawText("0 Wins", 70, 5, 50, BLACK); 
                    }
                    if(Winner == 3)
                    {
                        DrawText("Draw", 100, 5, 50, BLACK); 
                    }
                    DrawTexture(ButtonLight, 50, 345, WHITE);
                    DrawText("PLAY AGAIN", 60, 355, 30, BLACK);
                }
                //Grid
                DrawRectangle(screenWidth/2 - 55, screenHeight/2 - 137.5, 10, 275, BLACK);
                DrawRectangle(screenWidth/2 + 45, screenHeight/2 - 137.5, 10, 275, BLACK);
                DrawRectangle(screenWidth/2 - 137.5, screenHeight/2 - 55, 275, 10, BLACK);
                DrawRectangle(screenWidth/2 - 137.5, screenHeight/2 + 45, 275, 10, BLACK); 
            }
            if(DarkMode){
                DrawTexture(BackgroundImageDark, 0, 0, WHITE);
                
                if(!GameOver){
                    if(turn == 1) 
                    {
                        DrawText("X Turn", 70, 5, 50, WHITE); 
                    }
                    if(turn == 2) 
                    {
                        DrawText("0 Turn", 70, 5, 50, WHITE); 
                    }
                }
                else{
                    if(Winner == 1)
                    {
                        DrawText("X Wins", 70, 5, 50, WHITE); 
                    }
                    if(Winner == 2)
                    {
                        DrawText("0 Wins", 70, 5, 50, WHITE); 
                    }
                    if(Winner == 3)
                    {
                        DrawText("Draw", 100, 5, 50, WHITE); 
                    }
                    DrawTexture(ButtonDark, 50, 345, WHITE);
                    DrawText("PLAY AGAIN", 60, 355, 30, WHITE);
                }
                //Grid
                DrawRectangle(screenWidth/2 - 55, screenHeight/2 - 137.5, 10, 275, GRAY);
                DrawRectangle(screenWidth/2 + 45, screenHeight/2 - 137.5, 10, 275, GRAY);
                DrawRectangle(screenWidth/2 - 137.5, screenHeight/2 - 55, 275, 10, GRAY);
                DrawRectangle(screenWidth/2 - 137.5, screenHeight/2 + 45, 275, 10, GRAY);
            }
            
            //Symbol logic
            switch(Squares[0]){
                case 0:
                    DrawTexture(BlankTile,screenWidth/2 - 137.5, screenHeight/2 - 137.5, RAYWHITE);
                    break;
                case 1:
                    DrawTexture(Cross,screenWidth/2 - 137.5, screenHeight/2 - 137.5, MAROON);
                    break;
                case 2:
                    DrawTexture(Circle,screenWidth/2 - 137.5, screenHeight/2 - 137.5, BLUE);
                    break;
            }
            switch(Squares[1]){
                case 0:
                    DrawTexture(BlankTile,screenWidth/2 - 37.5, screenHeight/2 - 137.5, RAYWHITE);
                    break;
                case 1:
                    DrawTexture(Cross,screenWidth/2 - 37.5, screenHeight/2 - 137.5, MAROON);
                    break;
                case 2:
                    DrawTexture(Circle,screenWidth/2 - 37.5, screenHeight/2 - 137.5, BLUE);
                    break;
            }
            switch(Squares[2]){
                case 0:
                    DrawTexture(BlankTile,screenWidth/2 + 62.5, screenHeight/2 - 137.5, RAYWHITE);
                    break;
                case 1:
                    DrawTexture(Cross,screenWidth/2 + 62.5, screenHeight/2 - 137.5, MAROON);
                    break;
                case 2:
                    DrawTexture(Circle,screenWidth/2 + 62.5, screenHeight/2 - 137.5, BLUE);
                    break;
            }
            switch(Squares[3]){
                case 0:
                    DrawTexture(BlankTile,screenWidth/2 - 137.5, screenHeight/2 - 37.5, RAYWHITE);
                    break;
                case 1:
                    DrawTexture(Cross,screenWidth/2 - 137.5, screenHeight/2 - 37.5, MAROON);
                    break;
                case 2:
                    DrawTexture(Circle,screenWidth/2 - 137.5, screenHeight/2 - 37.5, BLUE);
                    break;
            }
            switch(Squares[4]){
                case 0:
                    DrawTexture(BlankTile,screenWidth/2 - 37.5, screenHeight/2 - 37.5, RAYWHITE);
                    break;
                case 1:
                    DrawTexture(Cross,screenWidth/2 - 37.5, screenHeight/2 - 37.5, MAROON);
                    break;
                case 2:
                    DrawTexture(Circle,screenWidth/2 - 37.5, screenHeight/2 - 37.5, BLUE);
                    break;
            }
            switch(Squares[5]){
                case 0:
                    DrawTexture(BlankTile,screenWidth/2 + 62.5, screenHeight/2 - 37.5, RAYWHITE);
                    break;
                case 1:
                    DrawTexture(Cross,screenWidth/2 + 62.5, screenHeight/2 - 37.5, MAROON);
                    break;
                case 2:
                    DrawTexture(Circle,screenWidth/2 + 62.5, screenHeight/2 - 37.5, BLUE);
                    break;
            }
            switch(Squares[6]){
                case 0:
                    DrawTexture(BlankTile,screenWidth/2 - 137.5, screenHeight/2 + 62.5, RAYWHITE);
                    break;
                case 1:
                    DrawTexture(Cross,screenWidth/2 - 137.5, screenHeight/2 + 62.5, MAROON);
                    break;
                case 2:
                    DrawTexture(Circle,screenWidth/2 - 137.5, screenHeight/2 + 62.5, BLUE);
                    break;
            }
            switch(Squares[7]){
                case 0:
                    DrawTexture(BlankTile,screenWidth/2 - 37.5, screenHeight/2 + 62.5, RAYWHITE);
                    break;
                case 1:
                    DrawTexture(Cross,screenWidth/2 - 37.5, screenHeight/2 + 62.5, MAROON);
                    break;
                case 2:
                    DrawTexture(Circle,screenWidth/2 - 37.5, screenHeight/2 + 62.5, BLUE);
                    break;
            }
            switch(Squares[8]){
                case 0:
                    DrawTexture(BlankTile,screenWidth/2 + 62.5, screenHeight/2 + 62.5, RAYWHITE);
                    break;
                case 1:
                    DrawTexture(Cross,screenWidth/2 + 62.5, screenHeight/2 + 62.5, MAROON);
                    break;
                case 2:
                    DrawTexture(Circle,screenWidth/2 + 62.5, screenHeight/2 + 62.5, BLUE);
                    break;
            }
            if(!IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Pressed = false;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !GameOver && !Pressed){
                if(mousePos.x >= 12.5 && mousePos.x <= 87.5 && mousePos.y >= 62.5 && mousePos.y <= 137.5 && Squares[0] == 0){
                    Squares[0] = turn;
                    turn = turn + 1;
                    if(turn > 2) turn = 1;
                    PlaySound(Place);
                }
                if(mousePos.x >= 112.5 && mousePos.x <= 187.5 && mousePos.y >= 62.5 && mousePos.y <= 137.5 && Squares[1] == 0){
                    Squares[1] = turn;
                    turn = turn + 1;
                    if(turn > 2) turn = 1;
                    PlaySound(Place);
                }
                if(mousePos.x >= 212.5 && mousePos.x <= 287.5 && mousePos.y >= 62.5 && mousePos.y <= 137.5 && Squares[2] == 0){
                    Squares[2] = turn;
                    turn = turn + 1;
                    if(turn > 2) turn = 1;
                    PlaySound(Place);
                }
                if(mousePos.x >= 12.5 && mousePos.x <= 87.5 && mousePos.y >= 162.5 && mousePos.y <= 237.5 && Squares[3] == 0){
                    Squares[3] = turn;
                    turn = turn + 1;
                    if(turn > 2) turn = 1;
                    PlaySound(Place);
                }
                if(mousePos.x >= 112.5 && mousePos.x <= 187.5 && mousePos.y >= 162.5 && mousePos.y <= 237.5 && Squares[4] == 0){
                    Squares[4] = turn;
                    turn = turn + 1;
                    if(turn > 2) turn = 1;
                    PlaySound(Place);
                }
                if(mousePos.x >= 212.5 && mousePos.x <= 287.5 && mousePos.y >= 162.5 && mousePos.y <= 237.5 && Squares[5] == 0){
                    Squares[5] = turn;
                    turn = turn + 1;
                    if(turn > 2) turn = 1;
                    PlaySound(Place);
                }
                if(mousePos.x >= 12.5 && mousePos.x <= 87.5 && mousePos.y >= 262.5 && mousePos.y <= 337.5 && Squares[6] == 0){
                    Squares[6] = turn;
                    turn = turn + 1;
                    if(turn > 2) turn = 1;
                    PlaySound(Place);
                }
                if(mousePos.x >= 112.5 && mousePos.x <= 187.5 && mousePos.y >= 262.5 && mousePos.y <= 337.5 && Squares[7] == 0){
                    Squares[7] = turn;
                    turn = turn + 1;
                    if(turn > 2) turn = 1;
                    PlaySound(Place);
                }
                if(mousePos.x >= 212.5 && mousePos.x <= 287.5 && mousePos.y >= 262.5 && mousePos.y <= 337.5 && Squares[8] == 0){
                    Squares[8] = turn;
                    turn = turn + 1;
                    if(turn > 2) turn = 1;
                    PlaySound(Place);
                }
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GameOver){
                if(mousePos.x >= 50 && mousePos.x <= 250 && mousePos.y >= 345 && mousePos.y <= 395)
                {
                    Winner = 0;
                    GameOver = false;
                    turn = 1;
                    Squares[0] = 0;
                    Squares[1] = 0;
                    Squares[2] = 0;
                    Squares[3] = 0;
                    Squares[4] = 0;
                    Squares[5] = 0;
                    Squares[6] = 0;
                    Squares[7] = 0;
                    Squares[8] = 0;
                    PlaySound(BtnPress);
                }
            }
            //Winning conditions
            //X Conditions
            if(Winner == 0){
                if(Squares[0] == 1 && Squares[1] == 1 && Squares[2] == 1){
                    Winner = 1;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[3] == 1 && Squares[4] == 1 && Squares[5] == 1){
                    Winner = 1;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[6] == 1 && Squares[7] == 1 && Squares[8] == 1){
                    Winner = 1;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[0] == 1 && Squares[3] == 1 && Squares[6] == 1){
                    Winner = 1;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[1] == 1 && Squares[4] == 1 && Squares[7] == 1){
                    Winner = 1;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[2] == 1 && Squares[5] == 1 && Squares[8] == 1){
                    Winner = 1;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[0] == 1 && Squares[4] == 1 && Squares[8] == 1){
                    Winner = 1;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[2] == 1 && Squares[4] == 1 && Squares[6] == 1){
                    Winner = 1;
                    GameOver = true;
                    PlaySound(Win);
                }
                //0 Conditions
                if(Squares[0] == 2 && Squares[1] == 2 && Squares[2] == 2){
                    Winner = 2;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[3] == 2 && Squares[4] == 2 && Squares[5] == 2){
                    Winner = 2;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[6] == 2 && Squares[7] == 2 && Squares[8] == 2){
                    Winner = 2;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[0] == 2 && Squares[3] == 2 && Squares[6] == 2){
                    Winner = 2;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[1] == 2 && Squares[4] == 2 && Squares[7] == 2){
                    Winner = 2;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[2] == 2 && Squares[5] == 2 && Squares[8] == 2){
                    Winner = 2;
                    GameOver = true;
                    PlaySound(Win);
                } 
                if(Squares[0] == 2 && Squares[4] == 2 && Squares[8] == 2){
                    Winner = 2;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(Squares[2] == 2 && Squares[4] == 2 && Squares[6] == 2){
                    Winner = 2;
                    GameOver = true;
                    PlaySound(Win);
                }
                if(!GameOver){
                    //Draw conditions
                    if(Squares[0] != 0 && Squares[1] != 0 && Squares[2] != 0 && Squares[3] != 0 && Squares[4] != 0 && Squares[5] != 0 && Squares[6] != 0 && Squares[7] != 0 && Squares[8] != 0)
                    {
                        GameOver = true;
                        Winner = 3;
                        PlaySound(Win);
                    }
                }
            }
        }
        if(Scene == 3){
            if(!DarkMode){
                DrawTexture(BackgroundImageLight, 0, 0, WHITE);
                DrawTexture(ButtonLight, 50, 325, WHITE);
                DrawText("BACK", 113, 337, 30, BLACK);
                
                DrawText("CREDITS", 58, 5, 40, GRAY);
                DrawText("Daradici András - Coding", 30, 55, 20, GRAY);
                DrawText("raylib -Graphics Library", 30, 85, 20, GRAY);
                DrawText("raylib.com", 110, 115, 20, SKYBLUE);
                DrawText("You - Playing the game <3", 30, 145, 20, GRAY);
            }
            if(DarkMode){
                DrawTexture(BackgroundImageDark, 0, 0, WHITE);
                DrawTexture(ButtonDark, 50, 325, WHITE);
                DrawText("BACK", 113, 337, 30, WHITE);
                DrawText("CREDITS", 58, 5, 40, GRAY);
                DrawText("Daradici András - Coding", 30, 55, 20, GRAY);
                DrawText("raylib -Graphics Library", 30, 85, 20, GRAY);
                DrawText("raylib.com", 110, 115, 20, SKYBLUE);
                DrawText("You - Playing the game <3", 30, 145, 20, GRAY);
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                PlaySound(BtnPress);
                if(mousePos.x >= 50 && mousePos.x <= 250 && mousePos.y >= 325 && mousePos.y <= 375){
                    Scene = 1;
                    PlaySound(BtnPress);
                }
                if(mousePos.x >= 0 && mousePos.x <= 400 && mousePos.y >= 115 && mousePos.y <= 135){
                    OpenURL("https://www.raylib.com/");
                    PlaySound(Win);
                }
            }
        }
        
        EndDrawing();
    }
    return 0;
}