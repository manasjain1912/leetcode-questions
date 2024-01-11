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
        bool dfs(TreeNode * root, int l,int r,int & res){
        if(!root){
            return true;
        }
        res = max(res,max(abs(root->val-l),abs(root->val-r)));
        dfs(root->left,min(root->val,l),max(root->val,r),res);
        dfs(root->right,min(root->val,l),max(root->val,r),res);
        return true;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        if(!root){
            return ans;
        }
        dfs(root->left,root->val,root->val,ans);
        dfs(root->right,root->val,root->val,ans);
        return ans;
    }  
    
};