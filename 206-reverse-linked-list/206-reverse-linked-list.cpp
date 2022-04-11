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
        
        ListNode* prev = nullptr;    
        ListNode* frwd = nullptr;    
        ListNode* curr = head;       
        
        while(curr) {            
            // Save the next step before switching over the link            
            frwd = curr->next;
            
            // SWtich the link!
            curr->next = prev;
            
            // Move prev and curr by 1 to the left
            prev = curr;
            curr = frwd;            
        }
        
        return prev;
        
    }
};