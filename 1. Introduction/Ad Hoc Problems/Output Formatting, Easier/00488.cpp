// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>

using namespace std;

void print_wave_form(int A)
{
	for (int i = 1; i <= A; i++) {
		for (int j = 0; j < i; j++) {
			cout << i;
		}
		cout << endl;
	}
	for (int i = A - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			cout << i;
		}
		cout << endl;
	}
}

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	string blank;
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << endl;
		}
		getline(cin, blank);
		int A;
		int F;
		cin >> A;
		cin >> F;
		// cout << A << " " << F << endl;
		for (int j = 0; j < F; j++) {
			if (j > 0) {
				cout << endl;
			}
			print_wave_form(A);
		}
	}
	return 0;
}
