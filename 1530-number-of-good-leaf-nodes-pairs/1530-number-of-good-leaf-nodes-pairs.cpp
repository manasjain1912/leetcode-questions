class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        dfs(root, distance, res);
        return res;
    }
    
    vector<int> dfs(TreeNode* root, int distance, int& res) {
        if (!root->left && !root->right) return {1};
        vector<int> left, right;
        if (root->left) left = dfs(root->left, distance, res);
        if (root->right) right = dfs(root->right, distance, res);
        for (int i = 0; i < left.size(); ++i) {
            for (int j = 0; j < right.size(); ++j) {
                if (left[i] + right[j] <= distance) ++res;
            }
        }
        vector<int> res_vec;
        for (int i = 0; i < left.size(); ++i) {
            if (left[i] + 1 < distance) res_vec.push_back(left[i] + 1);
        }
        for (int i = 0; i < right.size(); ++i) {
            if (right[i] + 1 < distance) res_vec.push_back(right[i] + 1);
        }
        return res_vec;
    }
};
