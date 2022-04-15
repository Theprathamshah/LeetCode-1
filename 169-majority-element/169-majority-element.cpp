class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        int maxElementCount = 0, maxElement;
        for_each(nums.begin(), nums.end(), [&](int n) { 
            freq[n]++; 
            if(maxElementCount < freq[n]) {
                maxElementCount = freq[n];
                maxElement = n;   
            }
        
        });
        
        return maxElement;
    }
};