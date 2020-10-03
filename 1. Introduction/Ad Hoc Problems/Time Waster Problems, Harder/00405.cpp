#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool match(vector<string>& v1, vector<string>& v2) {
	for (int i = 1; i < 5; i++) {
		if (v1[i] != "*" and v2[i] != "*" and v1[i] != v2[i]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	int N;
	for (int t = 1; cin >> N; t++) {
		map<string, vector<vector<string>>> route;
		for (int i = 0; i < N; i++) {
			string s;
			int M;
			cin >> s >> M;
			for (int j = 0; j < M; j++) {
				vector<string> v(5);
				for (int k = 0; k < 5; k++) {
					cin >> v[k];
				}
				route[s].push_back(v);
			}
		}
		cin >> N;
		printf("Scenario # %d\n", t);
		for (int i = 0; i < N; i++) {
			vector<string> v(5);
			for (int j = 0; j < 5; j++) {
				cin >> v[j];
			}
			set<string> visited;
			string prev_dest = v[0];
			v[0] = "";
			while (true) {
				for (auto vec: route[prev_dest]) {
					if (match(vec, v)) {
						v[0] = vec[0];
						break;
					}
				}
				if (prev_dest == v[0]) {
					// cout << prev_dest << endl;
					printf("%d -- delivered to ", i+1);
					cout << prev_dest << endl;
					break;
				}
				else if (v[0] == "") {
					// cout << "No hay mano" << endl;
					printf("%d -- unable to route at ", i+1);
					cout << prev_dest << endl;
					break;
				}
				else {
					if (visited.find(prev_dest) != visited.end()) {
						printf("%d -- circular routing detected by ", i+1);
						cout << prev_dest << endl;
						break;
					}
					visited.insert(prev_dest);
					prev_dest = v[0];
					v[0] = "";
				}
			}

		}
		cout << endl;
	}
	return 0;
}
