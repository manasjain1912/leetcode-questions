
class Solution {
public:
    ListNode* addTwoNum(ListNode* l1, ListNode* l2) {
        ListNode*dummy=new ListNode();
        ListNode*temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode*node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
     ListNode* reverseList(ListNode* head) {
    ListNode*newHead=NULL;
        while(head!=NULL)
        {
            ListNode*next=head->next;
            head->next=newHead;
            newHead=head;
            head=next;
            
        }
        return newHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            l1=reverseList(l1);
            l2=reverseList(l2);
            ListNode*ans=addTwoNum(l1,l2);
            ans=reverseList(ans);
            return ans;
    }
};