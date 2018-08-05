#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		int l = s.size();
		if (s == "1" or s == "4" or s == "78") {
			puts("+");
		}
		else if (l >= 2 and s[l - 2] == '3' and s[l - 1] == '5') {
			puts("-");
		}
		else if (l >= 2 and s[0] == '9' and s[l - 1] == '4') {
			puts("*");
		}
		else if (l >= 3 and s[0] == '1' and s[1] == '9' and s[2] == '0') {
			puts("?");
		}
		else {
			puts("?");
		}
	}
	return 0;
}
