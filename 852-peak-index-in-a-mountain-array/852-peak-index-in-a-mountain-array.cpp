class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int lo = 0;
        int hi = arr.size() - 1;
        int mid = -1;
        
        while (lo <= hi) {
            
            mid = lo + (hi-lo)/2;
            
            if(mid < arr.size() and arr[mid] < arr[mid+1]) { // peak is on the right for sure...
                lo = mid + 1;                
            }
            else { // i am in the peak or the peak is on the left of me
                
                // the important point is in the equality case, where mid is the peak.. hi will move to the left of the peak.. and so when the while ends.. lo is the guy pointing to the peak!
                hi = mid - 1;                
            }                        
        }
        // as we know lo will be pointing to the peak at the conclusion of the while loop
        return lo;
        
    }
};