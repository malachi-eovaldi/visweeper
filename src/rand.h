// rand.h
#pragma once

#include<random>
#include<time.h>

namespace rand_gen // Global rand helper to avoid multiple rands
{
	void time_seed(); // Seed with the time
	int get_rand(); // Get random int from std::rand
	int get_rand_range(int high); // Get random int below high
	int get_rand_range(int low, int high); // Get random int between high and low
}
