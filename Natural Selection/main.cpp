#include "world.h"

int main() {
	world world;


	
	srand((int)std::time(NULL));

	
	world.generate_mountains();

	//world.fill();
	//world.print();
	std::cerr << "\nDone.\n";
}