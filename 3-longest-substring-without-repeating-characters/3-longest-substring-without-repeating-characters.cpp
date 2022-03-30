class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int startIdx = 0;
        int endIdx = 0;
        vector<int> map(128,-1); // <char, lastseenIdx>
        char ch;
        int maxSize = 0;
        for (int endIdx = 0; endIdx < s.size(); endIdx++) {
            ch = s[endIdx];
            if(map[ch] >= 0) { //present
                
                if (startIdx <= map[ch]) { // means we need to update startIdx to move to the next idx
                    startIdx = map[ch] + 1;
                }
                
            }
            // also need to update the last seen idx
            map[ch] = endIdx; 
            
            maxSize = max(maxSize, endIdx - startIdx + 1);
            
        }
        return maxSize;
    }
};