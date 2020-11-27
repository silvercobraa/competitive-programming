// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool compare(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
	if (get<1>(t1) != get<1>(t2)) {
		return get<1>(t1) > get<1>(t2);
	}
	if (get<2>(t1) != get<2>(t2)) {
		return get<2>(t1) < get<2>(t2);
	}
	return get<0>(t1) < get<0>(t2);
}

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	string l;
	getline(cin, l);
	getline(cin, l);
	for (int i = 0; i < n; i++) {
		int contestant;
		int problem;
		int time_;
		char veredict;
		map<int, set<int>> solved;
		map<int, map<int,int>> penalty;
		set<int> contestants;
		map<int, int> total_penalty;
		vector<tuple<int,int,int>> ranklist;
		while (true) {
			getline(cin, l);
			if (l == "") {
				break;
			}
			stringstream ss(l);
			ss >> contestant;
			ss >> problem;
			ss >> time_;
			ss >> veredict;
			contestants.insert(contestant);
			// cout << veredict << endl;
			if (veredict == 'C') {
				if (solved[contestant].find(problem) == solved[contestant].end()) {
					solved[contestant].insert(problem);
					penalty[contestant][problem] += time_;
					total_penalty[contestant] += penalty[contestant][problem];
				}
			}
			else if (veredict == 'I') {
				if (solved[contestant].find(problem) == solved[contestant].end()) {
					penalty[contestant][problem] += 20;
				}
			}
		}
		// for (auto it = solved.rbegin(); it != solved.rend(); it++) {
		// 	int key = it->first;
		// 	auto value = it->second;
		// 	cout << "key: "<<  key << ' ' << value.size() << endl;
		// 	// for (auto i : value) {
		// 	// 	cout << ' ' << i;
		// 	// }
		// 	// cout << endl;
		// }
		for (auto c: contestants) {
			ranklist.push_back(tuple<int,int,int>(c, solved[c].size(), total_penalty[c]));
		}
		sort(ranklist.begin(), ranklist.end(), compare);
		for (auto t: ranklist) {
			cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
		}
		// UVa culia llorona
		if (i != n - 1) {
			cout << endl;
		}
	}
	return 0;
}
