#pragma once

#ifndef MAP_H
# define MAP_H

# include "global.h"

typedef struct s_map t_map;
typedef struct s_tile t_tile;
typedef struct s_biomes t_biomes;
typedef enum e_tile_type e_type;
typedef enum e_tiles_biomes e_biomes;

enum e_tile_type
{
    GRASS,
    GROUND,
    AIR
};

enum e_tiles_biomes
{
    DESERT,
    FOREST,
    MOUNTAIN,
    PLAIN,
    SNOW,
    SWAMP,
    WATER
};

struct s_tile
{
    bool walkable;
    t_inventory *inventory; // NULL if there is no inventory on the tile
    t_inventory *loot_table; // Loot table
    t_pos pos;
    float opacity;              // To let the light pass or not
    float temperature;          // To let the temperature pass or not
    int weight;
    int tile_id;
};

struct s_biome
{
    e_biomes biome;
    t_tile **tiles;
    int width;
    int height;
    int biome_id;
    int altitude;
    int temperature;
    int humidity;
    // void (*generate_tile(struct s_biome *self, t_tile **tiles, int w, int h));
    // void (*generate_structures(struct s_biome *self, t_tile **tiles, int w, int h));
};

struct s_map
{
    t_biomes **map;
    int width;
    int height;
};

#endif