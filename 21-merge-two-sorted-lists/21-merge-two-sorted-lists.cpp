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
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
//         if(!list1 and !list2) {return nullptr; }
//         if(!list1) { return list2; }
//         if(!list2) { return list1; }
        
//         if(list1->val < list2->val) {
//             list1->next = mergeTwoLists(list1->next, list2);
//             return list1;
//         }
//         else {
//             list2->next = mergeTwoLists(list1, list2->next);
//             return list2;
//         }
//     }
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* sentinal = new ListNode(-101);
        sentinal->next = nullptr;
        
        ListNode* prev = sentinal;
        
        while(list1 and list2) { // we do all this compare business until both are present.. after that we will just connect to which ever is alive..
          
            if(list1 -> val < list2->val) {
                prev->next = list1;
                list1 = list1->next;
            }
            else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev -> next;            
        }
        
        if(list1) {
            prev->next = list1;
        }
        else if(list2) {
            prev->next = list2;
        }
        else {
            prev->next = nullptr;
        }
        
        ListNode* answer = sentinal->next;
        delete sentinal;
        
        return answer;
        
  
    }
};