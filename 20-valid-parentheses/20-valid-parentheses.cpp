class Solution {
public:
    bool isValid(string s) {

        stack<char> mystack;
        char topItem;
        for (auto& ch : s) // 1. Iterative over the string character by character
        {
            if ((ch == '{') or (ch == '[') or (ch == '(')) // 2. Check for opening brackets
            {
                mystack.push(ch); // 2.1 Add them to the stack               
            }
            else if ((ch == '}') or (ch == ']') or (ch == ')')) // 3. Check for closing brackets
            {
                // Now it super important that stack is not empty as we are about to pop. 
                if(mystack.empty()) { return false; }
                
                topItem = mystack.top(); mystack.pop();
                switch(ch) // 3.1 make sure they are a pair. if not return false
                {
                    case ')': if (topItem!='(') { return false; } break;
                    case '}': if (topItem!='{') { return false; } break;
                    case ']': if (topItem!='[') { return false; } break;
                }
            }
            else
            {
                return false; // 4. we don't expect any other character
            }
        }
        return mystack.empty() ? true : false;         // 5. at the end the stack has to be empty! else the string was unbalanced.
    }
};

