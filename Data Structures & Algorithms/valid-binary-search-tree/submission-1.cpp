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
    bool isValidBST(TreeNode* root,int mx = 1e9,int mn = -1e9) {
        if(root == nullptr) return true;

        if(root->val >= mx || root->val <= mn) return false;
        int lmax = min(mx,root->val);
        int rmin = max(mn,root->val);
        return isValidBST(root->left,lmax,mn) && isValidBST(root->right,mx,rmin);

    }
};
