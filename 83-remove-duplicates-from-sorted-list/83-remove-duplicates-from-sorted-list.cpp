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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head or !head->next) {return head;}
        
        ListNode* curr = head;
        ListNode* diff = curr->next;
        
        while(diff) {
            
            if(curr->val != diff->val) {
                curr->next = diff;
                curr = diff;
            }
                        
            diff = diff->next;
            
        }
        
        // To handle the case where end elements are duplicates
        curr->next = diff;
        
        return head;
        
    }
};