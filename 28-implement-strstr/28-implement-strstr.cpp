class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int m = needle.size();
        
        if(m == 0) { return 0; }
        
        int start = 0, end = -1;
        int idx = -1;
        while(start <= n-m) {
            idx = 0;
            if(haystack[start] == needle[idx]) { // 1st character matched
                idx++;
                end = start+1;
                while(end < n and idx < m) { // ensure we check for 2nd and beyond only when it is within range
                    
                    if(haystack[end] != needle[idx]) {               // if something doesn't match, then we need to start seearching again from start..                                 
                        break;
                    }
                    
                    // If things are matching, just keep incrementing the end in the haystack and idx in needle
                    end++;
                    idx++;
                }
                
                if(idx == m) { // this means we must have found the needle so we can happily return 
                    return start;        
                }
                
            } 
            // incrment the start
            start++;
        }
        return -1;        
    }
};