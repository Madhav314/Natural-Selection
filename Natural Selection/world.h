#pragma once

#include <iostream>
#include <vector>

#include "creature.h"

class world {
public:
	const int width = 100;
	const int height = 30;
	char map[50][100];
	std::vector<creature> creatures;

	world(): map {0} {}

public:
	void print() {
		std::cout << "\n\n\n";

		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
				std::cout << map[i][j];
			}
			std::cout << '\n';
		}
	}

	void fill() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				map[i][j] = '#';
			}
		}
	}
	
};
