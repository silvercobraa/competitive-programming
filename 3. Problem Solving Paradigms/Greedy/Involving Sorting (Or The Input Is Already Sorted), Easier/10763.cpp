#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		map<int, int> in_degree;
		map<int, int> out_degree;
		set<int> values;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			out_degree[a]++;
			in_degree[b]++;
			values.insert(a);
			values.insert(b);
		}
		bool flag = true;
		for (auto x: values) {
			if (in_degree[x] != out_degree[x]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
