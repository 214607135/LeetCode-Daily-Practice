// 49. Group Anagrams

#include <iostream>
#include <unordered_map>
#include <vector>
#include <math.h>

using namespace std;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string> > mp;
		for (auto s : strs) {
			string temp = s;
			sort(temp.begin(), temp.end());
			mp[temp].push_back(s);
		}
		vector<vector<string> > res;
		for (auto key : mp) {
			res.push_back(key.second);
		}
		return res;
	}
};