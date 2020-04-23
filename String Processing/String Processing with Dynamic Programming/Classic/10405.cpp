#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dp;

void lcs(string& s1, string& s2) {
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			int left = dp[i+1][j];
			int up = dp[i][j+1];
			int diag = s1[i] == s2[j] ? dp[i][j] + 1 : dp[i][j];
			dp[i+1][j+1] = max(diag, max(left, up));
		}
	}
}

int main(int argc, char const *argv[]) {
	string s1, s2;
	while (getline(cin, s1)) {
		getline(cin, s2);
		dp = vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, 0));
		lcs(s1, s2);
		cout << dp[s1.size()][s2.size()] << endl;
	}
	return 0;
}
