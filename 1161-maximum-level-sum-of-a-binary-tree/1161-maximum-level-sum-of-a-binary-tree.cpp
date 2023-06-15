class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int res;
        int ans=-1e9;
        int level=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n= q.size();
            level++;
            long currsum=0;
            for(int i=0; i<n; i++){
                TreeNode* temp= q.front();
                q.pop();
                currsum+= temp->val;
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }   
            }
             if(currsum>ans){
                    res=level;
                    ans= currsum;
                    
            }
        }
        return res;
    }
};