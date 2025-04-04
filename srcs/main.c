#include "player.h"
#include "map.h"
#include "game.h"

void    load_backup(t_game *game)
{
    
    
}

int main(void)
{
    t_game  game;
    load_backup(&game); // Check if I already have some games saved (check a default folder)
    load_game(&game); // Load the game from the save file if I have some, in else just allow the user to start a new game
    close_game(&game); // Free all the memory used by the game and create a backup if needed
    return (0);
}