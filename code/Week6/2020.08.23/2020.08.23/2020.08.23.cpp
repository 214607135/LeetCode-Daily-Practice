// 105. Construct Binary Tree from Preorder and Inorder Traversal

#include <vector>
#include <iostream>

using namespace std;

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0 || inorder.size() == 0) {
			return NULL;
		}
		int i = std::find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

		vector<int> inLeft(inorder.begin(), inorder.begin() + i);
		vector<int> inRight(inorder.begin() + i + 1, inorder.end());
		vector<int> preLeft(preorder.begin() + 1, preorder.begin() + 1 + i);
		vector<int> preRight(preorder.begin() + 1 + i, preorder.end());

		TreeNode* root = new TreeNode(preorder[0]);
		root->left = buildTree(preLeft, inLeft);
		root->right = buildTree(preRight, inRight);

		return root;

	}
};