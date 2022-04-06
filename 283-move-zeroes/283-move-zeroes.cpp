class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int nextNonzeroIdx = 0;
        int currIdx = 0;
        
        while(currIdx < nums.size()) {
            
            if(nums[currIdx]) { // non zero value found
                
                // swap with nextNonzeroIdx
                // incrememnt nextNonzeroIdx so now nextNonzeroIdx points to the next locaiton where the val should go
                swap(nums[nextNonzeroIdx], nums[currIdx]);
                nextNonzeroIdx++;
            }
            currIdx++;            
        }
        return;
    }
};