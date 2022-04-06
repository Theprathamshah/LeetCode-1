class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // 0 -> logical_not -> true.. will move to the begining..
        // if we traverse the list from beginnning.. all zeros will move to the front..
        // therfore, we should traverse the list from the back :)
       stable_partition(nums.rbegin(), nums.rend(), logical_not<int>());
    }
};