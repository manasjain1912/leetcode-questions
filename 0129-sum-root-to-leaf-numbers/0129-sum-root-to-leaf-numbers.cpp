class Solution {
public:
    
    int sum = 0;
    
    void f(TreeNode *root, string cur_sum){
        
        if(!root) return;
        
        if(!root->left and !root->right){
            sum+=stoi(cur_sum + to_string(root->val));
            return;
        }
        
        f(root->left, cur_sum + to_string(root->val));
        f(root->right, cur_sum + to_string(root->val));
                
    }
    
    
    int sumNumbers(TreeNode* root) {
        
        f(root, "");
        return sum;
        
    }
};