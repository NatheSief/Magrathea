#pragma once

#ifndef PLAYER_H
# define PLAYER_H

# include <stdbool.h>

typedef struct s_entity t_entity;

struct s_entity
{
    //  POSITION
    int x;
    int y;

    //  STATUS
    bool is_alive;
    bool is_player;

    //  STATS
    int hp;
    int mana;
    int stamina;

    //  COMBAT
    int attack;
    int defense;
    int speed;

    //  LEVEL
    int level;
    int xp;
    int gold;

    //  ATTRIBUTES
    int power;
    int dexterity;
    int intelligence;
    int wisdom;
    int charisma;
    int luck;
    int constitution;
    int strength;
    int agility;
    int perception;
    int endurance;
    int willpower;
    int spirit;
    int mind;
 };

#endif