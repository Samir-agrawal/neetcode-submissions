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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        queue<pair<TreeNode*,int>> q; // node,depth
        q.push({root,0});
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            TreeNode* node = p.first;
            int depth = p.second;
            if(res.size() == depth) res.push_back(node->val);
            if(node->right) q.push({node->right,depth+1});
            if(node->left) q.push({node->left,depth+1});
        }
        return res;
    }
};
