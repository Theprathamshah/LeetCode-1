class Solution {
private:
    bool found(vector<int>& nums, int target) { // binary search O(n)
        
        int s = 0;
        int e = nums.size()-1;
        int m;
        while(s <=e) {
            m = s + (e-s) / 2;
            if(nums[m] == target) { return true;}
            else if (nums[m] > target) {
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }
        return false;
        
    }
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        auto ans = vector<int>{-1,-1};
        if(found(nums,target)) {
            auto first_it = lower_bound(nums.begin(), nums.end(), target);
            auto last_it = upper_bound(nums.begin(), nums.end(), target);    
            ans[0] = first_it - nums.begin();
            ans[1] = --last_it  - nums.begin();
        }
        return ans;
        
        
    }
};