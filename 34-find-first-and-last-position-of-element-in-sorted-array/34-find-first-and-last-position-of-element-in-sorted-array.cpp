class Solution {

private:
    bool found(vector<int>& nums, int target) { // O(logN)        
        int sIdx = 0;
        int eIdx = nums.size() - 1;
        int mIdx = -1;
        bool isPresent = false;
        
        while(sIdx <= eIdx) {
            mIdx = sIdx + (eIdx - sIdx) / 2;
            
            if (nums[mIdx] == target) {
                isPresent = true;
                break;
            }
            else if (nums[mIdx] < target) { 
                sIdx = mIdx + 1;
            }
            else { 
                eIdx = mIdx - 1;            
        }
    }
    return isPresent;
    }
    
    int getLowerBoundIdx(vector<int>& nums, int target) { // O(logN)        
        int sIdx = 0;
        int eIdx = nums.size() - 1;
        int mIdx = -1;
        bool isPresent = false;
        
        while(sIdx <= eIdx) {
            mIdx = sIdx + (eIdx - sIdx) / 2;
                        
            if (nums[mIdx] < target) { // unfavorable
                sIdx = mIdx + 1;
            }
            else {  // favroable. goal is to push sIdx one past the LB
                eIdx = mIdx - 1;            
            }   
        }
        return sIdx; // eIdx was posted at 1 less than LB
    }
    
    int getUpperBoundIdx(vector<int>& nums, int target) { // O(logN)        
        int sIdx = 0;
        int eIdx = nums.size() - 1;
        int mIdx = -1;
        bool isPresent = false;
        
        while(sIdx <= eIdx) {
            mIdx = sIdx + (eIdx - sIdx) / 2;
                        
            if (nums[mIdx] > target) { // unfavorable
                eIdx = mIdx - 1;
            }
            else { // favroable. goal is to push sIdx one past the UB                
                sIdx = mIdx + 1;
            }   
        }
        return eIdx; // sIdx was posted at 1 past UB
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) { // O(logN)        
        
        int lb = -1, ub = -1;
        
        int sIdx = 0;
        int eIdx = nums.size() - 1;
        int mIdx = -1;
        
        while(sIdx <= eIdx) {
            mIdx = sIdx + (eIdx - sIdx) / 2;
                        
            if (nums[mIdx] < target) { // unfavorable
                sIdx = mIdx + 1;
            }
            else {  // favroable. goal is to push sIdx one past the LB
                eIdx = mIdx - 1;            
            }   
        }
        lb = sIdx; // eIdx was posted at 1 less than LB
        
        eIdx = nums.size() - 1;
        while(sIdx <= eIdx) {
            mIdx = sIdx + (eIdx - sIdx) / 2;
                        
            if (nums[mIdx] > target) { // unfavorable
                eIdx = mIdx - 1;
            }
            else { // favroable. goal is to push sIdx one past the UB                
                sIdx = mIdx + 1;
            }   
        }
        ub = eIdx;
        
        return lb == ub+1 ? vector<int> {-1,-1} : vector<int> {lb,ub};
        
    }
};