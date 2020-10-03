// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	while (n != 0) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			pq.push(k);
		}
		int cost = 0;
		while (pq.size() >= 2) {
			int min1 = pq.top();
			pq.pop();
			int min2 = pq.top();
			pq.pop();
			int sum = min1 + min2;
			// cout << min1 << ' ' << min2 << ' ' << sum << endl;
			cost += sum;
			pq.push(sum);
		}
		cout << cost << endl;
		cin >> n;
	}
	return 0;
}
