#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

long dp(vector<vector<long>>& DP, string& s, int start, int end) {
	// // cout << start << " " << end << endl;
	// if (start + 1 == end) {
	// 	return long(s[start]);
	// }
	if (DP[start][end] != -1) {
		return DP[start][end];
	}
	long ans = 0;
	for (int k = start+1; k < end; k++) {
		long term1 = dp(DP, s, start, k);
		long term2 = dp(DP, s, k, end);
		ans = max(ans,  term1 + term2);
	}
	// si tiene 10 o menos dígitos
	if (end - start <= 10) {
		long l = stol(s.substr(start, end-start));
		if (l <= long(INT_MAX)) {
			// cout << l << endl;
			ans = max(ans, l);
		}
	}
	return DP[start][end] = ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		// vector<vector<long>> maxsum(s.size()+1, vector<long>(s.size()+1, -1));
		// for (int j = 0; j < s.size(); j++) {
		// 	maxsum[j][j+1] = long(s[j] - '0');
		// }
		// long ans = dp(maxsum, s, 0, s.size());
		// cout << ans << endl;

		// suma maxima de posicion i hasta la ultima
		vector<long> maxsum(s.size()+1, 0);
		maxsum[int(s.size())-1] = s[int(s.size())-1] - '0';
		for (int i = int(s.size())-2; i >= 0; i--) {
			long sum = 0;
			int j = i;
			do {
				sum *= 10;
				sum += long(s[j] - '0');
				if (sum > long(INT_MAX)) {
					break;
				}
				long curr = sum + maxsum[j+1];
				// cout << sum << " + " << maxsum[j+1] << " = " << curr << endl;
				maxsum[i] = max(maxsum[i], curr);
				j++;
			} while (j < s.size());
		}
		cout << maxsum[0] << endl;
	}

	return 0;
}
