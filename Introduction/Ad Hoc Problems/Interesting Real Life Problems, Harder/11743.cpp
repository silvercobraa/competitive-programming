#include <iostream>
#include <string>

using namespace std;

int digit_sum(int x) {
	// cout << "x:" << x << endl;
	int ret = 0;
	for ( ; x != 0; x /= 10) {
		ret += x % 10;
	}
	return ret;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int sum_doubles = 0;
		int sum = 0;
		sum_doubles += digit_sum(2*(s[0] - '0'));
		sum_doubles += digit_sum(2*(s[2] - '0'));
		sum_doubles += digit_sum(2*(s[5] - '0'));
		sum_doubles += digit_sum(2*(s[7] - '0'));
		sum_doubles += digit_sum(2*(s[10] - '0'));
		sum_doubles += digit_sum(2*(s[12] - '0'));
		sum_doubles += digit_sum(2*(s[15] - '0'));
		sum_doubles += digit_sum(2*(s[17] - '0'));
		// cout << sum_doubles << endl;
		sum += s[1] - '0';
		sum += s[3] - '0';
		sum += s[6] - '0';
		sum += s[8] - '0';
		sum += s[11] - '0';
		sum += s[13] - '0';
		sum += s[16] - '0';
		sum += s[18] - '0';
		// cout << sum << endl;
		sum += sum_doubles;
		// cout << sum << endl;
		if (sum % 10 == 0) {
			cout << "Valid" << endl;
		}
		else {
			cout << "Invalid" << endl;
		}
	}
	return 0;
}
