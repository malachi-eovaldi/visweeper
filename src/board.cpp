// board.cpp

#include<vector>
#include<random>
#include<sstream>

#include "tile.h"
#include "board.h"

Board::Board(int width, int height)
{
	this->width = width;
	this->height = height;

	board.resize(width);
	for(int i = 0; i < width; i++)
	{
		board[i].resize(height);
	}

	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			board[i][j] = Tile();
			board[i][j].set_hidden(false);
		}
	}
}

void Board::generate(int bombs)
{
	// TODO: check that space is not already a bomb, seed rand
	for(int i = 0; i < 10; i++)
	{
		board[std::rand() % width][std::rand() % height].set_bomb(true);
	}
}

std::string Board::repr()
{
	std::stringstream ss;
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			ss << board[i][j].repr();
		}
		ss << '\n';
	}
	return ss.str();
}
