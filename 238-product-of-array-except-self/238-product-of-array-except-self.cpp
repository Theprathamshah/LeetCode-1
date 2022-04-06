class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> leftProductExceptSelf(n, 1); // Space: O(N)        
        for(int i = 1; i < n; i++) { // Time: O(N)
            leftProductExceptSelf[i] = leftProductExceptSelf[i-1] * nums[i-1];
        }
         
        vector<int> rightProductExceptSelf(n, 1);
        for(int i = n-2; i >= 0; i--) {
            rightProductExceptSelf[i] = rightProductExceptSelf[i+1] * nums[i+1];
        }
        
        vector<int> finalProductExceptSelf(n,1);
        for(int i = 0; i < n; i++) {
            finalProductExceptSelf[i] = leftProductExceptSelf[i] * rightProductExceptSelf[i];
        }
        
        return finalProductExceptSelf;
    }
};