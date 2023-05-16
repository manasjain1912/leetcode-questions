class Solution {
public:
    void swap(ListNode*fast,ListNode*slow)
    {
         ListNode*temp=new ListNode(0);
            temp->val=fast->val;
            fast->val=slow->val;
            slow->val=temp->val;
            delete temp;
    }
    ListNode* swapPairs(ListNode* head) {
         if(!head)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL)
        {
            swap(fast,slow);
            if(fast->next!=NULL)
            {
             fast=fast->next->next;
             slow=slow->next->next;
            }
            else
            break;
        }
        return head; 
    }
};