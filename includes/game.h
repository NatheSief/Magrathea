#pragma once

#ifndef GAME_H
# define GAME_H

# include "map.h"
# include "player.h"

typedef struct s_game t_game;
typedef struct s_inventory t_inventory;
typedef struct s_master t_master;

struct s_game
{
    t_map *map;
    t_entity *player;
};

struct s_game
{
    int capacity;
    int used;
};

struct s_master
{
    t_game *game;   // Array of the different games that are currently running
    int nb_games;   // Number of games that are currently running
    void (*close_game)(t_game *game);   
};

#endif