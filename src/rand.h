// rand.h
#pragma once

#include<random>
#include<time.h>

namespace rand_gen
{
	void time_seed();
	int get_rand();
	int get_rand_range(int high);
	int get_rand_range(int low, int high);
}
