class Solution {
public:
    int rob(vector<int>& nums) {
        
               
        int n = nums.size();
        
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);;
        
//         vector<int> dp(n,0);
        
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
        
//         for (int i = 2; i < n; i++) {
//             dp[i] = max(               
//                 dp[i-2] + nums[i], 
//                 dp[i-1]);
//         }
//         return dp[n-1];
        
        int nMinus2 = nums[0];
        int nMinus1= max(nums[0], nums[1]);
        int nMinus0 = -1;
        
        for (int i = 2; i < n; i++) {
            
            nMinus0 = max(nMinus2 + nums[i], nMinus1);
            
            // Move by 1
            nMinus2 = nMinus1;
            nMinus1 = nMinus0;
        }
        
        return nMinus0;
            
            
        
        
    }
};