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
    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;
        auto res = getMinMax(root, diff);
        return diff;
    }
private:
    pair<int,int> getMinMax(TreeNode* root, int &diff) {
        int mn = INT_MAX, mx = INT_MIN;
        if(root->left != nullptr) {
            pair<int,int> minMaxL = getMinMax(root->left, diff);
            diff = max(diff, max(abs(root->val - minMaxL.first), abs(root->val - minMaxL.second)));
            mn = minMaxL.first;
            mx = minMaxL.second;
        }
        if(root -> right != nullptr) {
            pair<int,int> minMaxR = getMinMax(root->right, diff);
            diff = max(diff, max(abs(root->val - minMaxR.first), abs(root->val - minMaxR.second)));
            mn = min(mn, minMaxR.first);
            mx = max(mx, minMaxR.second);
        }

        return {min(mn,root->val), max(mx, root->val)};
    }
};
/*
amazon
google
fb
*/