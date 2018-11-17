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
	
	// Set vectors to the proper size and initialize with a Tile
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
	// Randomly place bombs, then increment numbers around them
	int randx, randy;
	for(int i = 0; i < bombs; i++)
	{
		do
		{ // Pick a new coord until we find one not already a bomb
			randx = rand_gen::get_rand_range(width);
			randy = rand_gen::get_rand_range(height);
		}while(board[randx][randy].is_bomb());
		board[randx][randy].set_bomb(true); // Set to bomb

		// Generate numbers
		// TODO
	}
}

std::string Board::repr()
{
	std::stringstream ss;
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			ss << board[x][y].repr(); // Add each tile's representation
		}
		ss << '\n';
	}
	return ss.str();
}
