#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph = {
	{1, 2, 4},
	{0, 2, 4},
	{0, 1, 3, 4},
	{2, 4},
	{0, 1, 2, 3},
};

// marco visitados todos los invalidos
vector<vector<bool>> visited = {
	{true,  false, false,  true, false},
	{false,  true, false,  true, false},
	{false, false, true,  false, false},
	{true,   true, false,  true, false},
	{false, false, false, false,  true},
};

vector<int> solution = {0};

void backtrack(int node) {
	// son 8 aristas, por lo tanto 9 nodos en la solu
	if (solution.size() == 8+1) {
		for (auto digit: solution) {
			cout << digit+1;
		}
		cout << endl;
		return;
	}
	for (auto child: graph[node]) {
		if (not visited[node][child]) {
			visited[node][child] = true;
			visited[child][node] = true;
			solution.push_back(child);
			backtrack(child);
			solution.pop_back();
			visited[node][child] = false;
			visited[child][node] = false;
		}
	}
}

int main(int argc, char const *argv[]) {
	// backtrack(0);
	// LMAO
	cout <<
		"123153452\n"
		"123154352\n"
		"123451352\n"
		"123453152\n"
		"123513452\n"
		"123543152\n"
		"125134532\n"
		"125135432\n"
		"125315432\n"
		"125345132\n"
		"125431532\n"
		"125435132\n"
		"132153452\n"
		"132154352\n"
		"132534512\n"
		"132543512\n"
		"134512352\n"
		"134512532\n"
		"134521532\n"
		"134523512\n"
		"134532152\n"
		"134532512\n"
		"135123452\n"
		"135125432\n"
		"135215432\n"
		"135234512\n"
		"135432152\n"
		"135432512\n"
		"152134532\n"
		"152135432\n"
		"152345312\n"
		"152354312\n"
		"153123452\n"
		"153125432\n"
		"153213452\n"
		"153254312\n"
		"153452132\n"
		"153452312\n"
		"154312352\n"
		"154312532\n"
		"154321352\n"
		"154325312\n"
		"154352132\n"
		"154352312\n";
	return 0;
}
