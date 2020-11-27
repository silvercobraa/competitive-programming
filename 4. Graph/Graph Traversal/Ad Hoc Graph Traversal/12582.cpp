#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		string s;
		cin >> s;
		stack<char> stk;
		map<char, int> degree;
		stk.push(s[0]);
		for (int pos = 1; pos < s.size(); pos++) {
			// cout << pos << endl;
			if (s[pos] == stk.top()) {
				stk.pop();
			}
			else {
				++degree[s[pos]];
				++degree[stk.top()];
				stk.push(s[pos]);
			}
		}
		printf("Case %d\n", t+1);
		for (auto p: degree) {
			printf("%c = %d\n", p.first, p.second);
		}
	}
	return 0;
}
