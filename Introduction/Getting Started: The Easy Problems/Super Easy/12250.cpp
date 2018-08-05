#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	int count = 1;
	for (cin >> s; s != "#"; cin >> s, count++) {
		cout << "Case " << count << ": ";
		if (s == "HELLO") {
			cout << "ENGLISH";
		}
		else if (s == "HOLA") {
			cout << "SPANISH";
		}
		else if (s == "HALLO") {
			cout << "GERMAN";
		}
		else if (s == "BONJOUR") {
			cout << "FRENCH";
		}
		else if (s == "CIAO") {
			cout << "ITALIAN";
		}
		else if (s == "ZDRAVSTVUJTE") {
			cout << "RUSSIAN";
		}
		else {
			cout << "UNKNOWN";
		}
		cout << endl;
	}
	return 0;
}
