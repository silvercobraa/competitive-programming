#include <iostream>
#include <vector>
#include <set>

std::vector<int> left = {
                 0, // placeholder para indexar desde 1
             0,  1,  2,
             0,  4,  5,
     0,  7,  8,  9, 10, 11, 12,
     0, 14, 15, 16, 17, 18, 19,
     0, 21, 22, 23, 24, 25, 26,
	         0, 28, 29,
			 0, 31, 32,
};

std::vector<int> right = {
                 0, // placeholder para indexar desde 1
              2, 3, 0,
              5, 6, 0,
     8,  9, 10, 11, 12, 13, 0,
    15, 16, 17, 18, 19, 20, 0,
    22, 23, 24, 25, 26, 27, 0,
	        29, 30, 0,
			32, 33, 0,
};

std::vector<int> up = {
                 0, // placeholder para indexar desde 1
              0, 0, 0,
              1, 2, 3,
     0,  0,  4,  5,  6,  0,  0,
     7,  8,  9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20,
            23, 24, 25,
            28, 29, 30,
};

std::vector<int> down = {
                 0, // placeholder para indexar desde 1
             4,  5,  6,
             9, 10, 11,
    14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27,
     0,  0, 28, 29, 30,  0,  0,
            31, 32, 33,
             0,  0,  0,
};


int main(int argc, char const *argv[]) {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> dir = {
        down, right, left, up,
	};
    std::vector<std::string> dir_name = {"down", "right", "left", "up"};
    std::cout << "HI Q OUTPUT" << std::endl;
	for (size_t i = 0; i < n; i++) {
		std::set<int> pegs;
		std::vector<bool> board(33 + 1, false);
        board[0] = true; // el cero lo marco ocupado para que no se pueda mover ahi
		int x;
		for (std::cin >> x; x != 0; std::cin >> x) {
			pegs.insert(x);
			// std::cout << x << " ";
			board[x] = true;
		}
		// std::cout << std::endl;
        while (true) {
            int best_dir = -1;
            int best_val = 0;
            for (auto peg: pegs) {
                for (int d = 0; d < 4; d++) {
                    int next = dir[d][peg];
                    int nextnext = dir[d][next];
                    // if (board[next] and not board[nextnext]) {
                    if (board[next] and not board[nextnext] and nextnext > best_val) {
                        // std::cout << peg << " " << dir_name[d] << std::endl;
                        best_val = peg;
                        best_dir = d;
                    }
                }
            }
            // std::cout << "best_dir: " << best_dir << ", best_val: " << best_val << std::endl;
            if (best_val != 0 and best_dir != -1) {
                int next = dir[best_dir][best_val];
                int nextnext = dir[best_dir][next];
                board[best_val] = false;
                board[next] = false;
                board[nextnext] = true;
                pegs.erase(best_val);
                pegs.erase(next);
                pegs.insert(nextnext);
            }
            else {
                break;
            }
        }
        int sum = 0;
        for (auto peg: pegs) {
            sum += peg;
        }
        std::cout << sum << std::endl;
	}
    std::cout << "END OF OUTPUT" << std::endl;
	return 0;
}
