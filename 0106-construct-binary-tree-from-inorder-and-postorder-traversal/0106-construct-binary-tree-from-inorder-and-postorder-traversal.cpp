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
    unordered_map<int, int> mp;
    int index;
    
    TreeNode* solve(int lb, int ub, vector<int>& inorder, vector<int>& postorder) {
        if (lb > ub) {
            return nullptr;
        }
        
        TreeNode* res = new TreeNode(postorder[index--]);
        
        if (lb == ub) {
            return res;
        }
        
        int mid = mp[res->val];
        res->right = solve(mid + 1, ub, inorder, postorder);
        res->left = solve(lb, mid - 1, inorder, postorder);
        
        return res;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        index = n - 1;
        
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        return solve(0, n - 1, inorder, postorder);
    }
};
