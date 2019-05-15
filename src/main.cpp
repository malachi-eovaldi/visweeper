// main.cpp

#include<iostream>
#include<random>
#include<time.h>

#include "board.h"

int main()
{
	//Disabled now for testing so the same board generates every time
	//srand(time(NULL));
	Board b(10,10);
	b.generate(10);

	int x, y;
	do
	{
		std::cout << b.repr();
		std::cout << "Please type the x coordinate to open: ";
		std::cin >> x;
		std::cout << "Please type the y coordinate to open: ";
		std::cin >> y;
		b.auto_open_at(x, y);
	}while(!std::cin.eof());
}
