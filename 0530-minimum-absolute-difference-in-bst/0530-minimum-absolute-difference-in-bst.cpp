class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        int prev = INT_MIN;
        inorder(result, prev, root);
        return result;
    }

private:
    void inorder(int& result, int& prev, TreeNode* root) {
        if (!root) return;
        inorder(result, prev, root->left);
        if (prev != INT_MIN) {
            result = min(result, root->val - prev);
        }
        prev = root->val;
        inorder(result, prev, root->right);
    }
};