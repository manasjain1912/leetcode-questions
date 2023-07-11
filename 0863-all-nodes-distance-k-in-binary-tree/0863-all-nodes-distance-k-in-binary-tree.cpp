class Solution {
public:
    vector<int> ans;
    void addneigbour(TreeNode* root, int k)
    {
        if(root==NULL || k<0) return;

        if(k==0)
        ans.push_back(root->val);

        addneigbour(root->left,k-1);
        addneigbour(root->right,k-1);
        return;
    }
    int solve(TreeNode* root, int target, int k)
    {
        if(root==NULL) return -1;
        if(root->val == target){
            addneigbour(root,k);
            return k-1;
        }
        int dist = solve(root->left,target,k);
        if(dist>-1)
        { 
            if(dist==0)
            ans.push_back(root->val);
            else{
            addneigbour(root->right,dist-1);
            return dist-1;
            }
        }
        dist = solve(root->right,target,k);
        if(dist>-1)
        {
            if(dist==0)
            {
                ans.push_back(root->val);
            }else{
            addneigbour(root->left,dist-1);
            return dist-1;
            }
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         if(root==NULL)
         return ans;

         int tar = target->val;

         solve(root,tar,k);
         return ans;
    }
};