class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int low = 0;
        int hi = letters.size() - 1;
        int mid = -1;
        
        if(letters[hi] <= target) { 
            return letters[low];
        }
        
        
        while(low <= hi) {
            
            mid = low + (hi - low) / 2;
            if (letters[mid] <= target) { // unfavorable. 
                low = mid + 1;
            }
            else {
                hi = mid - 1; // we will push hi beyond the bondary.. so lo will contain the answer;
            }
                
        }
        
        return letters[low];    
    }
};