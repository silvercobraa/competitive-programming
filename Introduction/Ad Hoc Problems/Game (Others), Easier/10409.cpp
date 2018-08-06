#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& die, int face1, int face2, int face3, int face4) {
	int aux = die[face1];
	die[face1] = die[face2];
	die[face2] = die[face3];
	die[face3] = die[face4];
	die[face4] = aux;
}

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		enum Face {TOP, NORTH, WEST, EAST, SOUTH, BOTTOM};
		vector<int> die = {1, 2, 3, 4, 5, 6};
		for (int i = 0; i < n; i++) {
			string command;
			cin >> command;
			if (command == "north") {
				rotate(die, NORTH, TOP, SOUTH, BOTTOM);
			}
			else if (command == "south") {
				rotate(die, SOUTH, TOP, NORTH, BOTTOM);
			}
			else if (command == "west") {
				rotate(die, WEST, TOP, EAST, BOTTOM);
			}
			else if (command == "east") {
				rotate(die, EAST, TOP, WEST, BOTTOM);
			}
		}
		cout << die[TOP] << endl;
	}

	return 0;
}
