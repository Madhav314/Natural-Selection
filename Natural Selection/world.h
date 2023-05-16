#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>

#include "creature.h"

class world {
public:
	const int width = 230;
	const int height = 50;
	char map[50][230];
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

	void generate_terrain() {
		std::cout << "terrain generated" << std::endl;
	}

	void generate_mountains() {
		std::default_random_engine generator;
		std::binomial_distribution<int> d(10, 0.5F);

		int i;
		int p[20] = {};
		int n;

		for (i = 0; i < 100; i++) {
			n = d(generator);
			++p[n];
		}
		for (i = 0; i < 20; i++) {
			std::cout << std::to_string(p[i]/10.0F) << " ";
		}
	}

	void place_species(creatures creatures) {
		int i;
		int j;
		int x;
		int y;

		for (i = 0; i < creatures.species.size(); i++) {
			x = rand() % width;
			y = rand() % height;
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
