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
    void preOrder(unordered_map<int, int> &res, TreeNode *root, int &count){

        if(root == NULL) return;

        res[root->val] ++; //Add current value to map

        preOrder(res, root->left, count);

        

        if(root->left == NULL && root->right == NULL){

			//check if the map element can be arranged as palindrome

            int oddCount = 0;

            for(auto x: res){

                if(x.second % 2 !=0)oddCount ++;

            }

            if(oddCount <2) count ++;

        }

        preOrder(res, root->right, count);

        res[root->val] --; //Remove  leaf value from map

        return;

        

    }

public:

    int pseudoPalindromicPaths (TreeNode* root) {

        unordered_map<int, int> mp;

        int count = 0;

        preOrder(mp, root, count);

        return count;

    }

};