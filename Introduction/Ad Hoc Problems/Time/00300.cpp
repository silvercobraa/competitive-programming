#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, int> haab = {
	{"pop", 0},
	{"no", 1},
	{"zip", 2},
	{"zotz", 3},
	{"tzec", 4},
	{"xul", 5},
	{"yoxkin", 6},
	{"mol", 7},
	{"chen", 8},
	{"yax", 9},
	{"zac", 10},
	{"ceh", 11},
	{"mac", 12},
	{"kankin", 13},
	{"muan", 14},
	{"pax", 15},
	{"koyab", 16},
	{"cumhu", 17},
	{"uayet", 18},
};

vector<string> tzolkin = {
	"imix",
	"ik",
	"akbal",
	"kan",
	"chicchan",
	"cimi",
	"manik",
	"lamat",
	"muluk",
	"ok",
	"chuen",
	"eb",
	"ben",
	"ix",
	"mem",
	"cib",
	"caban",
	"eznab",
	"canac",
	"ahau",
};

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	cout << n << endl;
	for (size_t i = 0; i < n; i++) {
		int d, y;
		char c;
		string month;
		cin >> d >> c >> month >> y;
		int days = 365*y + 20*haab[month] + d;
		cout << days%13 + 1 << " " << tzolkin[days % 20] << " " << days/(20*13) << endl;
	}
	return 0;
}
