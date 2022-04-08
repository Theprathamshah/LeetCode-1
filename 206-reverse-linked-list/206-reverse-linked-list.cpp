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
    ListNode* reverseList(ListNode* head) {
        
        if(!head) { return nullptr; }
        if(!head->next) { return head; }
        
        
        ListNode* p = nullptr;    // prev
        ListNode* c = head;       // current
        ListNode* n = c->next; // next
        
        head->next = nullptr;
        
        while(n) {
            
            p = c;
            c = n;            
            n = n->next;
            c->next = p;
        }
        
        return c;
        
    }
};