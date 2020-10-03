#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	vector<string> words;
	for (cin >> s; s != "#"; cin >> s) {
		words.push_back(s);
	}
	vector<string> sorted = words;
	for (int i = 0; i < sorted.size(); i++) {
		for (int j = 0; j < sorted[i].size(); j++) {
			if ('A' <= sorted[i][j] and sorted[i][j] <= 'Z') {
				sorted[i][j] = tolower(sorted[i][j], std::locale());
			}
		}
		sort(sorted[i].begin(), sorted[i].end());
	}
	vector<bool> ananagram(sorted.size(), true);
	for (int i = 0; i < sorted.size(); i++) {
		// if (not ananagram[i]) {
		// 	continue;
		// }
		for (int j = i + 1; j < sorted.size(); j++) {
			if (sorted[i] == sorted[j]) {
				// cout << words[i] << " " << words[j] << endl;
				// cout << sorted[i] << " " << sorted[j] << endl;
				ananagram[i] = false;
				ananagram[j] = false;
			}
		}
	}
	vector<string> ans;
	for (int i = 0; i < ananagram.size(); i++) {
		if (ananagram[i]) {
			ans.push_back(words[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto x: ans) {
		cout << x << endl;
	}
	return 0;
}
