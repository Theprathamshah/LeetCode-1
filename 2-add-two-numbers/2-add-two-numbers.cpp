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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 and !l2) { return nullptr; }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        int carry = 0;
        while ( l1 or l2 or carry) {
            
            int total = (l1 ? l1->val:0) + (l2 ? l2->val:0) + carry;
            int newVal = total % 10;
            carry = total / 10;
            ListNode* newNode = new ListNode(newVal);
            
            prev->next=newNode;
            prev=prev->next;
            
            l1 = l1 ? l1->next :nullptr;
            l2 = l2 ? l2->next :nullptr;
            
         }
        return dummy->next;
    }
};