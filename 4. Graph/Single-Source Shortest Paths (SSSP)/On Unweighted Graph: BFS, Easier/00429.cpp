#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

bool neighbors(string& s1, string& s2) {
	if (s1.size() != s2.size()) {
		return false;
	}
	int count = 0;
	for (int i = 0; i < s1.size(); i++) {
		count += s1[i] != s2[i];
	}
	return count == 1;
}

int bfs(map<string, vector<string>>& graph, string& start, string& goal) {
	queue<pair<int, string>> q;
	map<string, bool> visited;
	q.push({0, start});
	while (not q.empty()) {
		auto top = q.front();
		q.pop();
		if (top.second == goal) {
			return top.first;
		}
		visited[top.second] = true;
		for (auto neigh: graph[top.second]) {
			if (not visited[neigh]) {
				q.push({top.first+1, neigh});
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	string s;
	getline(cin, s);
	getline(cin, s);
	for (int t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		vector<string> v;
		while (getline(cin, s)) {
			if (s == "*") {
				break;
			}
			v.push_back(s);
		}
		map<string, vector<string>> graph;
		for (int i = 0; i < v.size(); i++) {
			for (int j = i+1; j < v.size(); j++) {
				if (neighbors(v[i], v[j])) {
					graph[v[i]].push_back(v[j]);
					graph[v[j]].push_back(v[i]);
				}
			}
		}
		while (getline(cin, s)) {
			if (s == "") {
				break;
			}
			stringstream ss(s);
			string start, goal;
			ss >> start >> goal;
			int ans = bfs(graph, start, goal);
			cout << start << " " << goal << " " << ans << endl;
		}
	}
	return 0;
}
