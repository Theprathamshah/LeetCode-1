class Solution {    
private:
    string cleanupString(const string& s)
    {
        char ch;
        string output;
        for(int i=0; i <s.size(); i++)
        {
            if (!((s[i] >=97 && s[i] <= 122) || (s[i] >=65 && s[i] <= 90) || (s[i] >=48 && s[i] <= 57)))  { 
                // non-alphanumeric characters
                continue;
            }            
            // ORing with 0x20(d32) will convert the upper to lower. Noop for lowercase
            ch = s[i] | (1 << 5); 
            
            // appending a character at the end of a string
            output.push_back(ch);            
        }
        return output;
    }
    
public:
    bool isPalindrome(string s) {
        
        string str = cleanupString(s);
        
        int start = 0;
        int end = str.size() - 1;
        
        while (start <= end)
        {
            if(str[start] != str[end]) { return false; }
            start++;
            end--;
        }
        
        return true;
        
    }
};