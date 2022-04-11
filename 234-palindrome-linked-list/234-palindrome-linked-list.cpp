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
private:
    ListNode* getMid(ListNode* head) { // for a linked list of even size, return the 1st mid element        
        if(!head or !head->next) {return head; }        
        ListNode* fast = head;
        ListNode* slow = head;        
        while(fast->next and fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head) {
        if(!head or !head->next) {return head; }        
     
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* fwd = nullptr;
        
        while(curr) {
            fwd = curr->next;            
            curr->next = prev;            
            prev = curr;
            curr = fwd;            
        }
        return prev;
    }
    
    bool helper(ListNode* headA, ListNode* headB) {
        
        while(headB) {
            if (headA->val != headB->val) { return false; }
            headA = headA->next;
            headB = headB->next;
        }
        return true;
    }
    
    
    
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* mid = getMid(head);        
        
        ListNode* mid_next = mid->next;  
        mid->next = nullptr;
        
        ListNode* tail = reverse(mid_next);
        
        bool answer = helper(head, tail);
        
        ListNode* mid_next_recovered = reverse(tail);
        mid->next = mid_next_recovered;
        
        return answer;
        
    }
};