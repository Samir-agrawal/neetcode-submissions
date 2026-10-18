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
    int calculateHeight(TreeNode* root,int &maxDiameter)
    {
        if(root==nullptr) return 0;
        int lh = calculateHeight(root->left,maxDiameter);
        int rh = calculateHeight(root->right,maxDiameter);
        maxDiameter = max(maxDiameter,lh+rh);
        return 1 + max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxDiameter = 0;
        calculateHeight(root,maxDiameter);
        return maxDiameter;
    }
};
