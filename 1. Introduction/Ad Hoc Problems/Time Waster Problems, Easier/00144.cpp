#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, k;
	for (cin >> n >> k; n != 0 or k != 0; cin >> n >> k) {
		vector<int> money(n, 0);
		int done = 0;
		int surplus = 0;
		for (int student=0, count=0; done < n; student=(student+1)%n) {
			if (money[student] >= 40) {
				continue;
			}
			if (surplus == 0) {
				money[student] += count+1;
				// printf("%d recibe %d (%d)\n", student+1, count+1, money[student]);
				count = (count + 1)%k;
				// count = (count + 1)%k;
			}
			else {
				// money[student] += surplus+k+1;
				money[student] += surplus;
				// printf("%d recibe %d (%d)\n", student+1, surplus, money[student]);
				// count = (count + 1)%k;
			}
			if (money[student] >= 40) {
				surplus = money[student] - 40;
				// surplus = 0;
				done++;
				// printf("%d sale\n", student+1);
				printf("%3d", student+1);
			}
			else {
				surplus = 0;
			}
		}
		puts("");
	}
	return 0;
}
