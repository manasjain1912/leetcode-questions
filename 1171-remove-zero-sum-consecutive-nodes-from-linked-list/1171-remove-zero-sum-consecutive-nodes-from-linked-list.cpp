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
    ListNode* removeZeroSumSublists(ListNode* head) {
           unordered_map<int,ListNode*>mp;
        int sum=0;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        head=dummy;
        while(head){
             sum+=head->val;
             mp[sum]=head;
             head=head->next;
        }
        head=dummy;
        sum=0;
        while(head){
             sum+=head->val;
            head->next=mp[sum]->next;
             head=head->next;
        }
        return dummy->next;
    }
};