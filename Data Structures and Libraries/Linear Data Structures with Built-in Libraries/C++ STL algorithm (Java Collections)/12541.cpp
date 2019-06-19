// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Person {
	string name;
	int day;
	int month;
	int year;
};

int compare(Person& p1, Person& p2) {
	if (p1.year != p2.year) {
		return p1.year - p2.year;
	}
	if (p1.month != p2.month) {
		return p1.month - p2.month;
	}
	if (p1.day != p2.day) {
		return p1.day - p2.day;
	}
	return 0;
}


int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	vector<Person> person(n);
	for (int i = 0; i < n; i++) {
		cin >> person[i].name;
		cin >> person[i].day;
		cin >> person[i].month;
		cin >> person[i].year;
	}
	int youngest = 0;
	int oldest = 0;
	for (int i = 0; i < n; i++) {
		// si el segundo es más viejo, la fecha de nacimiento es menor
		if (compare(person[i], person[youngest]) > 0) {
			youngest = i;
		}
		if (compare(person[i], person[oldest]) < 0) {
			oldest = i;
		}
	}
	cout << person[youngest].name << endl;
	cout << person[oldest].name << endl;
	return 0;
}
