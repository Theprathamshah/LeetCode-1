class Solution {
public:
    int mySqrt(int x) {
        
        int lo = 1;
        int hi = x;
        double mid = -1;
        
        while (lo <= hi) {
            
            mid = lo + (hi - lo) / 2;
            
            if(mid*mid > x) { // unfavorable region
                hi = mid - 1;
            }
            else { // this is favor region. also, we will push lo past the final answer such that at the end hi points to the solution!
                lo = mid + 1;                
            }            
        }   
        return hi;            
    }
};