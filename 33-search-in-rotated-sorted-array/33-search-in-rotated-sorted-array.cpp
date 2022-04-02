class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int lo = 0;
        int hi = nums.size() - 1;
        int mid;
        
        int answer = -1;
        while (lo <= hi) {
            
            mid = lo + (hi-lo)/2;
            
            if(nums[mid] == target) {
                answer = mid;
                break;
            }
            
            if (nums[lo] <= nums[mid]) { // lo --> mid is sorted
                
                if (target < nums[mid] and target >= nums[lo]) { // target is definately to the left of mid
                    hi = mid - 1;
                }
                else // in all other cases, target will be in the right..
                {
                    lo = mid + 1;
                }
            }
            else //  mid --> hi is sorted
            {
                if (target > nums[mid] and target <= nums[hi]) { // target is definately to the right of mid
                    lo = mid + 1;                
                }
                else {
                    hi = mid - 1;
                }
            }           
        }
        return answer;        
    }
};