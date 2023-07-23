class Solution

{

    public:

        void f(int n, vector<TreeNode*> &ans, unordered_map<int, vector< TreeNode*>> &dp)

        {

            if (dp.find(n) != dp.end())

            {

                ans = dp[n];

                return;

            }

            if (n == 1)

            {

                ans.push_back(new TreeNode());

                dp[n] = ans;

                return;

            }

            for (int i = 0; i < n; i++)

            {

                int l = i, r = n - i - 1;

                vector<TreeNode*> left, right;

                f(l, left, dp);

                f(r, right, dp);

                for (int i = 0; i < left.size(); i++)

                {

                    for (int j = 0; j < right.size(); j++)

                    {

                        ans.push_back(new TreeNode(0, left[i], right[j]));

                    }

                }

            }

            dp[n] = ans;

        }

    vector<TreeNode*> allPossibleFBT(int n)

    {

        unordered_map<int, vector<TreeNode*>> dp;

        vector<TreeNode*> ans;

        f(n, ans, dp);

        return ans;

    }

};