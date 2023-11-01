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
    void inorder(TreeNode* root, vector<int>&temp)
    {
        if(root==NULL)return ;
        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>temp;
            inorder(root,temp);
        unordered_map<int,int>mp;
        for(auto it:temp)
        {
            mp[it]++;
        }
        vector<int>ans;
        int count=0;
        for(auto it:mp)
        {
            if(it.second>count)
            {
                count=it.second;
            }
            
        }
        for(auto it:mp)
        {
            if(it.second==count)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};