#include "../../includes/save.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#ifdef _WIN32
# include <direct.h>
# define mkdir(path, mode) _mkdir(path)
#else
# include <unistd.h>
#endif

const char *get_save_dir(void) {
    const char *home = getenv("HOME");
    if (!home) return "./"; // fallback
    static char save_path[512];
    snprintf(save_path, sizeof(save_path), "%s/.local/share/MagratheaGame/saves", home);
    return save_path;
}

void ensure_save_directory_exists(void) {
    const char *path = get_save_dir();
    struct stat st = {0};

    if (stat(path, &st) == -1) {
        mkdir(path, 0755);
        printf("[SAVE] Dossier créé : %s\n", path);
    }
}

void list_saves(void) {
    const char *path = get_save_dir();
    DIR *dir = opendir(path);
    if (!dir) return;

    struct dirent *entry;
    printf("Sauvegardes disponibles :\n");

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR &&
            strcmp(entry->d_name, ".") != 0 &&
            strcmp(entry->d_name, "..") != 0) {
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dir);
}

bool create_save(const char *name) {
    char full_path[512];
    snprintf(full_path, sizeof(full_path), "%s/%s", get_save_dir(), name);
    struct stat st = {0};

    if (stat(full_path, &st) != -1) {
        printf("[SAVE] '%s' existe déjà.\n", name);
        return false;
    }
    mkdir(full_path, 0755);

    char chunks_path[512];
    snprintf(chunks_path, sizeof(chunks_path), "%s/chunks", full_path);
    mkdir(chunks_path, 0755);

    printf("[SAVE] Création de la sauvegarde '%s'\n", name);
    return true;
}

bool save_chunk(const char *save_name, t_chunk *chunk) {
    char path[512];
    snprintf(path, sizeof(path), "%s/%s/chunks", get_save_dir(), save_name);
    mkdir(path, 0755);

    char file[512];
    snprintf(file, sizeof(file), "%s/chunk_%d_%d.dat", path, chunk->x, chunk->y);
    FILE *f = fopen(file, "wb");
    if (!f) return false;
    fwrite(chunk->tiles, sizeof(t_tile), CHUNK_SIZE * CHUNK_SIZE, f);
    fclose(f);
    printf("[SAVE] Chunk (%d, %d) sauvegardé.\n", chunk->x, chunk->y);
    return true;
}
