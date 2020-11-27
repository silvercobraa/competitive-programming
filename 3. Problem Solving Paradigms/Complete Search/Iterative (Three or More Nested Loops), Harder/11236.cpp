// TODO: eliminar falsos positivos
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
	// for (long long i = 1; i <= 2000; i++) {
	for (long long i = 8; i <= 2000; i++) {
		for (long long j = i; j <= 2000 - i; j++) {
			for (long long k = j; k <= 2000 - (i+j); k++) {
				long long l = round((i+j+k)/(i*j*k/1000000.0 - 1));
				double a=i/100.0, b=j/100.0, c=k/100.0, d=l/100.0;
				if (l >= k and i+j+k+l <= 2000 and 1000000*(i+j+k+l) == i*j*k*l) {
					// if (a+b+c+d != a*b*c*d) {
					// 	printf("%.2lf %.2lf %.2lf %.2lf\n", 0.01*i, 0.01*j, 0.01*k, 0.01*l);
					// 	printf("%lf %lf\n", a+b+c+d, a*b*c*d);
					// }
					// cout << 1000000*(i+j+k+l) << " " << i*j*k*l << endl;
					printf("%.2lf %.2lf %.2lf %.2lf\n", 0.01*i, 0.01*j, 0.01*k, 0.01*l);
				}
			}
		}
	}
	return 0;
}
