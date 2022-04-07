class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        // 1. Do a XOR. The bits that are different will become 1
        // 2. Count number of set bits using Brian Kernighan's Algorithm
        
        int xored = start ^ goal;
        
        int count = 0;
        while(xored) {
            xored &= (xored-1);            
            count++;
        }
        return count;
        
    }
};