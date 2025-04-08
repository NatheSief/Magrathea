#ifndef SAVE_H
# define SAVE_H

# include <stdbool.h>

# define CHUNK_SIZE 16

typedef struct s_tile {
    int biome;
    int type;
    bool walkable;
    int structure_id;
} t_tile;

typedef struct s_chunk {
    int x, y;
    t_tile tiles[CHUNK_SIZE][CHUNK_SIZE];
    bool is_loaded;
    bool is_modified;
} t_chunk;

const char *get_save_dir(void);
void ensure_save_directory_exists(void);
void list_saves(void);
bool create_save(const char *name);
bool save_chunk(const char *save_name, t_chunk *chunk);

#endif
