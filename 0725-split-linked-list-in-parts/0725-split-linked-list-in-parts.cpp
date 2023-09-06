/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode*head)
    {
        int len=0;
        while(head)
        {
            head=head->next;
            len++;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length=getLength(head);
        int partition=length/k;
        int extra=length%k;
        vector<ListNode*>ans;
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(head)
        {
            int eachpart=partition;
            ans.push_back(curr);
            while(eachpart>0)
            {
                prev=curr;
                curr=curr->next;
                eachpart--;
            }
            if(extra!=0 && curr!=NULL)
            {
                extra--;
                prev=curr;
                curr=curr->next;
                
            }
            if(prev!=NULL)
            {
                head=curr;
                prev->next=NULL;
            }
        }
            while(ans.size()!=k)
            ans.push_back(NULL);
 
        return ans;
    }
};