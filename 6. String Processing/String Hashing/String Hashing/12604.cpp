#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string A;
unordered_map<char, int> m;

void encode(string& source, string& target, int shift) {
	for (int i = 0; i < source.size(); i++) {
		target[i] = A[(m[source[i]] + shift) % A.size()];
	}
}

int search(string& haystack, string& needle) {
	int matches = 0;
	vector<int> lps(needle.size()+1);
	lps[0] = -1;
	int i = 0, j = -1;
	while (i < needle.size()) {
		while (j >= 0 and needle[i] != needle[j]) {
			// cout << i << " " << j << endl;
			j = lps[j];
		}
		i++;
		j++;
		// cout << i << " asignado a " << j << endl;
		lps[i] = j;
	}
	// i iterador en haystack, j iterador en needle
	i = 0, j = 0;
	while (i < haystack.size()) {
		while (j >= 0 and haystack[i] != needle[j]) {
			j = lps[j];
		}
		i++;
		j++;
		if (j == needle.size()) {
			matches++;
			if (matches > 1) {
				return matches;
			}
		}
	}
	return matches;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		string W, S;
		cin >> A >> W >> S;
		string encoded = W;
		m.clear();
		for (size_t i = 0; i < A.size(); i++) {
			m[A[i]] = i;
		}
		vector<int> solution;
		for (size_t shift = 0; shift < A.size(); shift++) {
			encode(W, encoded, shift);
			// cout << W << " " << encoded << endl;
			int matches = search(S, encoded);
			if (matches == 1) {
				solution.push_back(shift);
			}
		}
		if (solution.size() == 0) {
			puts("no solution");
		}
		else if (solution.size() == 1) {
			cout << "unique: " << solution[0] << endl;
		}
		else {
			cout << "ambiguous:";
			for (auto shift: solution) {
				cout << " " << shift;
			}
			cout << endl;
		}
	}
	return 0;
}
