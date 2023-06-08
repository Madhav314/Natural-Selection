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
	char bedrock[50][230];
	char map[50][230];
	std::vector<species> all_species;

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
		generate_mountain();
		generate_mountain();
		generate_mountain();
		generate_mountain();
		generate_mountain();
		generate_mountain();
		generate_mountain();
		generate_mountain();
		generate_mountain();
		generate_mountain();
	}

	void generate_gaussian() {
		int i;
		int j;

		double gaussian[50][230]{};

		double sigma = 1.0;
		double r = 2.0 * sigma * sigma;
		double s = 2.0 * sigma * sigma;

		double sum = 0.0;

		for (i = 0; i < (height / 3); i++) {
			for (j = 0; j < (width / 3); j++) {
				r = std::sqrt(i * i + j * j);
				gaussian[i][j] = (std::exp(-(r * r) / s) / (3.1415926535 * s));
				sum += gaussian[i][j];
			}
		}
		
		for (i = 0; i < (height / 3); i++) {
			for (j = 0; j < (width / 3); j++) {
				gaussian[i][j] /= sum;
			}
		}



	}


	//simple function for testing
	void generate_mountain() {
		int i;
		int j;

		int x_pos = rand() % (width - 20);
		int y_pos = rand() % (height - 20);

		int size_x = rand() % 20 + 5;
		int size_y = rand() % 20 + 5;

		for (i = x_pos; i < x_pos + size_x; i++) {
			for (j = y_pos; j < y_pos + size_y; j++) {
				map[j][i] = '@';
			}
		}
	}

	void food() {

	}

	void populate(species s, int n) {

		size_t i;
		size_t j;
		int x;
		int y;

		for (i = 0; i < n; i++) {
			x = rand() % width;
			y = rand() % height;
			for (j = 0; j < s.terrain.size(); j++) {
				if (map[y][x] == s.terrain.at(j)) {
					s.creatures.push_back(creature(x, y));
					map[y][x] = s.symbol;
					break;
				}
			}

		}

	}

	void run() {
		std::cout << "ran" << std::endl;
	}

};
