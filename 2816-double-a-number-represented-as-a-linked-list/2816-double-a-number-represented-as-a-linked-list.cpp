class Solution {
public:
    
    ListNode* doubleIt(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != NULL) {
            int doubled_value = (curr->val << 1);
            if (doubled_value >= 10) {
                prev->val++;
                curr->val = doubled_value - 10;
            }
            else {
                curr->val = doubled_value;
            }
            prev = curr;
            curr = curr->next;
        }
        
        if (dummy->val == 0) return head;
        return dummy;
    }
};