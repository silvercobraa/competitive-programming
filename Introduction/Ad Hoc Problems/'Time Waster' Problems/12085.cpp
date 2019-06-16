#include <iostream>

using namespace std;

void print(int s, int c) {
	if (s == 0) {
		return;
	}
	if (c == 1) {
		cout << "0" << s << endl;
		return;
	}
	int e = s + c - 1;
	int m = 1;
	int count = 1;
	int power = 0;
	for (int i=s, j=e; i!=0 or j!=0; i/=10, j/=10) {
		if (i%10 != j%10) {
			power = count;
		}
		count++;
	}
	for (int i = 0; i < power; i++) {
		m *= 10;
	}
	cout << "0" << s << "-" << e%m << endl;
}

int main(int argc, char const *argv[]) {
	int n;
	int t = 1;
	for (cin >> n; n != 0; cin >> n) {
		int start = 0;
		int count = 1;
		cout << "Case " << t << ":\n";
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == start + count) {
				count++;
			}
			else {
				print(start, count);
				start = x;
				count = 1;
			}
		}
		if (start != 0) {
			print(start, count);
		}
		t++;
		cout << endl;
	}
	return 0;
}
