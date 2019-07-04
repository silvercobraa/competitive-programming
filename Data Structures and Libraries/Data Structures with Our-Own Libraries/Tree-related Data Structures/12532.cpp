#include <iostream>
#include <vector>

using namespace std;

struct sign {
	int val = 1; // el neutro de la mutiplicación es 1
	sign () {

	}
	sign(int x) {
		val = (x > 0) - (x < 0);
	}
	sign(const sign& x, const sign& y) {
		val = x.val * y.val;
	}
};

template<class node> class ST {
	vector<node> t;
	int n;
public:
	ST(vector<node> &arr) {
		n = arr.size();
		t.resize(n*2);
		copy(arr.begin(), arr.end(), t.begin() + n);
		for (int i = n-1; i > 0; --i)
			t[i] = node(t[i<<1], t[i<<1|1]);
	}
	// 0-indexed
	void set_point(int p, const node &value) {
		for (t[p += n] = value; p > 1; p >>= 1)
		t[p>>1] = node(t[p], t[p^1]);
	}
	// inclusive exclusive, 0-indexed
	node query(int l, int r) {
		node ansl, ansr;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) ansl = node(ansl, t[l++]);
			if (r&1) ansr = node(t[--r], ansr);
		}
		return node(ansl, ansr);
	}
};

int main(int argc, char const *argv[]) {
	int n, k;
	while (cin >> n >> k) {
		vector<sign> v(n);
		for (size_t i = 0; i < n; i++) {
			int x;
			cin >> x;
			v[i] = sign(x);
		}
		ST<sign> st(v);
		for (size_t i = 0; i < k; i++) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			if (c == 'C') {
				st.set_point(a-1, sign(b));
			}
			else if (c == 'P') {
				sign ans = st.query(a-1, b);
				if (ans.val == 0) {
					cout << 0;
				}
				else if (ans.val == 1) {
					cout << '+';
				}
				else if (ans.val == -1) {
					cout << '-';
				}
			}
		}
		cout << endl;
	}
	return 0;
}
