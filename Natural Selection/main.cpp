#include "world.h"

int main() {
	world world;


	
	srand((int)std::time(NULL));

	world.fill();
	world.generate_terrain();
	world.print();
	std::cerr << "\nDone.\n";
}