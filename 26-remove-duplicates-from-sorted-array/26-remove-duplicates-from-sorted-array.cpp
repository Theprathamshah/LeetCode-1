class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int count = 1;
        int i = 0; // i+1 is where we want to copy the new value if it doesn't match
        for (int j = i+1; j<n; j++) {
            
            if (nums[i] != nums[j]) { // something changed
                
                // copy the new value to i+1 idx
                nums[i+1] = nums[j];
                
                //incrememnt i by 1 so we will check for new duplicates
                i++;
                
                //increse the counter
                count++;                
            }            
        }
        return count;
    }
};

/*

1 1 1 2 2 3 3
1 1 <- same, incremembt j
1   1 <- same increment j
1     2 <- diff. now copy j val to i+1, increment i, increment j, count++


*/