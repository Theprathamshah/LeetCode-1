class Solution {
public:
    int calPoints(vector<string>& ops) {        
        stack<int> mystack;
        char ch;
        int a = 0,b = 0;
        for (auto& str: ops) {              
            ch = str[0];            
            switch(ch)
            {
                case 'C':
                    mystack.pop();
                    break;
                case '+':
                    a = mystack.top();mystack.pop();
                    b = mystack.top();mystack.pop();
                    mystack.push(b);
                    mystack.push(a);
                    mystack.push(a+b);
                    break;
                case 'D':
                    a = mystack.top();mystack.pop();
                    mystack.push(a);
                    mystack.push(a*2);
                    break;
                default:
                    mystack.push(stoi(str));
            }            
        }
        int sum = 0;
        while(!mystack.empty()) {
            sum += mystack.top(); mystack.pop();
        }
        return sum;
        
    }
};