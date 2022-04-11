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
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        // Define prev,curr and fwd pointers
        ListNode* prev = dummy;       
        ListNode* curr = head;
        ListNode* fwd = nullptr;
        
        // Prepare the new Head
        ListNode* newHead = curr->next;
        
        while(curr and curr->next) {
            
            // Initialize fwd (we know it will be valid coz we already checked for it in the while above)
            fwd = curr->next;
            
            // Update links
            curr->next = fwd->next;
            fwd->next = curr;
            prev->next = fwd;
            
            // Move by 2 to the right
            prev = curr;
            curr = curr->next;
        }
        
        delete dummy;
        
        return newHead;
        
        
    }
};