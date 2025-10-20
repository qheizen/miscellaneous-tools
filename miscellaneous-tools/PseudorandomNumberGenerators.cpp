#include "PseudorandomNumberGenerators.h"
#include <iostream>

std::string PRNG::_fromVectorToString(const std::vector<int> vector) {
	std::string result;
	for (int num : vector) {
		result += std::to_string(num);
	}
	return result;
}

std::vector<int> PRNG::_generateLaggedFibonacci(const std::vector<int>& init_seed, const int lag_a, const int lag_b, const int passwordLength) {
	unsigned int max_lag = std::max(lag_a, lag_b);

	if (init_seed.size() < max_lag) {
		throw "Seed is less than max_lag, we need " + std::to_string(max_lag) + ", but received " + std::to_string(init_seed.size());
	}

	std::vector<int> state = init_seed;
	std::vector<int> result;
	result.reserve(passwordLength);

	for (size_t i = 0; i < passwordLength; i++) {
		int new_value = std::abs(state[state.size() - lag_a] - state[state.size() - lag_b]);

		result.push_back(new_value);
		state.push_back(new_value);
	}
	return result;
}

std::vector<int> PRNG::_generateLinearCongruential(const int init_seed, const int a, const int c, const int m, const int passwordLength) {
	long int state = init_seed;
	std::vector<int> result;
	result.reserve(passwordLength);

	for (size_t i = 0; i < passwordLength; i++) {
		state = (a * state + c) & m;
		result.push_back(std::abs(state % 10));
	}
	return result;
}

std::vector<int> PRNG::_generateSinusoidal(const std::vector<int>& init_seed, const int passwordLength) {
	std::vector<int> result;
	result.reserve(passwordLength);

	for (size_t i = 0; i < passwordLength; i++) {
		int new_value = std::round(10 * std::sin(i / (init_seed[i] * 1.0f)));
		result.push_back(std::abs(new_value));
	}
	return result;
}

std::string PRNG::fiboRandom(const std::vector<int>& seed) {
	return _fromVectorToString(_generateLaggedFibonacci(seed));
}

std::string PRNG::sinRandom(const std::vector<int>& seed) {
	return _fromVectorToString(_generateSinusoidal(seed));
}

std::string PRNG::linearRandom(const int seed) {
	return _fromVectorToString(_generateLinearCongruential(seed));
}