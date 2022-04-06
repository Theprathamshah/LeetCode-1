class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> finalProductExceptSelf(n,1); // we'l; not count this in terms of space
        for(int i = 1; i < n; i++) { // Time: O(N)
            finalProductExceptSelf[i] = finalProductExceptSelf[i-1] * nums[i-1];
        }
         
        // vector<int> rightProductExceptSelf(n, 1);
        // for(int i = n-2; i >= 0; i--) {
        //     rightProductExceptSelf[i] = rightProductExceptSelf[i+1] * nums[i+1];
        // }
        
        // In the space optimized approvh we will build R on the fly..
        int rightProductExceptSelf = 1;
        
        // again here also, we will start from right side.. and keep updating rightProductExceptSelf as we go..
        for(int i = n-1; i >= 0; i--) {
            finalProductExceptSelf[i] = finalProductExceptSelf[i] * rightProductExceptSelf;
            rightProductExceptSelf *= nums[i];
        }
        
        
        // vector<int> finalProductExceptSelf(n,1); // we'l; not count this in terms of space
        // // for(int i = 0; i < n; i++) {
        // //     finalProductExceptSelf[i] = leftProductExceptSelf[i] * rightProductExceptSelf[i];
        // // }        
        // transform(leftProductExceptSelf.begin(), leftProductExceptSelf.end(), rightProductExceptSelf.begin(), finalProductExceptSelf.begin(), multiplies<int>());
        
        return finalProductExceptSelf;
    }
};