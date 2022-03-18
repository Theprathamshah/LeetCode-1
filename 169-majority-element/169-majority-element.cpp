class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        
        int N = nums.size();
        
        int threshold = N/2;
        
        for (auto& num : nums) {
            
            
            if(++freq[num] > threshold) { return num;}
            
        }
        return -1;
        
    }
};