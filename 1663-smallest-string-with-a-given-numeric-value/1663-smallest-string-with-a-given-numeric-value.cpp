class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string answer(n,'a');
        k -= n;
        int val;
        while(k > 0) {            
            answer[--n] += min(k,25);
            k -= min(k,25);
            
            
        }
        return answer;
        
    }
};