#include "Magrathea.h"

void    loadGraphics(t_game *master)
{
    master->gameState = GAME_LOAD;
    InitWindow(1440, 1024, "Magrathea");
    SetTargetFPS(60);

    Texture2D startingPage = LoadTexture("assets/Templates/startingPageMagrathea.png");
    Rectangle buttonLoadSave = {43, 528, 500, 107};
    Rectangle buttonNewGame = {43, 665, 500, 107};
    Vector2 mouse = GetMousePosition();
    bool hoveringLoadSave = CheckCollisionPointRec(mouse, buttonLoadSave);
    bool hoveringNewGame = CheckCollisionPointRec(mouse, buttonNewGame);
    bool clickedLoadSave = hoveringLoadSave && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    bool clickedNewGame = hoveringNewGame && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}