// main.cpp

#include<iostream>

#include "board.h"
#include "rand.h"

int main()
{
	Board b(24,80);
	b.generate(50);
	std::cout << b.repr();
}
