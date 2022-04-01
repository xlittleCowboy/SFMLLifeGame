#include "life.h"

Life::Life(float startSpawnChance)
{
	srand(time(0));

	this->startSpawnChance = startSpawnChance;
}

void Life::SpawnStartCells(Grid& grid)
{
	for (int i = 0; i < grid.GetRows(); i++)
	{
		for (int j = 0; j < grid.GetColumns(); j++)
		{
			if (rand() % 100 <= startSpawnChance)
			{
				grid.SetCell(i, j);
			}
		}
	}
}

void Life::SpawnCells(Grid& grid, int x, int y)
{
	grid.SetCell(y, x);
}

void Life::CheckCells(Grid& grid)
{
	for (int i = 0; i < grid.GetRows(); i++)
	{
		for (int j = 0; j < grid.GetColumns(); j++)
		{
			int neighbourCellsCount = CountNeighbourCells(grid, i, j);
			if (!grid.IsCellAlive(i, j))
			{
				if (neighbourCellsCount == 3)
				{
					grid.SetCell(i, j);
				}
			}
			else
			{
				if (neighbourCellsCount < 2 || neighbourCellsCount > 3)
				{
					grid.SetEmptyCell(i, j);
				}
			}
		}
	}
}

int Life::CountNeighbourCells(Grid& grid, int i, int j)
{
	int cellsCount = 0;

	int y, x;
	i == 0 ? y = i : y = i - 1;
	j == 0 ? x = j : x = j - 1;

	int y2, x2;
	i == grid.GetRows() - 1 ? y2 = i : y2 = i + 1;
	j == grid.GetColumns() - 1 ? x2 = j : x2 = j + 1;

	for (; y <= y2; y++)
	{
		j == 0 ? x = j : x = j - 1;
		for (; x <= x2; x++)
		{
			if (grid.IsCellAlive(y, x))
			{
				cellsCount++;
			}
		}
	}

	return cellsCount;
}