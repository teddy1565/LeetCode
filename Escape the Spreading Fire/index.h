#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define ESC_MIN -1
#define ESC_MAX 1000000000

#define GRASS 0
#define FIRE 1
#define WALL 2
#define USER 3
#define ESC_DOOR 4

int maximumMinutes(int** grid, int gridSize, int* gridColSize);