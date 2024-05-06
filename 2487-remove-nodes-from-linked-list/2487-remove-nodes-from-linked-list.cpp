class Solution {
public:
    void tra(ListNode* h, vector<int> &v)
    {
        while(h)
        {
            v.push_back(h->val);
            h = h->next;
        }
    }
    void nge(vector<int> &v, vector<int> &v1)
    {
        stack<int> s;
        int n = v.size();
        for(int i=0; i<n; i++)
        {
            while(!s.empty() && v[s.top()]<v[i])
            {
                v1[s.top()] = v[i];
                s.pop();
            }
            s.push(i);
        }
    }
    ListNode* removeNodes(ListNode* head) 
    {
        vector<int> v;
        tra(head, v);
        vector<int> v1(v.size(), -1);
        nge(v, v1);
        vector<int> v2;
        for(int i=0; i<v.size(); i++) if(v1[i]==-1) v2.push_back(v[i]);
        
        ListNode* ans=NULL;
        if(v2.size()==0) return ans;
        
        
        ListNode* temp = new ListNode(v2[0]);
        ans = temp;
        for(int i=1; i<v2.size(); i++)
        {
            ListNode* n1 = new ListNode(v2[i]);
            temp->next = n1;
            temp = temp->next;
        }
        
        return ans;
    }
};