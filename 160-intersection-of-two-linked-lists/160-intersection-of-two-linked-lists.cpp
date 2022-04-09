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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // Find length of A and B
        int lenA = 0, lenB = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while(tempA) {
            lenA++;
            tempA = tempA->next;
        }
        while(tempB) {
            lenB++;
            tempB = tempB->next;
        }
        
        // Goal is to advance the pointer of the longer list such that both pointers start at the same distance from the end. whenever the values are the same, it means that's the intersection point
        
        int delta = abs(lenA-lenB);
        if (lenA > lenB) {
            while(delta--) {                
                headA = headA->next;
            }
        }
        else {
            while(delta--) {                
                headB = headB->next;
            }            
        }
        
        // now head A and head B are the same distance from the end
        while(headA and headB) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        // If we get here means no intersection
        return nullptr;
    }
};