/*
Description: Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.size() == 1) {
			return nums[0];
		}
		int low = 0;
		int high = nums.size() - 1;
		int index = quicksort(nums, low, high);

		while (true) {
			if (nums.size() - index == k) {
				return nums[index];
			}
			else if (nums.size() - index > k) {
				low = index + 1;
				index = quicksort(nums, low, high);
			}
			else {
				high = index - 1;
				index = quicksort(nums, low, high);
			}
		}
	}
	int quicksort(vector<int>& nums, int low, int high) {
		if (low == high) {
			return high;
		}
		int key = nums[low];
		int i = low;
		int j = high + 1;
		while (true) {
			while (nums[++i] < key) {
				if (i == high) {
					break;
				}
			}
			while (nums[--j] > key) {
				if (j == low) {
					break;
				}
			}
			if (i >= j) {
				break;
			}
			swap(nums[i], nums[j]);
		}
		swap(nums[low], nums[j]);
		return j;
	}
};

