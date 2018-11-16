// main.cpp

#include<iostream>

#include "tile.h"

int main()
{
	Tile t;
	std::cout << t.debug();
	std::cout << t.repr() << std::endl;
}
