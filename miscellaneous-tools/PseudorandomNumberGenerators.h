#ifndef PSEUDORANDOM
#define PSEUDORANDOM
#pragma once

#include <string>
#include <vector>

class PRNG {
private:
	std::string _fromVectorToString(const std::vector<int> vector);

	std::vector<int> _generateLaggedFibonacci(const std::vector<int>& seed, const int lag_a = 17, const int lag_b = 5, const int passwordLength = 7);
	std::vector<int> _generateLinearCongruential(const int seed, const int a = 1664525, const int c = 1013904223, const int m = 0xffffffff, const int passwordLength = 12);
	std::vector<int> _generateSinusoidal(const std::vector<int>& init_seed, const int passwordLength = 10);

public:
	std::string fiboRandom(const std::vector<int>& seed);
	std::string sinRandom(const std::vector<int>& seed);
	std::string linearRandom(const int seed);
};

#endif