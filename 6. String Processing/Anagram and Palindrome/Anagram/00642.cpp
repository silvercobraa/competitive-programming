#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	vector<string> words;
	for (cin >> s; s != "XXXXXX"; cin >> s) {
		words.push_back(s);
	}
	sort(words.begin(), words.end());
	vector<string> sorted = words;
	for (int i = 0; i < sorted.size(); i++) {
		sort(sorted[i].begin(), sorted[i].end());
	}
	for (cin >> s; s != "XXXXXX"; cin >> s) {
		string ss = s;
		sort(ss.begin(), ss.end());
		int count = 0;
		for (int i = 0; i < sorted.size(); i++) {
			if (ss == sorted[i]) {
				cout << words[i] << endl;
				count++;
			}
		}
		if (count == 0) {
			cout << "NOT A VALID WORD" << endl;
		}
		cout << "******" << endl;
	}
	return 0;
}
