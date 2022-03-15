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
        string ans="/";
        stack<string> reversed;
        
        if(input.empty()){
            return ans;
        }
        
        while(!input.empty()){ 
            reversed.push(input.top()); input.pop();
        }
        
        while(!reversed.empty()){
            ans+=reversed.top()+"/"; reversed.pop(); // appending at the end is much faster
        }
        
        return ans.substr(0,ans.length()-1);        
    }

};