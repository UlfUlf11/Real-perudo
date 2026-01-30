#pragma once
#include <vector>

std::vector<int> Generate(int number) {
	std::vector<int> v;
	v.reserve(5);	

	for (int i = 0; i < number; ++i) {
		v.push_back(rand() % 6 + 1);
	}

	return v;
}

void GenerateDicesForPlayers() {
	
}