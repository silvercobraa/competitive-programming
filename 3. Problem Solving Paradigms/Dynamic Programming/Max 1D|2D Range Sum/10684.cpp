#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
	int n;
	for (cin >> n; n!= 0; cin >> n) {
		vector<int> gain(n);
		for (int j = 0; j < n; j++)
		{
			cin >> gain[j];
			// cout << gain[j] << endl;
		}
		int curr_sum = 0;
		int max_sum = 0;
		for (int j = 0; j < n; j++)
		{
			curr_sum += gain[j];
			// cout << curr_sum << ' ' << max_sum << endl;
			max_sum = max(curr_sum, max_sum);
			curr_sum = max(curr_sum, 0); // si sumo menos que cero, ignoro todo lo leido anteriormente
		}
		if (max_sum == 0) {
			cout << "Losing streak." << endl;
		}
		else {
			cout << "The maximum winning streak is " << max_sum << '.' << endl;
		}
	}
	return 0;
}
