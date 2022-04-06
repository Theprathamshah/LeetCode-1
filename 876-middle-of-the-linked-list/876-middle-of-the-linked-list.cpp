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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next and fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next) {
            slow = slow->next;
        }
        return slow;
        
    }
};

/*

fast and slow right..

1 2 3 4 5 N
|
|
  |
    |
    |
       |
    
1 2 3 4 5 6 N
|
|
--------------
    |
  |
--------------
        |
    |
--------------
    










*/