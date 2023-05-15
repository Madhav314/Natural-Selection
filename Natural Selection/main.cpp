#include <ctime>

#include "world.h"

int main() {
	world world;

	creature D("default", 'D', 1, 1);
	creature S("default", 'A', 2, 1);

	world.creatures.push_back(D);
	world.creatures.push_back(S);
	
	srand((int)std::time(NULL));
	world.fill();
	world.print();
	std::cerr << "\nDone.\n";
}