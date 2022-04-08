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

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
        
//         if(!head) { return nullptr; }
        
//         // removeElements(head -> next) will get me the solution with "val" removed from my children
//         head->next = removeElements(head->next, val);
        
//         // now the decision I have is what I send back my parent..
        
//         // If I have a val.. then I should sent my child.. (and hence I remove myself) else I should send myself..        
//         return head->val == val ? head->next : head;
//  }
// };

// The above solution is technically correct.. however, it takes a lot of stack space due to recursion...9.97%
// how can we improve that.. by doing it iteravetly..

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        
        
        // Let's make a dummy node        
        ListNode* sentinal = new ListNode(-1);
        sentinal->next = head;
        
        ListNode* current = head;        
        ListNode* prev = sentinal;
        ListNode* toDelete = nullptr;
        
        while(current) {            
            if(current->val == val) {
                prev->next = current->next;                
                toDelete = current;
            }
            else {
                prev = prev -> next;
            }
            current = current->next;
            
            if(toDelete != nullptr) {
                delete toDelete;
                toDelete = nullptr;
            }            
        }
        ListNode* newHead = sentinal->next;
        
        delete sentinal;
        
        return newHead;   
    }
};












