#include "grid.h"

Grid::~Grid()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] grid[i];
	}

	delete[] grid;
}

Grid::Grid(int cellSize, sf::Color cellColor, int windowWidth, int windowHeight)
{
	srand(time(0));

	// Random cell color!
	// cellColor = sf::Color(rand() % 255, rand() % 255, rand() % 255);

	this->cellSize = cellSize;
	this->cellColor = cellColor;
	cell.setSize(sf::Vector2f(cellSize, cellSize));
	cell.setFillColor(cellColor);

	emptyCellColor = sf::Color::Black;
	emptyCell.setSize(sf::Vector2f(cellSize, cellSize));
	emptyCell.setFillColor(emptyCellColor);

	rows = windowHeight / cellSize;
	columns = windowWidth / cellSize;

	grid = new sf::RectangleShape * [rows];
	oldGrid = new sf::RectangleShape * [rows];

	for (int i = 0; i < rows; i++)
	{
		grid[i] = new sf::RectangleShape[columns];
		oldGrid[i] = new sf::RectangleShape[columns];
	}

	ClearGrid();
}

void Grid::ClearGrid()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			emptyCell.setPosition(j * cellSize, i * cellSize);
			grid[i][j] = emptyCell;
			oldGrid[i][j] = emptyCell;
		}
	}
}

void Grid::DrawGrid(sf::RenderWindow& window)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			// Glitch Effect!
			// grid[i][j].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255)); 
			grid[i][j] = oldGrid[i][j];
			window.draw(grid[i][j]);
		}
	}
}

int Grid::GetRows()
{
	return rows;
}

int Grid::GetColumns()
{
	return columns;
}

bool Grid::IsCellAlive(int i, int j)
{
	return grid[i][j].getFillColor() == cellColor;
}

void Grid::SetCell(int i, int j)
{
	cell.setPosition(j * cellSize, i * cellSize);
	oldGrid[i][j] = cell;
}

void Grid::SetEmptyCell(int i, int j)
{
	emptyCell.setPosition(j * cellSize, i * cellSize);
	oldGrid[i][j] = emptyCell;
}

int Grid::GetCellSize()
{
	return cellSize;
}