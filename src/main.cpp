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
		std::cout << "Please type the x coordinate to flag: ";
		std::cin >> x;
		std::cout << "Please type the y coordinate to flag: ";
		std::cin >> y;
		b.toggle_flag_at(x, y);
	}while(!std::cin.eof());
}
