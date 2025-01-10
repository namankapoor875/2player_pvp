#include "Player_Obj.h"
#include "raylib.h"
#ifndef Map_Editor
#define Map_Editor
class MapEditor
{
    public:
    void DeathScreen(PlayerObj *Player1, PlayerObj *Player2, int screenWidth, int screenHeight, Rectangle Play_button){
        if ((Player1->Hp <= 0)or(Player2->Hp <= 0)){// Death Screen
                    if (IsCursorHidden()) EnableCursor();//check if the curssor is on the screen
                    //change bg and print all the rectangles
                    DrawRectangle(0, 0, screenWidth, screenHeight, (Color){0,0,0,80});
                    DrawRectangle(screenWidth/2.0f-200,screenHeight/2.0f-100,400,200, (Color){200,200,200,200});
                    
                    // Button color change 
                    DrawRectangleRec(Play_button,(Color) {225,225,225,225});
                    
                    // player death text 
                    if (Player1->Hp <= 0)DrawText("PLAYER 2 WON", screenWidth/2.0f-80, screenHeight/2.0f-50, 20.0f, BLACK);
                    else if (Player2->Hp <= 0) DrawText("PLAYER 1 WON", screenWidth/2.0f-80, screenHeight/2.0f-50, 20.0f, BLACK);
                    DrawText("Main Menu", screenWidth/2.0f-50, screenHeight/2.0f-12, 20.0f, BLACK);
                }
        return;
    }
    
    void AttackHorizontal(Rectangle pos, int Grid_Size_x, int Block_Size, Rectangle *list){
        for(int x=0; x <= Grid_Size_x; x++){
            list[x] = (Rectangle){(float)(x*Block_Size),(float)pos.y,(float)Block_Size,(float)Block_Size};
        }
    }
    
    void AttackVertical(Rectangle pos, int Grid_Size_y, int Block_Size, Rectangle *list){
        for(int x=0; x <= Grid_Size_y; x++){
            list[x] = (Rectangle){(float)pos.x,(float)(x*Block_Size),(float)Block_Size,(float)Block_Size};
        }
    }

};

#endif //Map_Editor