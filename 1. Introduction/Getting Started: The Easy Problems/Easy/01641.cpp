#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
    int h, w;
    int empty = 0;
    int full = 1;
    map<pair<int, char>, pair<int, int>> m {
        {{empty, '.'}, {empty, 0}},
        {{empty, '/'}, {full, 1}},
        {{empty, '\\'}, {full, 1}},
        {{full, '.'}, {full, 2}},
        {{full, '/'}, {empty, 1}},
        {{full, '\\'}, {empty, 1}},
    };

    while (cin >> h >> w) {
        int halfs = 0;
        for (int i = 0; i < h; ++i) {
            string s;
            cin >> s;
            int status = empty;
            for (auto c: s) {
                auto p = m[{status, c}];
                status = p.first;
                halfs += p.second;
            }
        }
        cout << halfs / 2 << endl;
    }
}