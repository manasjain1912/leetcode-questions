class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head== NULL) return NULL;
        ListNode* res= new ListNode(0,head);
        ListNode* prev= res;
        for(int i=0; i<left-1; i++) prev= prev->next; 
        ListNode* curr= prev->next;
        while(left++ < right){
            ListNode* temp= curr->next;
            curr->next= temp->next;
            temp->next= prev->next;
            prev->next= temp;
        }
        return res->next;
    }
};