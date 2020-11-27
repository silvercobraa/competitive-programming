#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print_answer(vector<int>& v1, vector<int>& v2) {
	// este caso es si no tienen ancestro comun
	// if (v1.empty() or v2.empty() or v1.back() != v2.back()) {
	// 	puts("no relation");
	// 	return;
	// }
	while (not v1.empty() and not v2.empty() and v1.back() == v2.back()) {
		v1.pop_back();
		v2.pop_back();
	}
	if (v1.empty()) {
		for (int i = v2.size(); i >= 2; i--) {
			if (i == 2) cout << "grand ";
			else cout << "great ";
		}
		cout << "parent" << endl;
		return;
	}
	if (v2.empty()) {
		for (int i = v1.size(); i >= 2; i--) {
			if (i == 2) cout << "grand ";
			else cout << "great ";
		}
		cout << "child" << endl;
		return;
	}
	int k = min(v1.size(), v2.size()) - 1;
	int j = abs(int(v2.size()) - int(v1.size()));
	if (j == 0) {
		if (k == 0) {
			cout << "sibling" << endl;
		}
		else {
			cout << k << " cousin" << endl;
		}
	}
	else {
		cout << k << " cousin removed " << j << endl;
	}
	// for (auto x: v1) {
	// 	cout << x << " ";
	// }
	// puts("");
	// for (auto x: v2) {
	// 	cout << x << " ";
	// }
	// puts("");
	// puts("");
}

int main(int argc, char const *argv[]) {
	string s1, s2;
	vector<int> prev;
	unordered_map<string, int> id;

	for (cin >> s1 >> s2; s1 != "no.child"; cin >> s1 >> s2) {
		if (id.find(s1) == id.end()) {
			id[s1] = id.size();
			prev.push_back(prev.size());
		}
		if (id.find(s2) == id.end()) {
			id[s2] = id.size();
			prev.push_back(prev.size());
		}
		int child = id[s1];
		int parent = id[s2];
		prev[child] = parent;
	}
	while (cin >> s1 >> s2) {
		// este caso es si alguno no existe en el arbol
		if (id.find(s1) == id.end() or id.find(s2) == id.end()) {
			puts("no relation");
			continue;
		}
		vector<int> v1;
		vector<int> v2;
		for (int id1 = id[s1]; prev[id1] != id1; id1 = prev[id1]) {
			v1.push_back(id1);
		}
		for (int id2 = id[s2]; prev[id2] != id2; id2 = prev[id2]) {
			v2.push_back(id2);
		}
		print_answer(v1, v2);
	}
	return 0;
}
