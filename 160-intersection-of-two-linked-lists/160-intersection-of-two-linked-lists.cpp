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
        
        while(headA) {
            stackA.push(headA);
            headA = headA->next;
        }
        while(headB) {
            stackB.push(headB);
            headB = headB->next;
        }
        
        ListNode* tempA;
        ListNode* tempB;
        ListNode* answer = nullptr;
        while(!stackA.empty() and !stackB.empty()) { // while one of them is not empty            
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