// main.cpp

#include<iostream>

#include "board.h"
#include "rand.h"

int main()
{
	rand_gen::time_seed();
	Board b(80,24);
	b.generate(50);
	std::cout << b.repr();
}
