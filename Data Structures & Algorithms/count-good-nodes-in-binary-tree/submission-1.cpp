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
    void dfs(int &count,TreeNode* root,int mx)
    {
        if(root == nullptr) return;
        if(root->val >= mx) count++;
        mx = max(mx,root->val);
        dfs(count,root->left,mx);
        dfs(count,root->right,mx);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0, mx = -101;
        dfs(count,root,mx);
        return count;
    }
};
