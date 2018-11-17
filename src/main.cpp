// main.cpp

#include<iostream>

#include "board.h"
#include "rand.h"

int main()
{
	std::ios_base::sync_with_stdio(false);
	rand_gen::time_seed();
	for(int i = 0; i < 25; i++)
		std::cout << rand_gen::get_rand_range(3, 10) << '\n';
//	Board b(24,80);
//	b.generate(50);
//	std::cout << b.repr();
}
