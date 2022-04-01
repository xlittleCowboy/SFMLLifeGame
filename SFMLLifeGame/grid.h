#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>

class Grid
{
private:
	int cellSize;
	sf::Color cellColor;
	sf::RectangleShape cell;

	sf::Color emptyCellColor;
	sf::RectangleShape emptyCell;

	int rows, columns;

	sf::RectangleShape** grid;
	sf::RectangleShape** oldGrid;

public:
	~Grid();
	Grid(int cellSize, sf::Color cellColor, int windowWidth, int windowHeight);

	void ClearGrid();
	void DrawGrid(sf::RenderWindow& window);

	bool IsCellAlive(int i, int j);
	void SetCell(int i, int j);
	void SetEmptyCell(int i, int j);

	int GetRows();
	int GetColumns();
};

