#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, m, run = 1;
	for (cin >> n; n != 0; cin >> n, run++) {
		string real_ans = "";
		string user_ans = "";
		string s;
		getline(cin, s);
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			real_ans += s;
			real_ans.push_back('\n');
		}
		cin >> m;
		getline(cin, s);
		for (int i = 0; i < m; i++) {
			getline(cin, s);
			user_ans += s;
			user_ans.push_back('\n');
		}
		cout << "Run #" << run << ": ";
		if (user_ans == real_ans) {
			cout << "Accepted";
		}
		else {
			string num1 = "";
			string num2 = "";
			for (auto c: real_ans) {
				if ('0' <= c and c <= '9') {
					num1.push_back(c);
				}
			}
			for (auto c: user_ans) {
				if ('0' <= c and c <= '9') {
					num2.push_back(c);
				}
			}
			bool equal = num1.size() == num2.size();
			if (equal) {
				for (int i = 0; i < num1.size(); i++) {
					if (num1[i] != num2[i]) {
						equal = false;
						break;
					}
				}
			}
			if (equal) {
				cout << "Presentation Error";
			}
			else {
				cout << "Wrong Answer";
			}
		}
		cout << endl;
	}
	return 0;
}
