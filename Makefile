NAME = rpg
SRC = $(wildcard srcs/*.c)
INC = -Iinclude
BUILD = build

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11 -lm

DEBUG_FLAGS = -DDEBUG_MODE=1 -g

all: $(BUILD)/$(NAME)

$(BUILD)/$(NAME): $(SRC)
	mkdir -p $(BUILD)
	$(CC) $(SRC) -o $(BUILD)/$(NAME) $(INC) $(CFLAGS) $(MLX_FLAGS)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean
	$(MAKE)

clean:
	rm -rf $(BUILD)

re: clean all

run: all
	./$(BUILD)/$(NAME)

.PHONY: all clean re run debug