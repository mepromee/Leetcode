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
    vector<int> preorderTraversal(TreeNode* root) {
        preorderTraverse(root);
        return preorder_vec;
    }
private:
    vector<int> preorder_vec;
    void preorderTraverse(TreeNode* root) {
        if(root == nullptr) return;
        preorder_vec.push_back(root->val);
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }
};
/*
9:59
*/