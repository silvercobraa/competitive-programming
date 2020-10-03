#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

// vector<string> allels = {"AA", "AB", "AO", "BB", "BO", "OO"};

// map<pair<char,char>, string> abo = {
// 	{{'A', 'A'}, "A"},
// 	{{'A', 'B'}, "AB"},
// 	{{'A', 'O'}, "A"},
// 	{{'B', 'A'}, "AB"},
// 	{{'B', 'B'}, "B"},
// 	{{'B', 'O'}, "B"},
// 	{{'O', 'A'}, "A"},
// 	{{'O', 'B'}, "B"},
// 	{{'O', 'O'}, "O"},
// };
// map<pair<char,char>, string> abo = {
map<pair<string, string>, string> abo = {
	{{"A+", "A+"}, "A+"},
	{{"A+", "A-"}, "A+"},
	{{"A-", "A+"}, "A+"},
	{{"A-", "A-"}, "A-"},
	{{"A+", "B+"}, "AB+"},
	{{"A+", "B-"}, "AB+"},
	{{"A-", "B+"}, "AB+"},
	{{"A-", "B-"}, "AB-"},
	{{"A+", "O+"}, "A+"},
	{{"A+", "O-"}, "A+"},
	{{"A-", "O+"}, "A+"},
	{{"A-", "O-"}, "A-"},
	{{"B+", "A+"}, "AB+"},
	{{"B+", "A-"}, "AB+"},
	{{"B-", "A+"}, "AB+"},
	{{"B-", "A-"}, "AB-"},
	{{"B+", "B+"}, "B+"},
	{{"B+", "B-"}, "B+"},
	{{"B-", "B+"}, "B+"},
	{{"B-", "B-"}, "B-"},
	{{"B+", "O+"}, "B+"},
	{{"B+", "O-"}, "B+"},
	{{"B-", "O+"}, "B+"},
	{{"B-", "O-"}, "B-"},
	{{"O+", "A+"}, "A+"},
	{{"O+", "A-"}, "A+"},
	{{"O-", "A+"}, "A+"},
	{{"O-", "A-"}, "A-"},
	{{"O+", "B+"}, "B+"},
	{{"O+", "B-"}, "B+"},
	{{"O-", "B+"}, "B+"},
	{{"O-", "B-"}, "B-"},
	{{"O+", "O+"}, "O+"},
	{{"O+", "O-"}, "O+"},
	{{"O-", "O+"}, "O+"},
	{{"O-", "O-"}, "O-"},
};

// vector<string> bloods = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
vector<string> bloods = {"O-", "O+", "AB-", "AB+", "B-", "B+", "A-", "A+"};

// map<string, vector<vector<string, string>>> parent = {
map<string, vector<vector<string>>> parent = {
// map<string, vector<string>> parent = {
	// {"A", {"AA", "AO"}},
	// {"B", {"BB", "BO"}},
	// {"AB", {"AB"}},
	// {"O", {"OO"}},
	{"A+", {{"A+", "A+"}, {"A+", "A-"}, {"A+", "O+"}, {"A+", "O-"}, {"A-", "O+"}, }},
	{"A-", {{"A-", "A-"}, {"A-", "O-"}, }},
	{"B+", {{"B+", "B+"}, {"B+", "B-"}, {"B+", "O+"}, {"B+", "O-"}, {"B-", "O+"}, }},
	{"B-", {{"B-", "B-"}, {"B-", "O-"}, }},
	{"AB+", {{"A+", "B+"}, {"A+", "B-"}, {"A-", "B+"}, }},
	{"AB-", {{"A-", "B-"}, }},
	{"O+", {{"O+", "O+"}, {"O+", "O-"}, {"O-", "O+"}, }},
	{"O-", {{"O-", "O-"}, }},
};

map<pair<char, char>, char> sign = {
	{{'+', '+'}, '+'},
	{{'+', '-'}, '+'},
	{{'-', '+'}, '+'},
	{{'-', '-'}, '-'},
};

bool valid(string s1, string s2, string s3) {
	// char rh1 = s1.back();
	// char rh2 = s2.back();
	// char rh3 = s3.back();
	// if (not (rh1 == '-' and rh2 == '-' and rh3 == '+')) {
	// 	return false;
	// }
	// s1.pop_back();
	// s2.pop_back();
	// s3.pop_back();
	auto p1 = parent[s1];
	auto p2 = parent[s2];
	for (auto all1: p1) {
		for (auto all2: p2) {
			for (auto c1: all1) {
				for (auto c2: all2) {
					// cout << "probando " << c1 << " " << c2 << " " << abo[{c1, c2}] << endl;
					if (abo[{c1, c2}] == s3) {
						// cout << "true" << endl;
						return true;
					}
				}
			}
		}
	}
	return false;
}

void print_set(set<string>& s) {
	if (s.empty()) {
		cout << "IMPOSSIBLE";
	}
	else if (s.size() == 1) {
		cout << *s.begin();
	}
	else {
		cout << "{";
		// for (auto ss: s) {
		// 	if (ss != *s.begin()) {
		// 		cout << ", ";
		// 	}
		// 	cout << ss;
		// }
		bool first = true;
		for (auto blood: bloods) {
			if (s.find(blood) != s.end()) {
				if (first) {
					first = false;
				}
				else {
					cout << ", ";
				}
				cout << blood;
			}
		}
		cout << "}";
	}
}

void test(string s1, string s2, string s3) {
	set<string> ans;
	if (s1 == "?") {
		for (auto blood: bloods) {
			// cout << blood << " " << s2 << " " << s3 << endl;
			if (valid(blood, s2, s3)) {
				ans.insert(blood);
			}
		}
		print_set(ans);
		cout << " " << s2 << " " << s3 << endl;
	}
	else if (s2 == "?") {
		for (auto blood: bloods) {
			// cout << s1 << " " << blood << " " << s3 << endl;
			if (valid(s1, blood, s3)) {
				ans.insert(blood);
			}
		}
		cout << s1 << " ";
		print_set(ans);
		cout << " " << s3 << endl;
	}
	else if (s3 == "?") {
		for (auto blood: bloods) {
			// cout << s1 << " " << s2 << " " << blood << endl;
			if (valid(s1, s2, blood)) {
				ans.insert(blood);
			}
		}
		cout << s1 << " " << s2 << " ";
		print_set(ans);
		cout << endl;
	}
}

int main(int argc, char const *argv[]) {
	string b1, b2, b3;
	int count = 1;
	for (cin>>b1>>b2>>b3;b1!="E" or b2!="N" or b3!="D";cin>>b1>>b2>>b3) {
		cout << "Case " << count << ": ";
		test(b1, b2, b3);
		count++;
	}
	return 0;
}
