#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>

#include "grid.h"

class Life
{
private:
	int startSpawnChance;

public:
	Life(float startSpawnChance);

	void SpawnStartCells(Grid& grid);

	void CheckCells(Grid& grid);
	int CountNeighbourCells(Grid& grid, int i, int j);
};

