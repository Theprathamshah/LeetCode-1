class Solution {
public:
    string simplifyPath(string path)         
    {
        vector<string> components = split(path, '/');
        
        stack<string> mystack;
        for (auto& component : components)
        {
            
            if(component == "." or component == "")
            {
                continue;
            }
            else if (component == "..")
            {
                if(!mystack.empty())
                {
                    mystack.pop();
                }
            }
            else
            {
                mystack.push(component);  
            }
        }
        string output = createCanonicalPath(mystack);
        return output;
    }
private:
    vector<string> split(const string& input, char delimiter)
    {
        istringstream ss(input);
        vector<string> output;
        string item;
        while(getline(ss, item, delimiter))
        {
            output.push_back(item);
        }
        return output;
        
    }
    string createCanonicalPath(stack<string> input)
    {
        if(input.empty())
        {
            return "/";
        }
        
        string output = {};
        string part;
        while(!input.empty())
        {
            part = input.top(); input.pop();
            output = "/" + part + output;
        }
        return output;        
    }

};