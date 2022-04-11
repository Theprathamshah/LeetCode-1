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
    ListNode* swapPairs(ListNode* head) {
        
        while(!head or !head->next) {return head; }
        
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* curr = head;
        ListNode* fwd = nullptr;
        
        // 
        ListNode* newHead = curr->next;
        
        while(curr and curr->next) {
            
            // Initialize pointers
            fwd = curr->next;
            
            // Update pointers
            curr->next = fwd->next;
            fwd->next = curr;
            prev->next = fwd;
            
            // Move by 2 to the right
            prev = curr;
            curr = curr->next;
        }
        
        
        return newHead;
        
        
    }
};