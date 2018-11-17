// board.cpp

#include<vector>
#include<sstream>

#include "rand.h"
#include "tile.h"
#include "board.h"

Board::Board(int width, int height)
{
	
	this->width = width;
	this->height = height;

	board.resize(width, std::vector<Tile>(height, Tile()));

	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			board[x][y].set_hidden(false);
		}
	}
}

void Board::generate(int bombs)
{
	// TODO: check that space is not already a bomb
	for(int i = 0; i < bombs; i++)
	{
		board[rand_gen::get_rand_range(width)][rand_gen::get_rand_range(height)]
				.set_bomb(true);
	}
}

std::string Board::repr()
{
	std::stringstream ss;
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			ss << board[x][y].repr();
		}
		ss << '\n';
	}
	return ss.str();
}
