#include "main.h"

/**
 * alloc_grid - creates a 2D array of integers initialised to zero
 * @width: number of columns
 * @height: number of rows
 *
 * Return: pointer to the 2D array, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int h, w;

	if (width <= 0 || height <= 0)
		return (NULL);

	/* allocate array of row pointers */
	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	for (h = 0; h < height; h++)
	{
		/* allocate each row */
		grid[h] = malloc(width * sizeof(int));
		if (grid[h] == NULL)
		{
			/* free previously allocated rows */
			for (w = 0; w < h; w++)
				free(grid[w]);
			free(grid);
			return (NULL);
		}

		/* initialise row to zero */
		for (w = 0; w < width; w++)
			grid[h][w] = 0;
	}

	return (grid);
}
