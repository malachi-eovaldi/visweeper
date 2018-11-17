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
	std::stringstream ss;
	if(flagged)
	{
		ss << TERM::FG_YELLOW << "F" << TERM::FG_DEF;
	}else if(hidden)
	{
		ss << TERM::FG_GREEN << "H" << TERM::FG_DEF;
	}else if(bomb)
	{
		ss << TERM::FG_RED << "B" << TERM::FG_DEF;
	}else
	{
		ss << TERM::FG_BLUE << adj << TERM::FG_DEF;
	}
	return ss.str();
}

int Tile::get_adj()
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
