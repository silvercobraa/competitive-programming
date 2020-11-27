#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	int case_ = 1;
	for (cin >> s; s != "end"; cin >> s, case_++) {
		// cout << s << endl;
		vector <char> tops;
		for (int i = 0; i < s.size(); i++) {
			bool assigned = false;
			for (int j = 0; j < tops.size(); j++) {
				if (tops[j] >= s[i]) {
					tops[j] = s[i];
					assigned = true;
					break;
				}
			}
			if (not assigned) {
				tops.push_back(s[i]);
			}
		}
		cout << "Case " << case_ << ": " << tops.size() << endl;
	}
	return 0;
}
