#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		vector<int> original;
		int x;
		for (cin >> x; x != 99; cin >> x) {
			original.push_back(x);
		}
		vector<int> position = original;
		vector<int> parked(position.size(), false);
		int empty;
		string s;
		getline(cin, s);
		for (getline(cin, s); s != ""; getline(cin, s)) {
			stringstream ss(s);
			ss >> empty;
			bool assigned = false;
			while (not assigned) {
				for (int i = 0; i < position.size(); i++) {
					if (position[i] == empty and not parked[i]) {
						parked[i] = true;
						assigned = true;
						break;
					}
				}
				if (assigned) {
					break;
				}
				for (int i = 0; i < position.size(); i++) {
					if (not parked[i]) {
						position[i] = position[i]%20 + 1;
					}
				}
			}
		}
		for (int i = 0; i < position.size(); i++) {
			if (parked[i]) {
				printf("Original position %d parked in %d\n", original[i], position[i]);
			}
			else {
				printf("Original position %d did not park\n", original[i]);
			}
		}
	}
	return 0;
}
