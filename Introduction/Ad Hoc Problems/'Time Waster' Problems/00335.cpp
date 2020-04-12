#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

constexpr int INF = 99999999;

using namespace std;

bool match(string& pattern, string& text) {
	int i = pattern.size() - 1;
	int j = text.size() - 1;
	for (; i >= 0 and j >= 0; i--, j--) {
		if (pattern[i] == '*') {
			return true;
		}
		else if (pattern[i] != text[j]) {
			return false;
		}
	}
	return i == -1 and j == -1;
}

int main(int argc, char const *argv[]) {
	int N;
	cin >> N;
	string line;
	getline(cin, line);
	string machine1, machine2;
	int preference;
	vector<string> m1;
	vector<int> pref;
	vector<string> m2;
	map<string, bool> is_up;
	for (int i = 0; i < N; i++) {
		getline(cin, line);
		stringstream ss(line);
		if (line[0] != ' ') {
			ss >> machine1;
		}
		ss >> preference >> machine2;
		m1.push_back(machine1);
		pref.push_back(preference);
		m2.push_back(machine2);
		is_up[machine2] = true;
	}
	char letter;
	for (cin >> letter; letter != 'X'; cin >> letter) {
		string domain;
		cin >> domain;
		if (letter == 'U') {
			is_up[domain] = true;
		}
		else if (letter == 'D') {
			is_up[domain] = false;
		}
		else if (letter == 'A') {
			cout << domain << " =>";
			int best = INF;
			int pos = -1;
			for (int i = 0; i < N; i++) {
				if (match(m1[i], domain) and is_up[m2[i]] and pref[i] < best) {
					best = pref[i];
					pos = i;
					// cout << "match " << domain << " " << m1[i] << endl;
				}
			}
			if (pos != -1) {
				cout << " " << m2[pos];
			}
			cout << endl;
		}
	}
	return 0;
}
