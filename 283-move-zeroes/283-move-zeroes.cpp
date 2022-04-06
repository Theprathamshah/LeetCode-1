class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int nextNonzeroIdx = 0;
        int currIdx = 0;
        
        while(currIdx < nums.size()) {
            
            if(nums[currIdx]) { // non zero value found
                
                // swap with nextNonzeroIdx                
                // swap(nums[nextNonzeroIdx], nums[currIdx]);
                
                // Instead of swapping (which is expensive), lets just copy it over..
                nums[nextNonzeroIdx] = nums[currIdx];
                
                // incrememnt nextNonzeroIdx so now nextNonzeroIdx points to the next locaiton where the val should go
                nextNonzeroIdx++;
            }
            currIdx++;            
        }
        
        // now everything from nextNonzeroIdx till the end can be a zero, right?
        fill(nums.begin() + nextNonzeroIdx, nums.end(), 0);
        
        
        return;
    }
};