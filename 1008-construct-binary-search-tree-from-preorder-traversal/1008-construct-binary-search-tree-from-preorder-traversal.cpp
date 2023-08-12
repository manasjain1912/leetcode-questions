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
    TreeNode*solve(int &i,vector<int>&preorder,int bound)
    {
        if(i==preorder.size() || preorder[i]>bound)return NULL;
        TreeNode*node=new TreeNode(preorder[i++]);
        node->left=solve(i,preorder,node->val);
        node->right=solve(i,preorder,bound);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(i,preorder,INT_MAX);
    }
};