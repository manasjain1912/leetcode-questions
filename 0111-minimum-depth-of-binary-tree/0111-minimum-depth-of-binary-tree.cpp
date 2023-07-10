class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)  return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if(root->left == NULL)
        {
            return 1 + rightDepth;
        }
        if(root->right == NULL)
        {
            return 1 + leftDepth;
        }
        return min(leftDepth, rightDepth) + 1;  
    }
};