// 289. Game of Life

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// no need to pre-declare functions in leetcode.
	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int> > temp = board;
		int n = board.size();
		int m = board[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = updateState(temp, i, j, n, m);
			}
		}
	}

	int updateState(vector<vector<int> > board, int i, int j, int n, int m) {
		int alive = 0;
		alive = alive_dead(board, i, j, n, m);
		if (board[i][j] == 0) {
			if (alive == 3) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			if (alive < 2 || alive > 3) {
				return 0;
			}
			else {
				return 1;
			}
		}
	}

	int alive_dead(vector<vector<int> > board, int i, int j, int n, int m) {
		int alive = 0;
		for (int p = -1; p <= 1; p++) {
			for (int q = -1; q <= 1; q++) {
				if ((i + p >= 0 && i + p < n) && (j + q >= 0 && j + q < m)) {
					if (p == 0 && q == 0) {
						continue;
					}
					if (board[i + p][j + q] == 1) {
						alive++;
					}
				}
			}
		}
		return alive;
	}
};