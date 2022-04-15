class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum = INT_MIN;
        int currentSum = INT_MIN;
        
        for(auto& n : nums) {
            
            if (currentSum < 0) { // means we should start fresh
                currentSum = n;                
            }
            else { // in all other cases we should update currentSum, even though "n" might be negative. that's coz the next number might be bigger than the current negative number eventually bringing up the current sum..
                currentSum += n;
                
            }
            maxSum = max(maxSum, currentSum);
            
        }
        return maxSum;
        
    }
};
