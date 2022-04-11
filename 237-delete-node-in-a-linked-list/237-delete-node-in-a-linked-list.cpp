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
        
        while(fwd->next) { // Walk till fwd is the last node
            
            // Copy the value
            curr->val = fwd->val;
            
            // Move by 1 to the right
            curr = fwd;
            fwd = fwd->next;
        }
        
        //copy one last time
        curr->val = fwd->val;
        
        // fwd is the tail and curr points to fwd
        curr->next = nullptr;
        delete fwd;
    }
};