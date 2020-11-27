#include <iostream>
#include <string>

using namespace std;

int leaps(int y) {
	return y/4 - y/100 + y/400;
}

bool isleap(int y) {
	return y%4==0 and (y%100!=0) or y%400==0;
	// return y%4==0 and (not y%100==0) or y%400==0;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string m1, m2, comma;
		int d1, d2, y1, y2;
		cin >> m1 >> d1 >> comma >> y1;
		cin >> m2 >> d2 >> comma >> y2;
		// int ans = leaps(y2) - leaps(y1 - 1);
		int ans = leaps(y2) - leaps(y1);
		// cout << ans << endl;
		if (isleap(y2) and (m2 == "January" or (m2 == "February" and d2 < 29))) {
			ans--;
		}
		// if (isleap(y1) and not (m1 == "January" or (m1 == "February" and d1 <= 29))) {
		if (isleap(y1) and (m1 == "January" or m1 == "February")) {
			// cout << "leap " << y1 << endl;
			ans++;
		}
		printf("Case %d: %d\n", i+1, ans);
	}
	return 0;
}
