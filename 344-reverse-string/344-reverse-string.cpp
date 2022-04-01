class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int sIdx = 0;
        int eIdx = s.size() - 1;
        char temp;
        while(sIdx <= eIdx) {
            
            temp = s[sIdx];
            s[sIdx++] = s[eIdx];
            s[eIdx--] = temp;
            
        }
    }
};

/*

h e l




*/