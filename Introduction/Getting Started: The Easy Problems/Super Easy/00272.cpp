#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	char c;
	bool open = true;
	while ((c = getchar()) != EOF) {
		if (c == '"') {
			if (open) {
				printf("``");
			}
			else {
				printf("''");
			}
			open = !open;
		}
		else {
			putchar(c);
		}
	}
	return 0;
}
