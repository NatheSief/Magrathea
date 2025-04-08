#include "Magrathea.h"

void    launchMagrathea(t_master *master)
{
    loadGraphics(master);
}

int main(void)
{
    t_master master = NULL;
    BeginDrawing();
    while (!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);
        launchMagrathea(&master);           //  Load la page d'accueil
        loadSaves(&master);                 //  Load les saves des parties precedentes si elles existent
        launchGame(&master.loadedGame);     //  Launch the current game
        saveGame(&master.loadedGame);       // Force create a save of the game
    }
    closeGame(&master);
    return (1);
}