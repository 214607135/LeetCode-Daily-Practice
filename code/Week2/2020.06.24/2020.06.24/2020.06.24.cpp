/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) {
			return {};
		}
		else if (root->left == NULL && root->right == NULL) {
			return { {root->val} };
		}

		vector<vector<int>> res;
		vector<int>     partialRes;
		int length;
		queue<TreeNode*> treeNodes;
		TreeNode* node = root;
		treeNodes.push(node);
		res.push_back({ root->val });

		while (!treeNodes.empty()) {
			partialRes = {};
			length = treeNodes.size();
			for (int j = 0; j < length; j++) {
				node = treeNodes.front();
				treeNodes.pop();
				if (node->left != NULL) {
					partialRes.push_back(node->left->val);
					treeNodes.push(node->left);
				}
				if (node->right != NULL) {
					partialRes.push_back(node->right->val);
					treeNodes.push(node->right);
				}
			}
			if (!partialRes.empty()) {
				res.push_back(partialRes);
			}
		}
		return res;
	}
};