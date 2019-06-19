// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

void print_queues(vector<deque<int>>& v)
{
	for (int i = 0; i < v.size(); i++) {
		cout << 'q' << i << ':';
		for (auto it2 = v[i].begin(); it2 != v[i].end(); it2++) {
			cout << ' ' << *it2;
		}
		cout << endl;
	}
	cout << "---------" << endl;
}

bool all_empty(vector<deque<int>>& v)
{
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].empty()) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const* argv[])
{
	int SET;
	cin >> SET;
	for (int i = 0; i < SET; i++) {
		int N, S, Q;
		int minutes = 0;
		cin >> N;
		cin >> S;
		cin >> Q;
		vector<deque<int>> q(N);
		// cout << "SET " << i << endl;
		for (int j = 0; j < N; j++) {
			int Qi;
			int cargo;
			cin >> Qi;
			for (int k = 0; k < Qi; k++) {
				cin >> cargo;
				q[j].push_back(cargo - 1);
				// print_queues(q);
			}

		}
		int station = 0;
		stack<int> carrier;
		do {
			// cout << "estación " << station << ':' << endl;
			// cout << "descargando..." << endl;
			// descargar
			while (carrier.size() != 0) {
				if (carrier.top() == station) {
					carrier.pop();
					minutes++;
				}
				else if (q[station].size() < Q) {
					q[station].push_back(carrier.top());
					carrier.pop();
					minutes++;
				}
				else {
					break;
				}
			}
			// print_queues(q);
			// cout << "cargando..." << endl;
			// cargar
			while (carrier.size() < S) {
				if (q[station].size() > 0) {
					carrier.push(q[station].front());
					q[station].pop_front();
					minutes++;
				}
				else {
					break;
				}
			}
			// print_queues(q);
			station = (station + 1) % N;
			if (carrier.size() == 0 && all_empty(q)) {
				break;
			}
			minutes += 2;

		} while (true);
		// cout << "MINUTES: " << minutes << endl;
		cout << minutes << endl;
	}
	return 0;
}
