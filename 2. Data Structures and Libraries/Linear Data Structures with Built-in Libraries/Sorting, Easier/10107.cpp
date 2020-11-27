#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	vector<long long> v;
	long long x;
	while (cin >> x) {
		v.push_back(x);
		sort(v.begin(), v.end());
		if (v.size() % 2 == 0) {
			cout << (v[v.size()/2-1] + v[v.size()/2])/2 << endl;
		}
		else {
			cout << v[v.size()/2] << endl;
		}
	}
	return 0;
}
