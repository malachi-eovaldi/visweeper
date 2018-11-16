// main.cpp

#include<iostream>

#include "tile.h"

int main()
{
	Tile t;
	t.set_hidden(false);
	t.set_adj(5);
	std::cout << t.debug();
	std::cout << t.repr() << std::endl;
}
