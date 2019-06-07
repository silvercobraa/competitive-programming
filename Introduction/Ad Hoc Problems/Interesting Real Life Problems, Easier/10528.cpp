#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

map<string,int> id = {
	{"C", 1 << 0},
	{"C#", 1 << 1},
	{"D", 1 << 2},
	{"D#", 1 << 3},
	{"E", 1 << 4},
	{"F", 1 << 5},
	{"F#", 1 << 6},
	{"G", 1 << 7},
	{"G#", 1 << 8},
	{"A", 1 << 9},
	{"A#", 1 << 10},
	{"B", 1 << 11},
};

map<string, int> scale;

int main(int argc, char const *argv[]) {
	string s;
	vector<string> notes = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
	vector<int> intervals = {0, 2, 4, 5, 7, 9, 11};
	for (int i = 0; i < notes.size(); i++) {
		for (auto j: intervals) {
			string note = notes[(i + j) % 12];
			scale[notes[i]] |= id[note];
		}
	}
	for (getline(cin, s); s != "END"; getline(cin, s)) {
		stringstream ss(s);
		int bits = 0;
		string note;
		while (ss >> note) {
			bits |= id[note];
		}
		bool first = true;
		for (int i = 0; i < notes.size(); i++) {
			int bits1 = bits;
			int bits2 = scale[notes[i]];
			// printf("%x %x\n", bits1, bits2);
			bool flag = true;
			for (int j = 0; j < 12; j++) {
				if ((bits1 & 1) and not (bits2 & 1)) {
					flag = false;
					break;
				}
				bits1 >>= 1;
				bits2 >>= 1;
			}
			if (flag) {
				if (first) {
					first = false;
				}
				else {
					cout << " ";
				}
				cout << notes[i];
			}
		}
		cout << endl;
	}
	return 0;
}
