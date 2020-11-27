#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<string> words;
set<string> word_set;
map<char, int> phrase_count;
map<char, int> anagram_count;
vector<int> ans;
string s;

void print(map<char, int>& m) {
	for (auto p: m) {
		if (p.second != 0)
			cout << p.first << " " << p.second << "  ";
	}
	cout << endl;
}


void backtrack(int k) {
	// cout << k << endl;
	// print(anagram_count);
	// cout << "parcial:";
	// for (auto i: ans) {
	// 	cout << " " << words[i];
	// }
	// cout << endl;
	// if (k == words.size()) {
	// 	// cout << "entra" << endl;
	// 	// if (phrase_count.size() == anagram_count.size()) {
	// 		bool valid = true;
	// 		for (auto p: phrase_count) {
	// 			if (phrase_count[p.first] - anagram_count[p.first] != 0) {
	// 				valid = false;
	// 				break;
	// 			}
	// 		}
	// 		for (auto p: anagram_count) {
	// 			if (anagram_count[p.first] - phrase_count[p.first] != 0) {
	// 				valid = false;
	// 				break;
	// 			}
	// 		}
	// 		if (valid) {
	// 			// print(anagram_count);
	// 			cout << s << " =";
	// 			for (auto i: ans) {
	// 				cout << " " << words[i];
	// 			}
	// 			cout << endl;
	// 		}
	// 	// }
	// 	return;
	// }
	for (int i = k; i < words.size(); i++) {
		for (char c: words[i]) {
			anagram_count[c]++;
		}
		bool flag = true;
		for (char c: words[i]) {
			if (anagram_count[c] > phrase_count[c]) {
				flag = false;
			}
		}
		if (flag) {
			ans.push_back(i);
			backtrack(i + 1);
			ans.pop_back();
		}
		for (char c: words[i]) {
			anagram_count[c]--;
		}
	}
	// print(anagram_count);
	// cout << "parcial:";
	// for (auto i: ans) {
	// 	cout << " " << words[i];
	// }
	// cout << endl;
	bool valid = true;
	for (auto p: phrase_count) {
		if (phrase_count[p.first] - anagram_count[p.first] != 0) {
			valid = false;
			break;
		}
	}
	for (auto p: anagram_count) {
		if (anagram_count[p.first] - phrase_count[p.first] != 0) {
			valid = false;
			break;
		}
	}
	bool flag = true;
	for (auto i: ans) {
		// cout << words[i] << endl;
		if (word_set.find(words[i]) != word_set.end()) {
			flag = false;
			break;
		}
	}
	if (valid and flag) {
	// if (valid) {
		// print(anagram_count);
		cout << s << " =";
		for (auto i: ans) {
			cout << " " << words[i];
		}
		cout << endl;
	}
}


int main(int argc, char const *argv[]) {
	for (getline(cin, s); s != "#"; getline(cin, s)) {
		words.push_back(s);
	}
	for (getline(cin, s); s != "#"; getline(cin, s)) {
		// cout << "phrase: " << s << endl;
		stringstream ss(s);
		string aux;
		while (ss >> aux) {
			// cout << aux << endl;
			word_set.insert(aux);
		}
		for (char c: s) {
			if (c != ' ') {
				phrase_count[c]++;
			}
		}
		// print(phrase_count);
		backtrack(0);
		word_set.clear();
		phrase_count.clear();
		anagram_count.clear();
		ans.clear();
	}
	return 0;
}
