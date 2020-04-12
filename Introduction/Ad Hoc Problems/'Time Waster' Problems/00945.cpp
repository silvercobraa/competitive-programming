#include <iostream>
#include <vector>

constexpr int INF = 99999999;

using namespace std;

int main(int argc, char const *argv[]) {
	int C;
	bool first = true;
	while (cin >> C) {
		if (not first) {
			cout << endl;
		}
		else {
			first = false;
		}
		int total_available = 0;
		vector<int> available(C);
		vector<int> count(C, 0);
		for (size_t i = 0; i < C; i++) {
			cin >> available[i];
			total_available += available[i];
		}
		int P;
		cin >> P;
		vector<vector<int>> containers(C);
		vector<int> weights(P);
		for (int i = 0; i < P; i++) {
			cin >> weights[i];
		}
		int unloaded = 0;
		int total_loaded = 0;
		int max_size = 0;
		for (int i = 0; i < P; i++) {
			int weight = weights[i];
			int lowest = INF;
			vector<int> filtered;
			for (int j = 0; j < C; j++) {
				lowest = min(lowest, count[j]);
			}
			for (int j = 0; j < C; j++) {
				if (count[j] == lowest) {
					filtered.push_back(j);
				}
			}
			int greatest = -1;
			for (int j = 0; j < filtered.size(); j++) {
				int id = filtered[j];
				greatest = max(greatest, available[id]);
			}
			vector<int> filtered2;
			for (int j = 0; j < filtered.size(); j++) {
				int id = filtered[j];
				if (available[id] == greatest) {
					filtered2.push_back(id);
				}
			}
			int id = filtered2[0];
			if (weight <= available[id]) {
				available[id] -= weight;
				count[id]++;
				containers[id].push_back(weight);
				total_loaded += weight;
				max_size = max(max_size, int(containers[id].size()));
			}
			else {
				for (int j = i; j < P; j++) {
					unloaded += weights[j];
				}
				break;
			}
		}
		for (int i = max_size - 1; i >= 0; i--) {
			for (int j = 0; j < containers.size(); j++) {
				if (j != 0) {
					cout << " ";
				}
				if (i < containers[j].size()) {
					cout << containers[j][i];
				}
				else {
					cout << ":";
				}
			}
			cout << endl;
		}
		for (size_t i = 0; i < 2*C-1; i++) {
			cout << "=";
		}
		cout << endl;
		for (size_t i = 0; i < C; i++) {
			if (i != 0) {
				cout << " ";
			}
			cout << i+1;
		}
		cout << endl;
		printf("\ncargo weight: %d\n", total_loaded);
		printf("unused weight: %d\n", total_available - total_loaded);
		printf("unloaded weight: %d\n", unloaded);
	}
	return 0;
}
