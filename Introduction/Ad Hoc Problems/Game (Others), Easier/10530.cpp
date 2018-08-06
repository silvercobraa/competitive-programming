#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		vector<int> guess;
		vector<string> reply;
		guess.push_back(n);
		int correct_value = n;
		while (true) {
			string s1, s2;
			cin >> s1 >> s2;
			reply.push_back(s2);
			if (s2 == "on") {
				correct_value = guess.back();
				break;
			}
			int x;
			cin >> x;
			guess.push_back(x);
		}
		bool honest = true;
		for (guess.pop_back(), reply.pop_back(); !guess.empty() and !reply.empty(); guess.pop_back(), reply.pop_back()) {
			if (reply.back() == "high" and guess.back() <= correct_value) {
				// cout << reply.back() << " "  << guess.back() << endl;
				honest = false;
				break;
			}
			else if (reply.back() == "low" and guess.back() >= correct_value) {
				// cout << reply.back() << " "  << guess.back() << endl;
				honest = false;
				break;
			}
		}
		if (honest) {
			cout << "Stan may be honest" << endl;
		}
		else {
			cout << "Stan is dishonest" << endl;
		}
	}
	return 0;
}
