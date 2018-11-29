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
			//board[x][y].set_hidden(false);
		}
	}
}

void Board::generate(int bombs)
{	/* TODO: add check to ensure that requested number of bombs does not exceed
	 * the number of tiles on the board, resulting in an infinte loop as the
	 * function continually try new locations and fails due to not having any
	 * empty slots left */
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
		char which = 0b11111111;
		if(randx == 0)
			which &= ~(TL_DIAG | LEFT | BL_DIAG);
		if(randx == width-1)
			which &= ~(TR_DIAG | RIGHT | BR_DIAG);
		if(randy == 0)
			which &= ~(TL_DIAG | TOP | TR_DIAG);
		if(randy == height-1)
			which &= ~(BL_DIAG | BOTTOM | BR_DIAG);
		increment_adj(randx, randy, which);
	}
}

std::string Board::repr()
{
	std::stringstream ss;
	// If a tile is on the border, draw the proper char, otherwise get its repr()
	for(int y = -1; y < height+1; y++)
	{
		for(int x = -1; x < width+1; x++)
		{
			if(x == -1 && y == -1)
				ss << "╔";
			else if(x == -1 && y == height)
				ss << "╚";
			else if(x == width && y == -1)
				ss << "╗";
			else if(x == width && y == height)
				ss << "╝";
			else if(x == -1 || x == width)
				ss << "║";
			else if(y == -1 || y == height)
				ss << "═";
			else
				ss << board[x][y].repr();
		}
		ss << '\n';
	}
	return ss.str();
}

void Board::increment_adj(int x, int y, char which)
{
	if(which & TL_DIAG)
		board[x-1][y-1].increment_adj();
	if(which & TOP)
		board[x][y-1].increment_adj();
	if(which & TR_DIAG)
		board[x+1][y-1].increment_adj();
	if(which & LEFT)
		board[x-1][y].increment_adj();
	if(which & RIGHT)
		board[x+1][y].increment_adj();
	if(which & BL_DIAG)
		board[x-1][y+1].increment_adj();
	if(which & BOTTOM)
		board[x][y+1].increment_adj();
	if(which & BR_DIAG)
		board[x+1][y+1].increment_adj();
}

void Board::open_tile_at(int x, int y)
{
	board[x][y].set_hidden(false);
}
