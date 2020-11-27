#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
	int b;
	cin >> b;
	for (int r = 1; r <= b; r++) {
		int s;
		cin >> s;
		vector<int> part(s - 1);
		for (int i = 0; i < s - 1; i++)
		{
			cin >> part[i];
			// cout << i << ':' << part[i] << endl;
		}
		int curr_sum = 0;
		int max_sum = 0;
		int begin = 1;
		int end = 2;
		int best_begin = 1;
		int best_end = 2;
		for (int i = 0; i < s - 1; i++)
		{
			curr_sum += part[i];
			if (curr_sum < 0) { // si sumo menos que cero, ignoro todo lo leido anteriormente
				curr_sum = 0;
				begin = i + 2; // no es i + 1, porque ese indice incluiria al ultimo tramo negativo leido
				end = i + 3;
			}
			// cout << "curr_sum: " << curr_sum << ' ' << max_sum << endl;
			if (curr_sum > max_sum) {
				max_sum = curr_sum;
				best_begin = begin;
				end = i + 2;
				best_end = end;				
				// cout << "new: " << begin << ' ' << end << endl;
			}
			else if (curr_sum == max_sum) {
				end = i + 2;
				if (end - begin > best_end - best_begin) {
					best_end = end;
					best_begin = begin;
				}
			}
		}
		if (max_sum == 0) {
			cout << "Route " << r << " has no nice parts" << endl;
		}
		else {
			// cout << "The nicest part of route " << r << " is between stops " << begin << " and " << end << endl;
			cout << "The nicest part of route " << r << " is between stops " << best_begin << " and " << best_end << endl;
			// cout << begin << ' ' << end << endl;
		}
	}
	return 0;
}
