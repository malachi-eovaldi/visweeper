// main.cpp

#include<iostream>

#include "board.h"
#include "rand.h"

int main()
{
	rand_gen::time_seed();
	Board b(10,10);
	b.generate(10);

	int x, y;
	do
	{
		std::cout << b.repr();
		std::cout << "Please type the x coordinate to expose: ";
		std::cin >> x;
		std::cout << "Please type the y coordinate to expose: ";
		std::cin >> y;
		b.open_tile_at(x, y);
	}while(!std::cin.eof());
}
