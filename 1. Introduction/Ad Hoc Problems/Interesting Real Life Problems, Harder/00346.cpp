#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<string> notes = {
	"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#",
};

map<string,string> parse = {
	{"Ab", "G#"},
	{"A", "A"},
	{"A#", "A#"},
	{"Bb", "A#"},
	{"B", "B"},
	{"B#", "C"},
	{"Cb", "B"},
	{"C", "C"},
	{"C#", "C#"},
	{"Db", "C#"},
	{"D", "D"},
	{"D#", "D#"},
	{"Eb", "D#"},
	{"E", "E"},
	{"E#", "F"},
	{"Fb", "E"},
	{"F", "F"},
	{"F#", "F#"},
	{"Gb", "F#"},
	{"G", "G"},
	{"G#", "G#"},
	{"ab", "G#"},
	{"a", "A"},
	{"a#", "A#"},
	{"bb", "A#"},
	{"b", "B"},
	{"b#", "C"},
	{"cb", "B"},
	{"c", "C"},
	{"c#", "C#"},
	{"db", "C#"},
	{"d", "D"},
	{"d#", "D#"},
	{"eb", "D#"},
	{"e", "E"},
	{"e#", "F"},
	{"fb", "E"},
	{"f", "F"},
	{"f#", "F#"},
	{"gb", "F#"},
	{"g", "G"},
	{"g#", "G#"},
};

set<vector<string>> major;
set<vector<string>> minor;

int main(int argc, char const *argv[]) {
	string n1, n2, n3;
	for (int i = 0; i < notes.size(); i++) {
		string first = notes[i];
		string Mthird = notes[(i+4)%notes.size()];
		string mthird = notes[(i+3)%notes.size()];
		string fifth = notes[(i+7)%notes.size()];
		major.insert({first, Mthird, fifth});
		minor.insert({first, mthird, fifth});
	}
	while (cin >> n1 >> n2 >> n3) {
		cout << n1 << " " << n2 << " " << n3;
		string u1 = parse[n1];
		string u2 = parse[n2];
		string u3 = parse[n3];
		// cout << u1 << " " << u2 << " " << u3;
		if (major.find({u1, u2, u3}) != major.end() or major.find({u1, u3, u2}) != major.end()) {
			cout << " is a " << u1 << " Major chord." << endl;
		}
		else if (major.find({u2, u3, u1}) != major.end() or major.find({u2, u1, u3}) != major.end()) {
			cout << " is a " << u2 << " Major chord." << endl;
		}
		else if (major.find({u3, u1, u2}) != major.end() or major.find({u3, u2, u1}) != major.end()) {
			cout << " is a " << u3 << " Major chord." << endl;
		}
		else if (minor.find({u1, u2, u3}) != minor.end() or minor.find({u1, u3, u2}) != minor.end()) {
			cout << " is a " << u1 << " Minor chord." << endl;
		}
		else if (minor.find({u2, u3, u1}) != minor.end() or minor.find({u2, u1, u3}) != minor.end()) {
			cout << " is a " << u2 << " Minor chord." << endl;
		}
		else if (minor.find({u3, u1, u2}) != minor.end() or minor.find({u3, u2, u1}) != minor.end()) {
			cout << " is a " << u3 << " Minor chord." << endl;
		}
		else {
			cout << " is unrecognized." << endl;
		}
	}
	return 0;
}
