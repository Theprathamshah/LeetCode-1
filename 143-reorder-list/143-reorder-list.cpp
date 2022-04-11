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
    
public:
    void reorderList(ListNode* head) {
        
        if(!head or !head->next) {return; }        
        
        ListNode* mid = getMid(head);
        
        ListNode* newHead = mid->next;
        mid->next = nullptr;
        
        newHead = reverse(newHead);
        
        ListNode* headA = head;
        ListNode* headB = newHead;
        ListNode *fwdA, *fwdB;
        
        while(headB) {
            
            // Save fwd
            fwdA = headA->next;
            fwdB = headB->next;
            
            // Update links
            headA->next = headB;
            headB->next = fwdA;
            
            // Move
            headA = fwdA;
            headB = fwdB;            
        }
        return;        
    }
};