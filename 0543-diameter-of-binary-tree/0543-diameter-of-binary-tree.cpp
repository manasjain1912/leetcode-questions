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
   int solve(TreeNode*root,int &diameter)
    {
        if(root==NULL)
            return 0 ;
        int lh=solve(root->left,diameter);
        int rh=solve(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
         solve(root,diameter);
        
        return diameter;
    }
};