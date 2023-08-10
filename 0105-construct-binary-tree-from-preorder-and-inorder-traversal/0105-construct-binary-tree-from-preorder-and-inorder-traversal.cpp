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
    unordered_map<int,int>mp;
    int index=0;
    TreeNode*solve(int lb,int ub,vector<int>&preorder,vector<int>&inorder)
    {
        if(lb>ub)
        {
            return NULL;
        }
        TreeNode*res=new TreeNode(preorder[index++]);
        if(lb==ub)
        {
            return res;
        }
        int mid=mp[res->val];
        res->left=solve(lb,mid-1,preorder,inorder);
        res->right=solve(mid+1,ub,preorder,inorder);
        return res;
        
            
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        mp.clear();
        int n=preorder.size();
        index=0;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        return solve(0,n-1,preorder,inorder);
    }
};