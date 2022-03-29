class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s = 0;
        int e = nums.size() - 1;
        int m;
        
        while(s <= e) {
            
            m = s + (e - s) / 2;
            
            if (nums[m] == target) { return m; }
            
            if (nums[s] <= nums[m]) { // means we are sorted b/w s to m
            
                if(target >= nums[s] and target < nums[m]) { // definatey target is between s and m
                    e = m - 1;                    
                }
                else if (target < nums[s]) { // this means the pivot is likly on the right side.. also.. as target is less than start it is likely going to be smallrt than mid too..
                    s = m + 1;
                }
                else
                {
                     s = m + 1;
                    // assert(0);
                }
            }
            else // we must be sorted b/w m to end
            {
                if (target > nums[m] and target <= nums[e]) {
                    s = m + 1;                    
                }
                else if (target >nums[e] ) // then it 
                {
                    e = m - 1;
                 }
                else
                {
                    e = m - 1;
                    // assert(0);
                }
            }
        }
        return -1;
        
    }
};