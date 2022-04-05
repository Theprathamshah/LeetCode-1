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
    ListNode* swapNodes(ListNode* head, int k) {
        

        
        // Walk k steps
        ListNode* aheadByK = head;
        for (int i = 1; i < k; i++) { // as k <= n we don't have to worry about going out of bounds!
            aheadByK = aheadByK -> next;            
        }
        ListNode* kFromFront = aheadByK;
        aheadByK = aheadByK->next;
        
        // Walk n-k steps
        ListNode* KfromEnd = head;
        while(aheadByK) {
            KfromEnd = KfromEnd -> next;
            aheadByK = aheadByK -> next;            
        }
        
        int temp;
        temp = kFromFront->val;
        kFromFront->val = KfromEnd->val;
        KfromEnd->val = temp;
            
        return head;
        
    }
};