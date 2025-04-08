#pragma once

#ifndef MAGRATEHA_H
# define MAGRATHEA_H

//              INCLUDES                //

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "raylib.h"

//              DEFINES                 //

# define SAVE_PATHS "~/.local/saves/Magrathea"

//              MACROS                  //

//              TYPEDEFS                //

typedef struct s_master t_master;       //  Game structure with the backups
typedef struct s_game t_game;           //  Structure that contains all the game informations
typedef struct s_entity t_entity;       //  Entity structure with the statistiques, inventory, ...
typedef struct s_biome t_biome;         //  Biomes structure with the function pointers to the generation, the rules, ...
typedef struct s_tile t_tile;           //  Tile structure, with the resistance, loot table, texture, ...
typedef struct s_book t_book;           //  Global book with all the informations to collect
typedef struct s_map t_map;             //  Local map for each games

typedef enum e_state e_state;

//              STRUCTURES              //

struct s_master
{
    e_state gameState;
    t_game  loadedGame;
    t_book  *book;
};

struct s_game
{
    t_map       *map;
    t_entity    *player;
};

//              ENUMS                   //

enum e_state
{
    GAME_LOAD,
    GAME_STARTING_PAGE,
    GAME_PLAY,
    GAME_OPTIONS,
    GAME_END
};

//              FUNCTION PROTOTYPES     //

void    loadGraphics(t_game *master);
void    closeGame(t_game *master);

//              GLOBALS                 //

//              DEBUG                   //
#endif