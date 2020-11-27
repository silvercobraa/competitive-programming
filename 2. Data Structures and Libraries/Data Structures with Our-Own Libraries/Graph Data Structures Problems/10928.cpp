#include <iostream>
#include <vector>
#include <string>
#include <sstream>

constexpr int INF = 99999999;

using namespace std;

int main(int argc, char const *argv[]) {
	int N;
	cin >> N;
	for (size_t n = 0; n < N; n++) {
		int P;
		cin >> P;
		vector<vector<int>> graph(P);
		string line;
		getline(cin, line);
		for (size_t i = 0; i < P; i++) {
			getline(cin, line);
			stringstream ss(line);
			int j;
			while (ss >> j) {
				graph[i].push_back(j-1);
			}
		}
		int minimum = INF;
		for (size_t i = 0; i < P; i++) {
			minimum = min(minimum, int(graph[i].size()));
		}
		bool first = true;
		for (size_t i = 0; i < P; i++) {
			if (graph[i].size() == minimum) {
				if (first) {
					first = false;
				}
				else {
					cout << " ";
				}
				cout << i+1;
			}
		}
		cout << endl;
	}
	return 0;
}
