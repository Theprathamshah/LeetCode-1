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
        
        while(headA and headB and !result) {
            if(table.count(headA))
            {
                result = headA;                
                break;
            }
            table[headA] = true;
            headA = headA -> next;
            
            if(table.count(headB))
            {
                result = headB;                
                break;
            }
            
            table[headB] = true;
            
            headB = headB -> next;
        }
        while(headA and !result) {
            if(table.count(headA)) {
                result = headA; 
                break;
            }
            table[headA] = true;
            headA = headA -> next;            
        }
        while(headB and !result) {
            if(table.count(headB)) {
                result = headB; 
                break;
            }
            table[headB] = true;
            headB = headB -> next;            
        }
        return result; 
        
        
        
    }
};

/*

Think about this recursively. 

the specicial thing about LL is what we see here.. there are 2 LL which we are giving as inputs to our func...









*/