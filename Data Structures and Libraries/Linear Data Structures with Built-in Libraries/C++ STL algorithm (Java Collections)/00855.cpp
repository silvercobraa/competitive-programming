// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<int,int>& p1, pair<int,int>& p2) {
	return p1.second < p2.second;
}

void print_v(vector<pair<int,int>>& v) {
	for (auto p: v) {
		cout << "(" << p.first << "," << p.second << ")";
	}
	cout << endl;
}

int main(int argc, char const* argv[])
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int S, A, F;
		cin >> S;
		cin >> A;
		cin >> F;
		vector<pair<int, int>> pos(F);
		for (int j = 0; j < F; j++) {
			int s, a;
			cin >> s;
			cin >> a;
			pos[j] = pair<int,int>(s, a);
		}
		sort(pos.begin(), pos.end());
		// print_v(pos);
		int s = pos[(pos.size() - 1)/2].first;
		sort(pos.begin(), pos.end(), comp);
		// print_v(pos);
		int a = pos[(pos.size() - 1)/2].second;
		cout << "(Street: " << s << ", Avenue: " << a << ")" << endl;
	}
	return 0;
}
