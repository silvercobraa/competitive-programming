#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
	int n;
	int count = 0;
	for (cin >> n; n != 0; cin >> n, count++) {
		if (count != 0) {
			cout << endl;
		}
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i1 = 0; i1 < n - 5; i1++) {
			for (int i2 = i1 + 1; i2 < n - 4; i2++) {
				for (int i3 = i2 + 1; i3 < n - 3; i3++) {
					for (int i4 = i3 + 1; i4 < n - 2; i4++) {
						for (int i5 = i4 + 1; i5 < n - 1; i5++) {
							for (int i6 = i5 + 1; i6 < n - 0; i6++) {
								cout << v[i1] << ' ';
								cout << v[i2] << ' ';
								cout << v[i3] << ' ';
								cout << v[i4] << ' ';
								cout << v[i5] << ' ';
								cout << v[i6] << '\n';
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
