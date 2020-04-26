#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		int dist, length;
		cin >> dist >> length;
		// double a = (length - dist)/2.0 + dist/2.0;
		double a = length/2.0;
		double b = sqrt(length*length - dist*dist)/2.0;
		// cout << M_PI << endl;
		printf("%.3lf\n", a*b*M_PI);
	}
	return 0;
}
