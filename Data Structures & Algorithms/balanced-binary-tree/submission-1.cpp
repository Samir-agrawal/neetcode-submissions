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
private:
    int getHeight(TreeNode* root)
    {
        if(root==nullptr) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if(lh == -1 || rh == -1 || abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(getHeight(root)==-1) return false;
        return true;
    }
};
