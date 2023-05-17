#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
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
				map[i][j] = '~';
			}
		}
	}

	void generate_terrain() {
		std::cout << "terrain generated" << std::endl;
		generate_mountains();
	}

	void generate_mountains() {
		int i;
		int j;

		int peek_x = rand() % 230;
		int peek_y = rand() % 50;

		int range_x = 1;
		int range_y =1;

		int p[20];

		for (i = 0; i < 20; i++) {
			p[i] = (int)(100*(std::exp(-0.1*i) + 0.5));
		}

		for (i = 0; i < range_y; i++) {
			for (j = 0; j < range_x; j++) {
				if (range_x > width - peek_x) {
					break;
				}
				if (p[j] > (rand() % 90)) {
					map[peek_y + i][peek_x + j] = '@';
				}
				range_x++;
			}
			if (range_y > height - peek_y) {
				break;
			}
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
