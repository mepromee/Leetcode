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
    int maxPathSum(TreeNode* root) {
        helper(root);
        return mxSum;
    }
private:
    int mxSum = INT_MIN;
    int helper(TreeNode *root) {
        if(root == nullptr) return 0;
        int leftRes = helper(root->left);
        int rightRes = helper(root->right);
        
        int mxIncludingThis = max(root->val, max(leftRes + root->val, rightRes + root->val));
        mxSum = max(mxSum,max(mxIncludingThis, leftRes + root->val + rightRes));
        
        return mxIncludingThis;
    }
};
/*
microsoft
amazon
*/