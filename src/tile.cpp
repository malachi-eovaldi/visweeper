// tile.cpp

#include<string>
#include<sstream>

#include "tformat.h"
#include "tile.h"

Tile::Tile(): adj(0), bomb(false), flagged(false), hidden(true)
{
}

std::string Tile::repr()
{
	// Return a color code, character representation, then color reset code
	std::stringstream ss;
	if(flagged)
	{
		ss << TERM::FG_YELLOW << 'F';
	}else if(hidden)
	{
		ss << TERM::FG_GREEN << 'H';
	}else if(bomb)
	{
		ss << TERM::FG_RED << 'B';
	}else if(adj == 0)
	{
		ss << TERM::FG_BLUE << ' ';
	}else
	{
		ss << TERM::FG_BLUE << adj;
	}
	ss << TERM::FG_DEF;
	return ss.str();
}

int Tile::adj_bombs()
{
	return adj;
}

void Tile::set_adj(int adj)
{
	this->adj = adj;
}

bool Tile::is_bomb()
{
	return bomb;
}

void Tile::set_bomb(bool b)
{
	bomb = b;
}

bool Tile::is_flagged()
{
	return flagged;
}

void Tile::set_flagged(bool b)
{
	flagged = b;
}

bool Tile::is_hidden()
{
	return hidden;
}

void Tile::set_hidden(bool b)
{
	hidden = b;
}

std::string Tile::debug()
{
	std::stringstream ss;
	ss << "adj:\t" << this->adj << "\nbomb:\t" << this->bomb << "\nflag:\t" <<
			this->flagged << "\nhidden:\t" << this->hidden << std::endl;
	return ss.str();
}

void Tile::increment_adj()
{
	adj++;
}
