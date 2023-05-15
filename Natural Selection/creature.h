#pragma once
#include <string>

struct position {
	int x;
	int y;
};


class creature {
	public:
		std::string name;
		char symbol;
		int population;
		std::vector<position> positions;
		bool eaten;

		int speed;
		int energy;

		creature() : name("name"), symbol('?'), population(0), eaten(false), speed(1), energy(1) {}

		creature(std::string name, char symbol, int speed, int energy): name(name), symbol(symbol), speed(speed), energy(energy) {}
};