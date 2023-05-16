#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include "creature.h"

class world {
public:
	const int width = 100;
	const int height = 30;
	char map[50][100];
	std::vector<creatures> all_species;

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

	void place_species(creatures creatures) {
		int i;
		int j;
		int x;
		int y;

		for (i = 0; i < creatures.species.size(); i++) {
			x = rand() % 100;
			y = rand() % 50;
			for (j = 0; j < creatures.terrain.size(); j++) {
				if (map[y][x] == creatures.terrain.at(j)) {
					map[y][x] = creatures.terrain.at(j);
					break;
				}
			}
			if (j == creatures.terrain.size()) {
				i--;
			}
		}

	}

	void place_all_species() {
		int i;

		for (i = 0; i < all_species.size(); i++) {

			place_species(all_species.at(i));
			
		}
	}


	void run() {
		place_all_species();
		std::cout << "ran" << std::endl;
	}


};
