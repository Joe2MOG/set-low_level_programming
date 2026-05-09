#include "main.h"

/**
 * free_grid - frees a 2D array created by alloc_grid
 * @grid: the grid to free
 * @height: number of rows
 */
void free_grid(int **grid, int height)
{
	int h;

	if (grid == NULL || height <= 0)
		return;

	for (h = 0; h < height; h++)
		free(grid[h]);

	free(grid);
}
