#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct TrieNode {
	int id;
	int parent;
	bool leaf;
	char ch;
	bool s1 = false;
	bool s2 = false;
	int depth = 0;
	map<char, int> children;
	TrieNode(int id=0, int parent=0, char ch='\0', int depth=0, bool leaf=false) {
		this->id = id;
		this->parent = parent;
		this->ch = ch;
		this->leaf = leaf;
		this->depth = depth;
	}
};

class Trie {
private:

public:
	vector<TrieNode> trie = {TrieNode()};
	Trie () {

	}
	void insert(string& word, int start, int id) {
		// cout << "insertando " << word.substr(start, word.size()-start) << endl;
		int node = 0;
		for (int i = start; i < word.size(); i++) {
			char character = word[i];
			if (trie[node].children.find(character) == trie[node].children.end()) {
				TrieNode tnode(trie.size(), node, character, trie[node].depth+1);
				trie[node].children[character] = trie.size();
				node = trie.size();
				trie.push_back(tnode);
			}
			else {
				node = trie[node].children[character];
			}
			if (id == 1) {
				trie[node].s1 = true;
			}
			else if (id == 2) {
				trie[node].s2 = true;
			}
		}
		trie[node].leaf = true;
		// ++trie[node].count;

	}

	void dfs(int node, int best, string& s) {
		if (trie[node].s1 and trie[node].s2 and trie[node].depth == best) {
			// cout << trie[node].depth << " " << s << " " << trie[node].s1 << " " << trie[node].s2 << endl;
			cout << s << endl;
		}
		for (auto child: trie[node].children) {
			s.push_back(child.first);
			dfs(child.second, best, s);
			s.pop_back();
		}
	}
};

int main(int argc, char const *argv[]) {
	string s1, s2;
	for (int case_ = 0; cin >> s1 >> s2; case_++) {
		if (case_ != 0) {
			cout << endl;
		}
		Trie trie;
		for (int i = 0; i < s1.size(); i++) {
			trie.insert(s1, i, 1);
		}
		for (int i = 0; i < s2.size(); i++) {
			trie.insert(s2, i, 2);
		}
		int best = 0;
		for (auto node: trie.trie) {
			if (node.s1 and node.s2 and node.depth > best) {
				best = node.depth;
			}
		}
		if (best == 0) {
			cout << "No common sequence." << endl;
			continue;
		}
		string print = "";
		trie.dfs(0, best, print);
	}
	return 0;
}
