#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	cout << "MAKING THE GRADE OUTPUT" << endl;
	for (int t = 0; t < T; t++) {
		int students, tests;
		cin >> students >> tests;
		// vector<vector<int>> test_grades(students, vector<int>(tests));
		vector<int> bonus(students);
		vector<int> absences(students);
		vector<double> avgs(students);
		vector<char> grades(students);
		double avg = 0.0;
		double std = 0.0;
		for (size_t i = 0; i < students; i++) {
			int min_grade = 101;
			int sum = 0;
			int total_grades = tests;
			for (size_t j = 0; j < tests; j++) {
				int x;
				cin >> x;
				min_grade = min(min_grade, x);
				sum += x;
			}
			if (tests > 2) {
				sum -= min_grade;
				total_grades--;
			}
			avgs[i] = double(sum) / total_grades;
			avg += avgs[i];
			// printf("%lf\n", avgs[i]);
			cin >> bonus[i] >> absences[i];
		}
		avg /= students;
		for (auto x: avgs) {
			std += (x - avg)*(x - avg);
		}
		std /= students;
		std = sqrt(std);
		if (std < 1.0) {
			std = 1.0;
		}
		// printf("%lf %lf\n", avg, std);
		// printf("%lf %lf %lf\n", avg-std, avg, avg+std);
		int ans = 0;
		for (int i = 0; i < avgs.size(); i++) {
			double x = avgs[i] + 3*(bonus[i]/2);
			// printf("x %lf\n", x);
			if (x >= avg + std) {
				grades[i] = 'A';
			}
			else if (x >= avg) {
				grades[i] = 'B';
			}
			else if (x >= avg-std) {
				grades[i] = 'C';
			}
			else {
				grades[i] = 'D';
			}
			grades[i] += absences[i]/4;
			if (grades[i] > 'D') {
				grades[i] = 'F';
			}
			if (absences[i] == 0 and grades[i] != 'A') {
				grades[i]--;
				if (grades[i] == 'E') {
					grades[i] = 'D';
				}
			}
			// cout << grades[i] << endl;
			if ('A' <= grades[i] and grades[i] <= 'D') {
				ans += 4 - (grades[i] - 'A');
				// cout << ans << endl;
			}
		}
		printf("%.1lf\n", double(ans)/students);
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
