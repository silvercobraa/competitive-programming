#include <iostream>

using namespace std;

void print(int bal) {
	if (bal < 1000) {
		printf("%d", bal);
	}
	else {
		print(bal / 1000);
		printf(",%03d", bal % 1000);
	}

}
int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (int count = 1; count <= n; count++) {
		int sum = 0;
		// cout << count << endl;
		for (int i = 0; i < 12; i++) {
			double tmp;
			// cin >> tmp;
			int a, b;
			scanf("%d.%d", &a, &b);

			// printf("%d.%d\n", a, b);
			tmp = 100*a + b;
			sum += tmp;
			// cout << tmp << " " << 100*tmp << " " << int(100*tmp) << endl;
		}
		// printf("mod: %d\n", sum % 12);
		// printf("sum: %d\n", sum);
		sum = (sum + 6)/12;
		printf("%d $", count);
		print(sum/100);
		if (sum%100 < 10) {
			printf(".%02d\n", sum%100);
		}
		else {
			printf(".%d\n", sum%100);
		}
	}
	return 0;

}
