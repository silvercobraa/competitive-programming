#include <iostream>
#include <map>
#include <vector>

using namespace std;

int round(int tick) {
	if (tick < 30) return 0;
	if (30 <= tick and tick < 90) return 60;
	if (90 <= tick and tick < 150) return 120;
	if (150 <= tick and tick < 210) return 180;
	if (210 <= tick and tick < 270) return 240;
	if (270 <= tick and tick < 330) return 300;
	if (330 <= tick and tick < 390) return 360;
	if (390 <= tick and tick < 450) return 420;
	if (450 <= tick and tick <= 480) return 480;
}

struct Command {
	int code;
	int note;
	int m;
	int b;
	int t;
};

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != -1; cin >> n) {
		vector<Command> v;
		for (int i = 0; i < n; i++) {
			int code, note, m, b, t;
			cin >> code >> note >> m >> b >> t;
			t = round(t);
			if (t == 480) {
				t = 0;
				b += 1;
				if (b == 5) {
					b = 1;
					m += 1;
				}
			}
			Command cmd = {code, note, m, b, t};
			// printf("%d %d %d %d %d\n", cmd.code, cmd.note, cmd.m, cmd.b, cmd.t);

			v.push_back(cmd);
			if (cmd.code == 0) {
				for (int j = int(v.size())-1; j >= 0; j--) {
					int on = 480*(4*v[j].m + v[j].b) + v[j].t;
					int off = 480*(4*cmd.m + cmd.b) + cmd.t;
					if (v[j].code == 1 and v[j].note == cmd.note and off <= on) {
						// printf("on: %d, off: %d\n", on, off);
						// printf("cmd: %d %d %d %d %d\n", cmd.code, cmd.note, cmd.m, cmd.b, cmd.t);
						// printf("v[j]: %d %d %d %d %d\n", v[j].code, v[j].note, v[j].m, v[j].b, v[j].t);
						v.erase (v.begin() + j);
						v.pop_back();
						break;
					}
				}
			}
		}
		cout << v.size() << endl;
		for (auto s: v) {
			printf("%d %d %d %d %d\n", s.code, s.note, s.m, s.b, s.t);
		}
	}
	cout << -1 << endl;
	return 0;
}
