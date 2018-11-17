// rand.cpp

#include "rand.h"

void rand_gen::time_seed()
{
	srand(time(NULL));
}

int rand_gen::get_rand()
{
	return rand();
}

int rand_gen::get_rand_range(int high)
{
	return rand() % high;
}

int rand_gen::get_rand_range(int low, int high)
{
	return rand() % (high - low) + low;
}
