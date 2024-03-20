class Solution {

public:

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode *slow = list1, *fast = list1, *temp = list2;

        while(--a){

            slow = slow -> next;

        }

        b += 2;

        while(--b){

            fast = fast -> next;

        }

        while(list2 -> next != nullptr){

            list2 = list2 -> next;

        }

        

        slow -> next = temp;

        list2 -> next = fast;

        return list1;

    }

};
    