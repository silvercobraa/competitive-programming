#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

map<char, int> suit = {
	{'C', 0},
	{'D', 1},
	{'S', 2},
	{'H', 3},
};

// donde chucha esta definida rank en la biblioteca estandar??
map<char, int> rank_ = {
	{'2', 0},
	{'3', 1},
	{'4', 2},
	{'5', 3},
	{'6', 4},
	{'7', 5},
	{'8', 6},
	{'9', 7},
	{'T', 8},
	{'J', 9},
	{'Q', 10},
	{'K', 11},
	{'A', 12},
};

bool compare(const string& s1, const string& s2) {
	if (suit[s1[0]] < suit[s2[0]]) {
		return true;
	}
	else if (suit[s1[0]] == suit[s2[0]]) {
		if (rank_[s1[1]] < rank_[s2[1]]) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main(int argc, char const *argv[]) {
	vector<char> direction = {'S', 'W', 'N', 'E'};
	char dealer;
	for (cin >> dealer; dealer != '#'; cin >> dealer) {
		int first = -1;
		for (size_t i = 0; i < 4; i++) {
			if (direction[i] == dealer) {
				first = i;
			}
		}
		string s1, s2;
		cin >> s1 >> s2;
		s1 += s2;
		int ptr = (first + 1) % 4;
		// cout << s1 << " " << s2 << endl;
		vector<vector<string>> cards(4);
		for (size_t i = 0; i < s1.size(); i += 2) {
			string card = s1.substr(i, 2);
			cards[ptr].push_back(card);
			ptr = (ptr + 1) % 4;
		}
		for (size_t i = 0; i < 4; i++) {
			cout << direction[i] << ":";
			sort(cards[i].begin(), cards[i].end(), compare);
			for (size_t j = 0; j < cards[i].size(); j++) {
				cout << " " << cards[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
