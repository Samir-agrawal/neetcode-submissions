class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        dfs(root, k, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int& k, int& result) {
        if (!node || k <= 0) return;
        dfs(node->left, k, result);
        k--;
        if (k == 0) {
            result = node->val;
            return; 
        }
        dfs(node->right, k, result);
    }
};
