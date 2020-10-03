#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	while (cin >> n) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> p;
		bool is_s = true;
		bool is_q = true;
		bool is_p = true;
		for (int i = 0; i < n; i++) {
			int t, x;
			cin >> t >> x;
			if (t == 1) {
				s.push(x);
				q.push(x);
				p.push(x);
			}
			// solo cuando hay elementos podemos borrar, de lo constrario la respuesta es "impossible"
			else if (not s.empty()) {
				is_s &= s.top() == x;
				is_q &= q.front() == x;
				is_p &= p.top() == x;
				s.pop();
				q.pop();
				p.pop();
			}
			else {
				is_s = false;
				is_q = false;
				is_p = false;
			}
		}
		if (is_s and not (is_q or is_p)) {
			puts("stack");
		}
		else if (is_q and not (is_s or is_p)) {
			puts("queue");
		}
		else if (is_p and not (is_s or is_q)) {
			puts("priority queue");
		}
		else if (is_p or is_s or is_q) {
			puts("not sure");
		}
		else {
			puts("impossible");
		}
	}
	return 0;
}
