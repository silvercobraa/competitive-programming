#include <iostream>
#include <vector>

using namespace std;

int get_water_units(const string& s) {
    int water_height = 0;
    int current_heigth = 0;
    int half_units = 0;
    for (auto c: s) {
        if (c == '\\') {
            if (current_heigth < water_height) {
                half_units += 2*(water_height - current_heigth);
                half_units++;
            }
            current_heigth--;
        }
        else if (c == '_') {
            if (current_heigth < water_height) {
                half_units += 2*(water_height - current_heigth);
            }
        }
        else if (c == '/') {
            if (current_heigth < water_height) {
                half_units++;
                current_heigth++;
                half_units += 2*(water_height - current_heigth);
            }
            else {
                water_height++;
            }
        }
    }
    return 0;
}

int simulate(const string& s) {
    vector<int> land(s.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
        int diff = (s[i] == '/') ? 1 : (s[i] == '\\' ? -1 : 0);
        land[i+1] = land[i] + diff;
    }
    vector<int> water {land};
    int maxL = 0;
    int maxR = 0;
    int L = 0;
    int R = 0;
    for (int i = 0; i < land.size(); i++) {
        if (land[i] > maxL) {
            L = i;
            maxL = land[i];
        }
        if (land[i] >= maxR) {
            R = i;
            maxR = land[i];
        }
    }
    for (int i = 1; i < L; i++) {
        water[i] = max(water[i-1], water[i]);
    }
    for (int i = L+1; i < R; i++) {
        water[i] = maxL;
    }
    for (int i = int(water.size()) - 2; i > R; i--) {
        water[i] = max(water[i+1], water[i]);
    }
    int answer = 0;
    for (int i = 0; i < land.size(); i++) {
        answer += water[i] - land[i];
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int answer {simulate(s)};
        cout << answer << endl;
    }
    return 0;
}