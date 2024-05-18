class Solution {
public:
    int ans=0;

    void calculateTotalMoves(TreeNode* &root,TreeNode* &parent){
        if(root==NULL){
            return;
        }
 
        calculateTotalMoves(root->left,root);
        calculateTotalMoves(root->right,root);
        int coinsToBeMovedToParent = root->val-1;
        ans+=abs(coinsToBeMovedToParent);
        if(parent!=NULL){
            parent->val+=coinsToBeMovedToParent;
        }
    }

    int distributeCoins(TreeNode* root) {
        TreeNode* parent=NULL;
        calculateTotalMoves(root,parent);
        return ans;
    }
};