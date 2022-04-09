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
        
        stack<ListNode*> stackA, stackB;
        
        // Put all the nodes from A into a stack
        while(headA) { // O(n) time, O(n) space)
            stackA.push(headA);
            headA = headA->next;
        }
        // Put all the nodes from B into a stack
        while(headB) {
            stackB.push(headB);
            headB = headB->next;
        }
        
        ListNode* tempA;
        ListNode* tempB;
        ListNode* answer = nullptr;
        while(!stackA.empty() and !stackB.empty()) { // while both of them not empty
            tempA = stackA.top(); stackA.pop();
            tempB = stackB.top(); stackB.pop();
            if(tempA != tempB) {
                break;
            }            
            answer = tempA;
        }
        return answer;
    }
};