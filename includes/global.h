#pragma once

#ifndef GLOBAL_H
# define GLOBAL_H

# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif

typedef struct s_pos t_pos;

struct s_pos
{
    int x;
    int y;
};

#endif