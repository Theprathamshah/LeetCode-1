class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int startIdx = 0;
        int endIdx = 0;
        unordered_map<char,int> map; // <char, lastseenIdx>
        char ch;
        int maxSize = 0;
        for (int endIdx = 0; endIdx < s.size(); endIdx++) {
            ch = s[endIdx];
            if(map.count(ch)) { //present
                
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