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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return ans;
    }
private:
    unordered_map<string,int> tripletToId;
    unordered_map<int,int>cnt;
    vector<TreeNode*> ans;
    
    int traverse(TreeNode* cur) {
        if(cur == nullptr) return 0;
        int leftId = traverse(cur->left);
        int rightId = traverse(cur->right);
        
        string triplet = to_string(leftId) + ',' + to_string(cur->val) + ',' + to_string(rightId);
        
        if(!tripletToId.count(triplet)) {
            tripletToId[triplet] = tripletToId.size() + 1;
        }
        
        int curId = tripletToId[triplet];
        cnt[curId]++;
        
        if(cnt[curId] == 2) {
            ans.push_back(cur);
        }
        
        return curId;
    }
};
/*
8:45

9:25
*/