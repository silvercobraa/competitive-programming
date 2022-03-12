#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int p, h, o;
	while (cin >> p >> h >> o) {
		if (p > o) {
			puts("Hunters win!");
		}
		else {
			int diff = o - p;
			if (h > diff) {
				puts("Hunters win!");
			}
			else {
				puts("Props win!");
			}
		}
	}
	return 0;
}
