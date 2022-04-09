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
        
        unordered_map<ListNode*, bool> table;
        
        ListNode * result = nullptr;
        
        // Traverse list A till the end
        while(headA) {
            table[headA] = true;
            headA = headA -> next;
        }
        
        
        // Now traverse list B. And check for nodes in the table. if something is found then that's the interaction point.
        while(headB) {
            if(table.count(headB)) {
                return headB;
            }
            headB = headB -> next;            
        }
        
        // if we get here, it measn we must have traversed list B also and didn't find any common node    
        return nullptr; 
    }
};