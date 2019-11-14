// board.cpp

#include<vector>
#include<sstream>
//#include<stack>
#include<iostream>
#include<random>

#include "tile.h"
#include "board.h"
#include "coord.h"

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
			//randx = rand_gen::get_rand_range(width);
			//randy = rand_gen::get_rand_range(height);
			randx = rand() % width;
			randy = rand() % height;
		}while(board[randx][randy].is_bomb());
		board[randx][randy].set_bomb(true); // Set to bomb

		// Place numbers indicating amount of adjacent bombs
		// TODO: switch to get_valid_tiles function once complete
		char loc = 0b11111111;
		if(randx == 0)
			loc &= ~(TL_DIAG | LEFT | BL_DIAG);
		if(randx == width-1)
			loc &= ~(TR_DIAG | RIGHT | BR_DIAG);
		if(randy == 0)
			loc &= ~(TL_DIAG | TOP | TR_DIAG);
		if(randy == height-1)
			loc &= ~(BL_DIAG | BOTTOM | BR_DIAG);
		increment_adj(randx, randy, loc);
	}
}

char Board::get_valid_tiles_around(int x, int y)
{
		char loc = 0b11111111;
		if(x == 0)
			loc &= ~(TL_DIAG | LEFT | BL_DIAG);
		if(x == width-1)
			loc &= ~(TR_DIAG | RIGHT | BR_DIAG);
		if(y == 0)
			loc &= ~(TL_DIAG | TOP | TR_DIAG);
		if(y == height-1)
			loc &= ~(BL_DIAG | BOTTOM | BR_DIAG);
		return loc;
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

void Board::increment_adj(int x, int y, char loc)
{
	if(loc & TL_DIAG)
		board[x-1][y-1].increment_adj();
	if(loc & TOP)
		board[x][y-1].increment_adj();
	if(loc & TR_DIAG)
		board[x+1][y-1].increment_adj();
	if(loc & LEFT)
		board[x-1][y].increment_adj();
	if(loc & RIGHT)
		board[x+1][y].increment_adj();
	if(loc & BL_DIAG)
		board[x-1][y+1].increment_adj();
	if(loc & BOTTOM)
		board[x][y+1].increment_adj();
	if(loc & BR_DIAG)
		board[x+1][y+1].increment_adj();
}

bool Board::should_expand(int x, int y)
{
	if(!board[x][y].is_hidden()) // Tile is open
	{
		std::cout << "should_expand returns false @ ";
		std::cout << x << ", " << y << "\n";
		return false;
	}
	if(board[x][y].adj_bombs() !=0) // Tile is not empty
	{
		std::cout << "should_expand returns false @ ";
		std::cout << x << ", " << y << "\n";
		return false;
	}
	if(board[x][y].is_bomb())
	{
		std::cout << "should_expand returns false @ ";
		std::cout << x << ", " << y << "\n";
		return false;
	}
	if(board[x][y].is_flagged())
	{
		std::cout << "should_expand returns false @ ";
		std::cout << x << ", " << y << "\n";
		return false;
	}
	std::cout << "should_expand returns true @ ";
	std::cout << x << ", " << y << "\n";
	return true;
}

bool Board::should_auto_open(int x, int y)
{
	if(board[x][y].is_flagged())
	{
		return false;
	}
	if(!board[x][y].is_hidden())
	{
		return false;
	}
	return true;
}

void Board::open_tile_at(int x, int y)
{
	std::cout << "Open tile at (" << x << ", " << y << ")\n";
	board[x][y].set_hidden(false);
}

std::string Board::loc_repr(char loc)
{
	switch(loc)
	{
		case TL_DIAG:
			return "Top left diagonal";
		case TOP:
			return "Top";
		case TR_DIAG:
			return "Top right diagonal";
		case LEFT:
			return "Left";
		case RIGHT:
			return "Right";
		case BL_DIAG:
			return "Bottom left diagonal";
		case BOTTOM:
			return "Bottom";
		case BR_DIAG:
			return "Bottom right diagonal";
		default: //TODO: add proper exception
			return "This sucks, you broke it, bunghole!";
	}
}

void Board::auto_open_at(int x, int y, int iter)
{
	std::cout << "auto_open_at (" << x << ", " << y << ")\n";
	if(iter == 0)
	{
		open_tile_at(x, y);
		if(board[x][y].adj_bombs() != 0) return;
	}
	// Determine what adjacent tiles to check and/or open
	char valid = get_valid_tiles_around(x, y);
	// There are 8 "loc" positions, iterate through them
	for(int l = 1; l < 1<<8; l <<= 1)
	{
		//std::cout << "Checking at " << loc_repr(l) << std::endl;
		if(valid & l) // The adjecent tile at this location is within bounds
		{
			//std::cout << "Valid at " << loc_repr(l) << std::endl;
			int nextx = x + get_x_offs(l);
			int nexty = y + get_y_offs(l);
			if(should_expand(nextx, nexty))
			{
				open_tile_at(nextx, nexty);
				auto_open_at(nextx, nexty);
			}else if(should_auto_open(nextx, nexty))
			{
				open_tile_at(nextx, nexty);
			}
		}
	}
}

int Board::get_x_offs(char loc)
{
	switch(loc)
	{
		case TL_DIAG:
		case LEFT:
		case BL_DIAG:
			return -1;
		case TOP:
		case BOTTOM:
			return 0;
		case TR_DIAG:
		case RIGHT:
		case BR_DIAG:
			  return 1;
		default:// TODO: exception
			  return 69;
	}
}

int Board::get_y_offs(char loc)
{
	switch(loc)
	{
		case TL_DIAG:
		case TOP:
		case TR_DIAG:
			return -1;
		case LEFT:
		case RIGHT:
			return 0;
		case BL_DIAG:
		case BOTTOM:
		case BR_DIAG:
			return 1;
		default:// TODO: exception
			return 69;
	}
}

void Board::toggle_flag_at(int x, int y)
{
	board[x][y].set_flagged(!board[x][y].is_flagged());
}
