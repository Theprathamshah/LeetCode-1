class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int N = 1 + *max_element(nums.begin(), nums.end());
        
        vector<int> freq(N,0);
        for (auto& num: nums)
        {
            freq[num]++;
        }
        
        vector<int> dp(N,0);
        dp[0] = 0;
        dp[1] = max(freq[1]*1, freq[0]*0);
        
        for(int i=2;i<N;i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + freq[i]*i);
        }
        return dp[N-1];
    }
};