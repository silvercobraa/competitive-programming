// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Individual
{
	string title;
	string first_name;
	string last_name;
	string address;
	string home_phone;
	string work_phone;
	string mailbox;
	int department;
	bool operator < (const Individual& ind) const
	{
		return (last_name < ind.last_name);
	}
};

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	string l;
	vector<string> departments;
	vector<Individual> individuals;
	getline(cin, l);
	for (int i = 0; i < n; i++) {
		string department;
		getline(cin, department);
		departments.push_back(department);
		while (true) {
			getline(cin, l);
			if (l == "") {
				break;
			}
			stringstream ss(l);
			Individual ind;
			ind.department = i;
			getline(ss, ind.title, ',');
			getline(ss, ind.first_name, ',');
			getline(ss, ind.last_name, ',');
			getline(ss, ind.address, ',');
			getline(ss, ind.home_phone, ',');
			getline(ss, ind.work_phone, ',');
			getline(ss, ind.mailbox, ',');
			individuals.push_back(ind);
		}
	}
	sort(individuals.begin(), individuals.end());
	for (auto i : individuals) {
		cout << "----------------------------------------" << endl;
		cout << i.title << ' ' << i.first_name << ' ' << i.last_name << endl;
		cout << i.address << endl;
		cout << "Department: " << departments[i.department] << endl;
		cout << "Home Phone: " << i.home_phone << endl;
		cout << "Work Phone: " << i.work_phone << endl;
		cout << "Campus Box: " << i.mailbox << endl;
	}
	return 0;
}
