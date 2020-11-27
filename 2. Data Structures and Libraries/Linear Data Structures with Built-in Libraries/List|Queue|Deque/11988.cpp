#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	while (cin >> s) {
		list<char> l;
		auto it = l.begin();
		for (auto c: s) {
			if (c == '[') {
				it = l.begin();
			}
			else if (c == ']') {
				it = l.end();
			}
			else {
				l.insert(it, c);
			}
		}
		for (auto c: l) {
			cout << c;
		}
		cout << endl;
	}
	return 0;
}
