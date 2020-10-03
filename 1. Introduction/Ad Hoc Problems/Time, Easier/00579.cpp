#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int h, m;
	string s;
	char c;
	for (cin>>h>>c>>s; h != 0 or s != "00"; cin >>h>>c>>s) {
		m = 10*(s[0] - '0') + s[1] - '0';
		// cout << h << " " << m << endl;
		int pm = 2*6*m;
		int ph = 2*30*(h%12) + m;
		// printf("pm: %d ph: %d\n", pm, ph);
		int d1 = ph < pm ? pm - ph : ph - pm;
		int d2 = 2*360 - d1;
		// printf("d1: %d d2: %d\n", d1, d2);
		double ans = d1 < d2 ? d1/2.0 : d2/2.0;
		printf("%.3lf\n", ans);
 	}
	return 0;
}
