class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    int pairSum(ListNode* head) {
        
        
        ListNode* fast = head->next->next ,*slow = head;
        while(fast){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = reverse(slow->next);
        slow->next = NULL;
        ListNode* t1 = head, *t2 = head2;
        int val = 0;
        while(t1!=NULL){
            val = max(val , t1->val + t2->val);
            t1 = t1->next;
            t2 = t2->next;
        }
        return val;
    }
};