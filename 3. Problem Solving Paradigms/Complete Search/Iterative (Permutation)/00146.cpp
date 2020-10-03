#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	for (cin >> s; s != "#"; cin >> s) {
		auto ret = next_permutation(s.begin(), s.end());
		if (ret) {
			cout << s << endl;
		}
		else {
			cout << "No Successor" << endl;
		}
	}
	return 0;
}
