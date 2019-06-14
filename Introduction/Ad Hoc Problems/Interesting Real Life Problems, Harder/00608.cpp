#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s1, s2, s3;
		vector<bool> v(12, true);
		set<char> light = {'A','B','C','D','E','F','G','H','I','J','K','L'};
		set<char> heavy = {'A','B','C','D','E','F','G','H','I','J','K','L'};
		for (int j = 0; j < 3; j++) {
			cin >> s1 >> s2 >> s3;
			if (s3 == "even") {
				for (auto c: s1) {
					v[c - 'A'] = false;
				}
				for (auto c: s2) {
					v[c - 'A'] = false;
				}
			}
			else if (s3 == "up") {
				set<char> aux;
				set<char> ans;
				for (auto c: s2) {
					aux.insert(c);
				}
				set_intersection(light.begin(),light.end(),aux.begin(),aux.end(),
					std::inserter(ans,ans.begin()));
				light = ans;
				aux.clear();
				ans.clear();
				for (auto c: s1) {
					aux.insert(c);
				}
				set_intersection(heavy.begin(),heavy.end(),aux.begin(),aux.end(),
				std::inserter(ans,ans.begin()));
				heavy = ans;
			}
			else if (s3 == "down") {
				set<char> aux;
				set<char> ans;
				for (auto c: s1) {
					aux.insert(c);
				}
				set_intersection(light.begin(),light.end(),aux.begin(),aux.end(),
					std::inserter(ans,ans.begin()));
				light = ans;
				aux.clear();
				ans.clear();
				for (auto c: s2) {
					aux.insert(c);
				}
				set_intersection(heavy.begin(),heavy.end(),aux.begin(),aux.end(),
				std::inserter(ans,ans.begin()));
				heavy = ans;
			}
		}
		for (auto b: v) {
			// cout << b << " ";
		}
		// cout << endl;
		// cout << "light:" << endl;
		for (auto c: light) {
			// cout << c << " ";
			if (v[c-'A']) {
				cout << c << " is the counterfeit coin and it is light." << endl;
			}
		}
		// cout << endl;
		// cout << "heavy:" << endl;
		for (auto c: heavy) {
			// cout << c << " ";
			if (v[c-'A']) {
				cout << c << " is the counterfeit coin and it is heavy." << endl;
			}
		}
		// cout << endl;
	}
	return 0;
}
