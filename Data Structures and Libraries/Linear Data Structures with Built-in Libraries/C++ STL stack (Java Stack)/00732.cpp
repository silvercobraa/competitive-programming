#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string source;
string target;

void backtrack(int source_idx, int target_idx, int i_count, int o_count, stack<char>& stk, vector<char>& solution) {
	// cout << i_count << " " << o_count << endl;
	// cout << source_idx << " " << target_idx <<  " " << source[source_idx] << " " << target[target_idx] << endl;
	if (i_count == source.size() and o_count == source.size()) {
		for (int i = 0; i < solution.size(); i++) {
			if (i != 0) {
				cout << " ";
			}
			cout << solution[i];
		}
		cout << endl;
	}
	if (i_count < source.size()) {
		solution.push_back('i');
		stk.push(source[source_idx]);
		backtrack(source_idx+1, target_idx, i_count+1, o_count, stk, solution);
		stk.pop();
		solution.pop_back();
	}
	if (not stk.empty() and stk.top() == target[target_idx]) {
		solution.push_back('o');
		char cache = stk.top();
		stk.pop();
		backtrack(source_idx, target_idx+1, i_count, o_count+1, stk, solution);
		stk.push(cache);
		solution.pop_back();
	}
}

int main(int argc, char const *argv[]) {
	while (cin >> source >> target) {
		puts("[");
		if (source.size() == target.size()) {
			stack<char> stk;
			vector<char> solu;
			backtrack(0, 0, 0, 0, stk, solu);
		}
		puts("]");
	}
	return 0;
}
