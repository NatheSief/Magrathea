#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define WIDTH  100
#define HEIGHT 50

float temperature[HEIGHT][WIDTH];

static float _map_range(int value, int a, int b, float c, float d) 
{
    return ((float)(value - a) / (float)(b - a)) * (d - c) + c;
}

static float _clampf(float val, float min, float max) 
{
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

static float _randf_range(float min, float max) 
{
    return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

static void _generate_temperature_map(void) 
{
    srand(time(0));
    for (int y = 0; y < HEIGHT; y++) 
    {
        float temp_base = _map_range(y, 0, HEIGHT, -1.0f, 1.0f);
        for (int x = 0; x < WIDTH; x++) 
        {
            float offset = _randf_range(-0.2f, 0.2f);
            temperature[y][x] = _clampf(temp_base + offset, -1.0f, 1.0f);
        }
    }
}

static void _print_temp_preview(void) 
{
    if (!DEBUG_MODE)
        return ;
    for (int y = 0; y < 10; y++) 
    {
        for (int x = 0; x < 20; x++) 
            printf("%+.2f ", temperature[y][x]);
        printf("\n");
    }
}

int proceduralGen(void)
{
    _generate_temperature_map();
    print_temp_preview();
    return 0;
}
