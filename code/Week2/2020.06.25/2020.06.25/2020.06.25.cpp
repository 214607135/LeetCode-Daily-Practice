class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int low = matrix[0][0];
		int hi = matrix[n - 1][n - 1];
		int mid;
		int nums = 0;

		while (low < hi) {
			mid = (low + hi) / 2;
			int pos = 0;
			nums = 0;
			for (int i = 0; i < n; i++) {
				pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				nums += pos;
			}
			if (nums < k) {
				low = mid + 1;
			}
			else {
				hi = mid;
			}
		}
		return hi;
	}
};