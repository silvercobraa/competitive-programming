#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

typedef std::pair<int,int> Point;
typedef std::pair<Point, Point> Segment;

using namespace std;

int dist(pair<int,int> p1, pair<int,int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void get_points(vector<Point>& points, vector<Point>& stops, vector<int>& times) {
	Point start = stops[0];
	int current_time = 0;
	int stop_idx = 0;
	int time_idx = 0;
	for (int time_idx = 0; stop_idx < stops.size(); time_idx++) {
		Point p = stops[stop_idx];
		int d = dist(start, p);
		if (times[time_idx] == current_time + d) {
			points.push_back(p);
			stop_idx++;
			current_time += d;
			start = p;
		}
		else {
			// caso vertical
			int delta = times[time_idx] - current_time;
			if (start.first == p.first) {
				if (start.second < p.second) {
					start = {start.first, start.second+delta};
				}
				else {
					start = {start.first, start.second-delta};
				}
			}
			// caso horizontal
			else {
				if (start.first < p.first) {
					start = {start.first+delta, start.second};
				}
				else {
					start = {start.first-delta, start.second};
				}
			}
			current_time += delta;
			points.push_back(start);
		}
	}
	// for (auto gio: points) {
	// 	cout << gio.first << " " << gio.second << endl;
	// }
	// cout << endl;
}

// Los segmentos son A-B y C-D
Point intersect(Point A, Point B, Point C, Point D) {
	// (ux, uy) es un vector unitario de A hacia B
	// (vx, vy) es un vector unitario de C hacia D
	int ux = B.first > A.first ? 1 : (B.first < A.first ? -1 : 0);
	int uy = B.second > A.second ? 1 : (B.second < A.second ? -1 : 0);
	int vx = D.first > C.first ? 1 : (D.first < C.first ? -1 : 0);
	int vy = D.second > C.second ? 1 : (D.second < C.second ? -1 : 0);
	int term1 = (C.first - A.first) * (uy - vy);
	int term2 = (C.second - A.second) * (ux - vx);
	// if (term1 == term2 and not (ux == vx and uy == vy)) {
	if (term1 == term2) {
		// puts("Posible interseccion");
		// cout << "A:" << A.first << " " << A.second << endl;
		// cout << "B:" << B.first << " " << B.second << endl;
		// cout << "C:" << C.first << " " << C.second << endl;
		// cout << "D:" << D.first << " " << D.second << endl;
		// cout << "ux: " << ux << " vx: " << vx << endl;
		// cout << "uy: " << uy << " vy: " << vy << endl;
		double t1 = (C.first - A.first) / double(ux - vx);
		double t2 = (C.second - A.second) / double(uy - vy);
		// cout << "t: " << t1 << endl;
		// cout << "t: " << t2 << endl;
		// cout << "dist: " << dist(A, B) << endl;
		if (t1 >= 0 and t1 <= dist(A, B)) {
			return {A.first + t1*ux, A.second + t1*uy};
		}
		else if (t2 >= 0 and t2 <= dist(A, B)) {
			return {A.first + t2*ux, A.second + t2*uy};
		}
	}
	return {-1, -1};
}


int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t i = 0; i < T; i++) {
		if (i != 0) {
			puts("");
		}
		vector<Point> tmpg;
		vector<Point> tmpl;
		vector<int> t = {0};
		int a, b;
		cin >> a >> b;
		tmpg.push_back({a, b});
		cin >> a >> b;
		tmpl.push_back({a, b});
		int m;
		cin >> m;
		int count = 0;
		for (size_t i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			int d = dist(tmpl.back(), {x, y});
			count += d;
			t.push_back(count);
			tmpl.push_back({x, y});
		}
		int n;
		cin >> n;
		count = 0;
		for (size_t i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			// cout << x << " " << y << ",  " << tmpg.back().first << " " << tmpg.back().second << endl;

			int d = dist(tmpg.back(), {x, y});
			count += d;
			t.push_back(count);
			tmpg.push_back({x, y});
		}
		sort(t.begin(), t.end());
		t.erase(unique(t.begin(), t.end()), t.end());
		vector<Point> giovanni;
		vector<Point> leporello;
		get_points(giovanni, tmpg, t);
		get_points(leporello, tmpl, t);
		int minimum = min(giovanni.size(), leporello.size());
		bool safe = true;
		for (size_t i = 1; i < minimum; i++) {
			Point inter = intersect(giovanni[i-1], giovanni[i], leporello[i-1], leporello[i]);
			if (inter.first != -1 and inter.second != -1) {
				// cout << "inter: " << inter.first << " " << inter.second << endl;
				// cout << "gio: " << giovanni[i].first << " " << giovanni[i].second << endl;
				// cout << giovanni.size() << " " << leporello.size() << endl;
				if (i + 1 == minimum and leporello.size() == minimum and inter == leporello[i]) {
					// cout << "ACA" << endl;
					continue;
				}
				puts("No");
				safe = false;
				break;
			}
		}
		if (safe) {
			puts("Yes");
		}
		// cout << endl;
		// TODO: intersectar los segmentos que tengan mismo indice en los arreglos construidos
	}
	return 0;
}
