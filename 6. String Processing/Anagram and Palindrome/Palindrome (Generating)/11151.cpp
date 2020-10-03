#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int memoize(string& s, int l, int r) {
	// cout << l << " " << r << endl;
	if (l > r) {
		// puts("l>r");
		return 0;
	}
	if (dp[l][r] != -1) {
		// puts("!=1");
		return dp[l][r];
	}
	if (l == r) {
		// puts("l==r");
		dp[l][r] = 1;
		return 1;
	}
	int l2 = l;
	int r2 = r;
	// cout << l2 << " " << r2 << endl;
	while (s[r2] != s[l]) {
		r2--;
	}
	while (s[l2] != s[r]) {
		l2++;
	}
	int option1 = memoize(s, l+1, r2-1) + 2;
	int option2 = memoize(s, l2+1, r-1) + 2;
	int option3 = memoize(s, l+1, r-1);
	if (l == r2) {
		option1--;
	}
	if (l2 == r) {
		option2--;
	}
	return dp[l][r] = max(max(option1, option2), option3);

}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (size_t i = 0; i < n; i++) {
		getline(cin, s);
		// cout << s << endl;
		dp = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
		int ans = memoize(s, 0, int(s.size())-1);
		cout << ans << endl;
	}
	return 0;
}
