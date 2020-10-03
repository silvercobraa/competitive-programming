#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int strong, weak;

int match(string& sol, string& ans, int sg) {
	// int sg = 0;
	int wk = 0;
	multiset<char> s1, s2;
	for (int i = 0; i < sol.size(); i++) {
		// if (sol[i] == ans[i]) {
		// 	sg++;
		// }
		s1.insert(sol[i]);
		s2.insert(ans[i]);
	}
	multiset<char> inter;
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(inter, inter.begin()));
	wk = int(inter.size()) - strong;
	// wk = int(inter.size()) - sg;
	return strong == sg and weak == wk;
}

int backtrack(string& sol, string& ans, int k, int sg) {
	if (sg > strong) {
		return 0;
	}
	if (k == sol.size()) {
		return match(sol, ans, sg);
	}
	int ret = 0;
	for (char c = '1'; c <= '9'; c++) {
		ans.push_back(c);
		if (c == sol[k]) {
			ret += backtrack(sol, ans, k + 1, sg + 1);
		}
		else {
			ret += backtrack(sol, ans, k + 1, sg);
		}
		ans.pop_back();
	}
	return ret;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (int t = 0; t < n; t++) {
		string solution;
		cin >> solution >> strong >> weak;
		string ans;
		cout << backtrack(solution, ans, 0, 0) << endl;
	}
	return 0;
}
