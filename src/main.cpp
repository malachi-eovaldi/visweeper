// main.cpp

#include<iostream>

#include "board.h"
#include "rand.h"

int main()
{
	rand_gen::time_seed();
	Board b(10,10);
	b.generate(10);
	std::cout << b.repr();
}
