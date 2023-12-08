class Solution {
public:
    
        string tree2str(TreeNode* root) {

        if(!root) return "";

        string ans="";

        ans+=to_string(root->val);

        if(root->left || root->right){

            ans+="("+tree2str(root->left)+")";

        }

        if(root->right){

            ans+='('+tree2str(root->right)+")";          

        }

        return ans;

    
    }
};