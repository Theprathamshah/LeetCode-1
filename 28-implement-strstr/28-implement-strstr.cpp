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
            if(haystack[start] == needle[idx]) {
                idx++;
                end = start+1;
                while(end < n and idx < m) {
                    
                    if(haystack[end] != needle[idx]) {                                                
                        break;
                    }
                    end++;
                    idx++;
                }
                if(idx == m) {
                    return start;        
                }
                
            } 
            start++;
        }
        return -1;        
    }
};