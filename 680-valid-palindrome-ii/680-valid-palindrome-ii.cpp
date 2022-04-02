class Solution {
private:
    bool helper(string& s, int l, int h, bool chanceLeft = true) {
        
        if (l >=h) {
            return true;
        }
        
        bool answer = false;
        if (s[l] == s[h]) {
            answer |= helper(s,l+1,h-1,chanceLeft);
        }
        else if (!chanceLeft) {
            return false;
        }
        else
        {
            chanceLeft = false;                
            if (s[l+1] == s[h]) {
                answer |= helper(s, l+1, h, chanceLeft);
            }        
            if (s[l] == s[h-1]) {
                answer |= helper(s, l, h-1, chanceLeft);
            }
            
        }
        return answer;        
    }
public:
    bool validPalindrome(string s) {
        
        int l = 0;
        int h = s.size() - 1;
        
        return helper(s,l,h);
     }
};

// "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"
// "eeccccbebaeeabebccceea"
// "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"
// "eeccccbebaeeabebccceea"