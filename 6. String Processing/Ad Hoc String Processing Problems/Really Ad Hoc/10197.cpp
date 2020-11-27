#include <iostream>
#include <map>
#include <string>

using namespace std;

void conjugate(string root, char tv) {
	cout << "eu        " << root << 'o' << endl;
	cout << "tu        " << root;
	if (tv == 'i') {
		cout << "es" << endl;
	}
	else {
		cout << tv << "s" << endl;
	}
	cout << "ele/ela   " << root;
	if (tv == 'i') {
		cout << "e" << endl;
	}
	else {
		cout << tv << endl;
	}
	cout << "n";
	printf("%c", (char)243);
	cout << "s       " << root << tv << "mos" << endl;
	cout << "v";
	printf("%c", (char)243);
	cout << "s       " << root;
	if (tv == 'i') {
		cout << tv << "s" << endl;
	}
	else {
		cout << tv << "is" << endl;
	}
	cout << "eles/elas " << root;
	if (tv == 'i') {
		cout << "em" << endl;
	}
	else {
		cout << tv << "m" << endl;
	}
}

int main(int argc, char const *argv[]) {
	string pt, eng;
	map<string, string> dict;
	bool first = true;
	while (cin >> pt >> eng) {
		if (not first) {
			puts("");
		}
		cout << pt << " (to " << eng << ")" << endl;
		dict[pt] = eng;
		if (pt.size() >= 2 and pt[pt.size() - 1] == 'r') {
			char c = pt[pt.size() - 2];
			if (c == 'a' or c == 'e' or c == 'i') {
				conjugate(pt.substr(0, pt.size()-2), c);
			}
			else {
				puts("Unknown conjugation");
			}
		}
		else {
			puts("Unknown conjugation");
		}
		first = false;
	}
	return 0;
}
