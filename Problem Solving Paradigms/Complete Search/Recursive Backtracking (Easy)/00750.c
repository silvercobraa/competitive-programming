#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// map<pair<int, char>, set<string>> result;
map<pair<char, int>, set<string>> result;

void swap(char* a, char* b) {
	char c = *a;
	*a = *b;
	*b = c;
	return;
}

int valid(char v[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(i - j) == abs(v[i] - v[j])) {
				return 0;
			}
		}
	}
	return 1;
}

void perm(char v[], int k, int n) {
	if (k == n) {
		if (valid(v, n)) {
			for (int i = 0; i < n; i++) {
				// result[{i + 1, v[i]}].insert(v);
				result[{v[i], i + 1}].insert(v);
			}
		}
	}
	for (int i = k; i < n; i++) {
		// printf("%d %d\n", i, k);
		swap(&v[k], &v[i]);
		perm(v, k + 1, n);
		swap(&v[k], &v[i]);
	}
}

int main(int argc, char const* argv[])
{
	char arr[] = "12345678";
	perm(arr, 0, 8);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		if (i != 0) {
			cout << endl;
		}
		// int row;
		// char col;
		char row;
		int col;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		// scanf("%d %c", &row, &col);
		// scanf("%c %d", &row, &col);
		cin >> row >> col;
		// printf("%c %d\n", row, col);
		int count = 1;
		for (string s : result[{row, col}]) {
			if (count < 10) {
				cout << ' ';
			}
			cout << count << "     ";
			for (char c : s) {
				cout << ' ' << c;
			}
			cout << endl;
			count++;
		}
	}
	return 0;
}
