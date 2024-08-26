/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
       if(!root)
            return {};
        vector<int> ans;
        stack<pair<Node*,bool>> st;
        st.push({root,false});
        while(!st.empty()){
            auto curr=st.top();
            st.pop();
            root=curr.first;bool flag=curr.second;
            if(!flag){
                st.push({root,true});
                for(auto it=root->children.rbegin();it!=root->children.rend();++it)
                    st.push({*it,false});
            }
            else
                ans.push_back(root->val);
        }
        return ans; 
    }
};