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
    int maxProduct(TreeNode* root) {
        int tot = getTotSum(root);

        helper(root, tot, true);
        return mxProduct%M;
    }
private:
    long long int mxProduct = 0;
    int M = 1e9 + 7;

    int getTotSum(TreeNode* root) {
        if(root == nullptr) return 0;
        return getTotSum(root->left) + getTotSum(root->right) + root->val;
    }

    int helper(TreeNode* root, int& tot, bool isHead) {
        if(root == nullptr) return 0;
        int subtreeSum = helper(root->left, tot, false) + helper(root->right, tot, false) + root->val;
        if(!isHead) {
            long long int res = (tot-subtreeSum) * 1ll * subtreeSum;

            mxProduct = max(mxProduct, res);
        }
        return subtreeSum;
    }
};
/*
amazon
bloomberg
*/