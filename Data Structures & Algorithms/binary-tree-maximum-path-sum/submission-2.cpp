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
    int maxPath = INT_MIN;
    int getMaxPathSum(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int lmax = max(getMaxPathSum(root->left),0);
        int rmax = max(getMaxPathSum(root->right),0);
        int currPathSum = lmax + rmax + root->val;
        maxPath = max(maxPath,currPathSum);
        return max(lmax,rmax)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        getMaxPathSum(root);
        return maxPath;
    }
};
