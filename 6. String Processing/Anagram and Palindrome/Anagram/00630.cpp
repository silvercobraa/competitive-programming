#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		int n;
		cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++) {
			cin >> words[i];
		}
		// sort(words.begin(), words.end());
		vector<string> sorted = words;
		for (int i = 0; i < sorted.size(); i++) {
			sort(sorted[i].begin(), sorted[i].end());
		}
		string s;
		for (cin >> s; s != "END"; cin >> s) {
			string ss = s;
			sort(ss.begin(), ss.end());
			vector<int> matches;
			for (int i = 0; i < sorted.size(); i++) {
				if (ss == sorted[i]) {
					matches.push_back(i);
				}
			}
			cout << "Anagrams for: " << s << endl;
			if (matches.size() == 0) {
				cout << "No anagrams for: " << s << endl;
			}
			else {
				for (int i = 0; i < matches.size(); i++) {
					cout << setw(3) << i + 1;
					cout << ") " << words[matches[i]] << endl;
				}
			}
		}
	}
	return 0;
}
