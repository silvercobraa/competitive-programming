#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Trie {
	map<char, Trie> children;
	void add(string& s, int k=0) {
		if (k == s.size()) {
			// cout << s << endl;
			return;
		}
		// cout << "creando hijo " << s[k] << endl;
		children[s[k]].add(s, k+1);
	}
	int count(string& s, int k=0) {
		if (k == s.size()) {
			return children.size();
		}
		return children[s[k]].count(s, k+1);
	}
};

bool prefix(vector<string>& v, Trie trie) {
	for (auto s: v) {
		if (trie.count(s) > 1) {
			return true;
		}
		// NI IDEA PORQUE ITERATIVO NO FUNCIONA
		// Trie t = trie;
		// cout << s << endl;
		// for (char c: s) {
		// 	cout << "nodo: " << c << ", hijos: " << t.children.size() << endl;
		// 	t = t.children[c];
		// }
		// cout << t.children.size() << endl;
		// if (t.children.size() > 1) {
		// 	cout << s << " tiene mas de 2 hijos" << endl;
		// 	return true;
		// }
	}
	return false;
}

void dfs(Trie trie, string& s, int depth=0) {
	cout << "node: " << s << ", children: " << trie.children.size() << ", depth: " << depth << endl;
	for (auto p: trie.children) {
		s.push_back(p.first);
		dfs(p.second, s, depth+1);
		s.pop_back();
	}
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int N;
		cin >> N;
		Trie trie;
		vector<string> v(N);
		for (size_t i = 0; i < N; i++) {
			cin >> v[i];
			string s = v[i] + "$";
			// cout << "insertando " << s << endl;
			trie.add(s);
			// trie.add(v[i]);
		}
		string rvalue = "";
		// dfs(trie, rvalue);
		if (prefix(v, trie)) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
