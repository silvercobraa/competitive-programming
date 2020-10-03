#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fenwick Tree
vector<int> a;
void add(int n, int x) {for ( ; n < a.size(); n |= n + 1) a[n] += x; }
int sum(int n) {int s = 0; while (n >= 0) { s+= a[n]; n=(n&(n+1))-1;} return s;}
int query(int l, int r) {return sum(r) - (l == 0? 0 : sum(l - 1));} // inclusivo ambos

int main(int argc, char const *argv[]) {
	int n;
	int count = 0;
	for (cin >> n; n != 0; cin >> n) {
		if (count != 0) {
			cout << endl;
		}
		a = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			add(i, x);
		}
		string s;
		cout << "Case " << count+1 << ":" << endl;
		for (cin >> s; s != "END"; cin >> s) {
			int a, b;
			cin >> a >> b;
			if (s == "S") {
				a--;
				int val = query(a, a);
				add(a, b - val);
			}
			else if (s == "M") {
				a--; b--;
				cout << query(a, b) << endl;
			}
		}
		count++;
	}
	return 0;
}
