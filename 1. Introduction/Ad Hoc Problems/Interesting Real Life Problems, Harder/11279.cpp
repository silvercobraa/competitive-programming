#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<string> querty_lower {
	"`1234567890-=",
	" qwertyuiop[]\\",
	" asdfghjkl;'",
	" zxcvbnm,./"
};

vector<string> querty_upper {
	"~!@#$%^&*()_+",
	" QWERTYUIOP{}|",
	" ASDFGHJKL:\"",
	" ZXCVBNM<>?"
};

vector<string> dvorak_lower {
	"`123qjlmfp/[] ",
	" 456.orsuyb;=\\",
	" 789aehtdck-  ",
	" 0zx,inwvg'   "
};
vector<string> dvorak_upper {
	"~!@#QJLMFP?{}",
	" $%^>ORSUYB:+|",
	" &*(AEHTDCK_",
	" )ZX<INWVG\""
};

void insert_coordinates(const vector<string>& v, map<char, pair<int, int>>& m) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] != ' ') {
				m[v[i][j]] = {i, j};
			}
		}
	}
}

double dist(const pair<int, int>& p1, const pair<int, int>& p2) {
	double first = p1.first - p2.first;
	double second = p1.second - p2.second;
	return sqrt(first*first + second*second);
}

double min_dist(const string& home_keys, const map<char, pair<int, int>>& coords, char c) {
	double result = 99999999;
	for (auto& key: home_keys) {
		auto p1 = coords.find(key);
		auto p2 = coords.find(c);
		if (p1 != coords.end() and p2 != coords.end()) {
			result = min(result, 2*dist(p1->second, p2->second));
			// cout << p1->first << " " << p2->first << " " << dist(p1->second, p2->second) << endl;
		}
	}
	return result;
}

double total_dist(const string& home_keys, const map<char, pair<int, int>>& coords, const string& line) {
	double result = 0.0;
	for (auto& c: line) {
		// char cc = tolower(c);
		auto p = coords.find(c);
		if (p != coords.end()) {
			result += min_dist(home_keys, coords, c);
		}
	}
	return result;
}

int main(int argc, char const *argv[]) {

	map<char, pair<int, int>> querty_coords;
	map<char, pair<int, int>> dvorak_coords;
	string querty_1_home = "fghj";
	string querty_2_home = "asdfjkl;";
	string dvorak_home = "ehtd";
	insert_coordinates(querty_lower, querty_coords);
	insert_coordinates(querty_upper, querty_coords);
	insert_coordinates(dvorak_lower, dvorak_coords);
	insert_coordinates(dvorak_upper, dvorak_coords);
	string line;
	while (getline(cin, line)) {
		// cout << line << endl;
		double ans1 = total_dist(querty_2_home, querty_coords, line);
		double ans2 = total_dist(querty_1_home, querty_coords, line);
		double ans3 = total_dist(dvorak_home, dvorak_coords, line);
		printf("%.2lf %.2lf %.2lf\n", ans1, ans2, ans3);
	}
	return 0;
}
