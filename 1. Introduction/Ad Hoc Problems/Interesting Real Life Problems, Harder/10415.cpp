#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, vector<int>> fingers = {
	{'c', {2, 3, 4, 7, 8, 9, 10}},
	{'d', {2, 3, 4, 7, 8, 9}},
	{'e', {2, 3, 4, 7, 8}},
	{'f', {2, 3, 4, 7}},
	{'g', {2, 3, 4}},
	{'a', {2, 3}},
	{'b', {2}},
	{'C', {3}},
	{'D', {1, 2, 3, 4, 7, 8, 9}},
	{'E', {1, 2, 3, 4, 7, 8}},
	{'F', {1, 2, 3, 4, 7}},
	{'G', {1, 2, 3, 4}},
	{'A', {1, 2, 3}},
	{'B', {1, 2}},
};

int main(int argc, char const *argv[]) {
	/* code */
	int n;
	cin >> n;
	string notes;
	getline(cin, notes);
	for (int i = 0; i < n; i++) {
		getline(cin, notes);
		vector<int> count(10 + 1, 0);
		vector<bool> prev(10 + 1, false);
		for (int j = 0; j < notes.size(); j++) {
			char note = notes[j];
			if (j == 0) {
				for (auto x: fingers[note]) {
					count[x]++;
					prev[x] = true;
				}
			}
			else {
				vector<bool> new_prev(10+1, false);
				for (auto x: fingers[note]) {
					if (not prev[x]) {
						count[x]++;
					}
					new_prev[x] = true;
				}
				prev = new_prev;
			}
		}
		cout << count[1];
		for (int j = 2; j <= 10; j++) {
			cout << " " << count[j];
		}
		cout << endl;
	}
	return 0;
}
