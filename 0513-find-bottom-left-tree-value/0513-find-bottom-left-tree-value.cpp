class Solution {
public:  
 int findBottomLeftValue(TreeNode* root) {
     queue<TreeNode*>q; int ans=0;
     q.push(root);
     while(!q.empty())
     {
         int size = q.size();
         for(int i=1; i<=size ;i++)
         {
         TreeNode *front = q.front(); q.pop();
            if(i==1) 
            ans = front->val;
         if(front->left) q.push(front->left);
         if(front->right) q.push(front->right);
         }
     }
     return ans;
    }
};