#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, vector<string>> scale = {
	{"Gb", {"Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F",}},
	{"Db", {"Db", "Eb", "F", "Gb", "Ab", "Bb", "C"}},
	{"Ab", {"Ab", "Bb", "C", "Db", "Eb", "F", "G"}},
	{"Eb", {"Eb", "F", "G", "Ab", "Bb", "C", "D"}},
	{"Bb", {"Bb", "C", "D", "Eb", "F", "G", "A"}},
	{"F", {"F", "G", "A", "Bb", "C", "D", "E"}},
	{"C", {"C", "D", "E", "F", "G", "A", "B"}},
	{"G", {"G", "A", "B", "C", "D", "E", "F#"}},
	{"D", {"D", "E", "F#", "G", "A", "B", "C#"}},
	{"A", {"A", "B", "C#", "D", "E", "F#", "G#"}},
	{"E", {"E", "F#", "G#", "A", "B", "C#", "D#"}},
	{"B", {"B", "C#", "D#", "E", "F#", "G#", "A#"}},
};

// HAAAAAACK, el espacio es para no tener que limpiar el string
map<string, int> interval = {
	{" SECOND", 1},
	{" THIRD", 2},
	{" FOURTH", 3},
	{" FIFTH", 4},
	{" SIXTH", 5},
	{" SEVENTH", 6},
	{" OCTAVE", 7},
};

int main(int argc, char const *argv[]) {
	string key;
	while (getline(cin, key)) {
		cout << "Key of " << key << endl;
		string tmp;
		getline(cin, tmp);
		stringstream ss (tmp);
		string note, dir, inter;
		while (ss >> note >> dir and getline(ss, inter, ';')) {
			int pos = -1;
			for (int i = 0; i < scale[key].size(); i++) {
				if (scale[key][i] == note) {
					pos = i;
					break;
				}
			}
			if (pos == -1) {
				cout << note << ": invalid note for this key" << endl;
			}
			else {
				int i = interval[inter];
				if (dir == "DOWN") {
					i = 7 - i;
				}
				string ans = scale[key][(pos + i)%7];
				cout << note << ": " << dir << inter << " > " << ans << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
