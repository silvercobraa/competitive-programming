// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> T;
int main(int argc, char const* argv[])
{
	priority_queue<T, vector<T>, greater<T>> pq;
	string s;
	cin >> s;
	while (s != "#") {
		int id;
		int period;
		cin >> id;
		cin >> period;
		// cout << s << " " << id << " " << period << endl;
		pq.push(T(period, id, period)); // el tercer argumento es la cantidad original
		cin >> s;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (pq.empty()) {
			break;
		}
		auto p = pq.top();
		int p0 = get<0>(p);
		int p1 = get<1>(p);
		int p2 = get<2>(p);
		cout << p1 << endl;
		pq.pop();
		pq.push(T(p0 + p2, p1, p2));
	}
	return 0;
}
