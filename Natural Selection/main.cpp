#include "world.h"

int main() {
	world world;


	
	srand((int)std::time(NULL));

	world.fill();
	world.generate_terrain();

	species A;

	world.populate(A, 50);
	world.print();
	std::cerr << "\nDone.\n";

}