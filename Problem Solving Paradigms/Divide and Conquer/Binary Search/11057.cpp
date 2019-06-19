#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find(vector<int>& v, int sum) {
	auto b1 = v.begin();
	auto b2 = v.end();
	int dist = 99999999;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		auto ans = lower_bound(it + 1, v.end(), sum - *it);
		if (ans != v.end() && abs(ans - it) < dist && *ans + *it == sum) {
			b1 = it;
			b2 = ans;
			dist = b2 - b1;
		}
	}
	cout << "Peter should buy books whose prices are " << *b1 << " and " << *b2 << "." << endl << endl;
}

int main(int argc, char const* argv[])
{
	int n = 0;
	while (cin >> n) {
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int M;
		cin >> M;
		find(v, M);
	}
	return 0;
}
