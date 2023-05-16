#pragma once
#include <string>

class creature {
	public:

		int x;
		int y;
		bool eaten;
		bool alive;

		creature(): x(0), y(0), eaten(false), alive(true){}

		creature(int x, int y, bool eaten, bool alive): x(x), y(y), eaten(eaten), alive(alive)  {}
};

class creatures {
	public:
		std::string name;
		char symbol;
		int population;
		int speed;
		std::vector<char> terrain;
		std::vector<creature> species;

		creatures() : name("defult"), symbol('d'), population(1), speed(1), terrain(1, ' ') {}


};