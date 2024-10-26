class Solution {
public:
    vector<int> height, depth;
    vector<pair<int,int>> v;
    int calHeight(TreeNode* node) {
      if (!node) return -1; 
      
      int leftHeight = calHeight(node->left);
      int rightHeight = calHeight(node->right);

      int currentHeight = max(leftHeight, rightHeight) + 1;
      height[node->val] = currentHeight; 
      
      return currentHeight;
    }
    
    void calDepth (TreeNode* root, int level = 0) {
      if (root == NULL)
        return;
      
      depth[root->val] = level;
      calDepth(root->left, level + 1);
      calDepth(root->right, level + 1);
      
      return;

    }
    void bfs(TreeNode* root) {

      queue<TreeNode*> q;
      q.push(root);
      
      while (!q.empty()) {
        int sz = q.size();
        int n1 = 0, v1 = 0, n2 = 0, v2 = 0;
        priority_queue<pair<int,int>> pq;
        pq.push({0,0});
        for (int i = 0; i < sz; i++) {
          auto node = q.front();
          q.pop();
          if (node->left)
            q.push(node->left);
          if (node->right)
            q.push(node->right);
          int val = height[node->val] + depth[node->val];
          pq.push({val,node->val});
        }
        pair p1 = pq.top();
        pq.pop();
        pair p2 = pq.top();
        v.push_back({p1.second,p2.second});
      }

    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
      
      ios::sync_with_stdio(false);
      cin.tie(0); cout.tie(0);
      height.resize(1e5 + 1,-1);
      depth.resize(1e5 + 1,-1);
      calHeight(root);
      calDepth(root);
      bfs(root);
      vector<int> res;
      for (int i = 0; i < queries.size(); i++) {

        int l = depth[queries[i]];
        if (v[l].first != queries[i])
          res.push_back(height[v[l].first] + depth[v[l].first]);
        else if (v[l].second == 0)
          res.push_back(depth[v[l - 1].first]);
        else
          res.push_back(height[v[l].second] + depth[v[l].second]);
      }
      return res;
    }
};