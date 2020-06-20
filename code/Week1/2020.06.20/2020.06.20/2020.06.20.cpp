/*
Description: Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.size() > 1) {
			int slow = nums[0];
			int fast = nums[slow];

			while (slow != fast) {
				slow = nums[slow];
				fast = nums[nums[fast]];
			}

			fast = 0;
			while (slow != fast) {
				slow = nums[slow];
				fast = nums[fast];
			}
			return fast;
		}
		return -1;
	}
};