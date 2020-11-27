// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const* argv[])
{
	int N, K, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		map<char, int> m;
		char key;
		int value;
		for (int j = 0; j < K; j++) {
			cin >> key;
			cin >> value;
			m[key] = value;
		}
		cin >> M;
		int cost = 0;
		string line;
		getline(cin, line);
		for (int k = 0; k < M; k++) {
			getline(cin, line);
			for (auto c: line) {
				auto value = m.find(c);
				if (value != m.end()) {
					cost += m[c];
				}
			}
		}
		printf("%.2lf$\n", cost/100.0);
	}
	return 0;
}
