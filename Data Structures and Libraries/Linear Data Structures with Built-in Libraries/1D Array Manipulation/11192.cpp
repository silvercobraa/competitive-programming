#include <iostream>
#include <string>

using namespace std;

void flip(string& s, int l, int offset) {
	for (int i = 0; i < l/2; i++) {
		// cout << "swapping " << offset + i << " con " << offset + l - i - 1 << endl;
		char tmp = s[offset + i];
		s[offset + i] = s[offset + l - i - 1];
		s[offset + l - i - 1] = tmp;
	}
}

int main(int argc, char const *argv[]) {
	int l;
	for (cin >> l; l != 0; cin >> l) {
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i += s.size()/l) {
			// cout << i << " ";
			flip(s, s.size()/l, i);
		}
		cout << s << endl;
	}
	return 0;
}
