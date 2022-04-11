/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* curr = node; 
        ListNode* fwd = node; // It is given that the node can't be the last, so we can safely assume node->next is not NULL
        ListNode* prev = nullptr; 
        
        while(fwd) { 
            
            // Copy the value
            curr->val = fwd->val;
            
            // Move by 1 to the right
            prev = curr;
            curr = fwd;
            fwd = fwd->next;            
        }
        
        prev->next = nullptr;
        delete curr;
    }
};