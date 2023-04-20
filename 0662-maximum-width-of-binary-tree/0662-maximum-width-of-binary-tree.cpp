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

    int widthOfBinaryTree(TreeNode* root) {

        if (!root) return 0;

        queue<pair<TreeNode*, unsigned int>> q;

        unsigned int mx = 0;

        q.push({root, 1});

        while (q.size()) {

            unsigned int sz = q.size();

            unsigned int left = 0, right = 0;

            for (int i = 0; i < sz; i++) {

                auto node = q.front().first;

                unsigned int nodeNo = q.front().second;

                q.pop();

                if (!left) left = nodeNo;

                right = nodeNo;

                if (node->left) q.push({node->left, nodeNo * 2});

                if (node->right) q.push({node->right, nodeNo * 2 + 1});

            }

            mx = max(mx, right - left + 1);

        }

        return mx;

    }

};

