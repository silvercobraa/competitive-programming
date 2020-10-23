#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> Graph;

int toposorts(Graph& graph, vi& nodes, vi& visited, vi& indegree, vi& solution) {
	if (solution.size() == nodes.size()) {
		for (int i = 0; i < solution.size(); i++) {
			if (i != 0) cout << " ";
			cout << char(solution[i]+'A');
		}
		cout << endl;
		return 1;
	}
	int sorts = 0;
	for (auto parent: nodes) {
		if (not visited[parent] and indegree[parent] == 0) {
			visited[parent] = true;
			solution.push_back(parent);
			for (auto child: graph[parent]) {
				indegree[child]--;
			}
			sorts += toposorts(graph, nodes, visited, indegree, solution);
			for (auto child: graph[parent]) {
				indegree[child]++;
			}
			solution.pop_back();
			visited[parent] = false;
		}
	}
	return sorts;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	string s;
	getline(cin, s);
	for (size_t t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		vector<vector<int>> graph(26);
		vi indegree(26, 0);
		vi visited(26, false);
		vi nodes;
		// no se si es necesario pero como es barato lo hago por si acaso
		sort(nodes.begin(), nodes.end());
		getline(cin, s);
		getline(cin, s);
		stringstream ss(s);
		char c;
		while (ss >> c) {
			nodes.push_back(c - 'A');
		}
		char a, b, dummy;
		while (scanf("%c<%c%c", &a, &b, &dummy)) {
			graph[a-'A'].push_back(b-'A');
			indegree[b-'A']++;
			if (dummy == '\n') break;
		}
		vi solution;
		int sorts = toposorts(graph, nodes, visited, indegree, solution);
		if (sorts == 0) {
			cout << "NO" << endl;
		}
	}
	return 0;
}
