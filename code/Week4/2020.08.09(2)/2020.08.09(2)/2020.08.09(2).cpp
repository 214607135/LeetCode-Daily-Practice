// 454. 4Sum II

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> abSum;
		int res = 0;

		for (int a : A) {
			for (int b : B) {
				abSum[a + b]++;
			}
		}

		for (int c : C) {
			for (int d : D) {
				res += abSum[-c - d];
			}
		}
		return res;
	}
};