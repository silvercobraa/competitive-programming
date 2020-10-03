#include <iostream>
#include <vector>

#define MAX 2000000

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		vector<int> v(n);
		vector<int> f(MAX+1, 0);
		vector<int> ans(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			f[v[i]]++;
		}
		for (int i = 1; i <= MAX; i++) {
			f[i] += f[i - 1];
		}
		for (int i = 0; i < n; i++) {
			ans[--f[v[i]]] = v[i];
		}
		cout << ans[0];
		for (int i = 1; i < n; i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}
