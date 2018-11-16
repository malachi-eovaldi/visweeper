// main.cpp

#include<iostream>

#include "board.h"

int main()
{
	std::ios_base::sync_with_stdio(false);
	Board b(10,10);
	b.generate();
	std::cout << b.repr();
}
