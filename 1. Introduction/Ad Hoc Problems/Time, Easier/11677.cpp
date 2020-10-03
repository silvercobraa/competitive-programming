#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int h1, m1, h2, m2;
	for (cin>>h1>>m1>>h2>>m2; h1!=0 or m1!=0 or h2!=0 or m2!=0; cin>>h1>>m1>>h2>>m2) {
		if (m2 < m1) {
			m2 += 60;
			h1++;
		}
		if (h2 < h1) {
			h2 += 24;
		}
		int ans = m2 - m1 + 60*(h2 - h1);
		cout << ans << endl;
	}
	return 0;
}
