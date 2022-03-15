class Solution {
public:
    string simplifyPath(string path) {
        vector<string> components = splitStringstream(path,'/');   // splitting the path at '/' is the key
        string output = cleanupAndMerge(components);
        return output;           
    }
private:
    
    // Function to split the input string in the Unix style to a vector of Strings demlimited by '/'
    vector<string> splitStringstream(const string& input, char delimiter) {
        istringstream ss(input);
        vector<string> components;
        string component;
        while(getline(ss, component, delimiter)) {
            components.push_back(component);
        }
        return components;        
    }
    
    // Function to split the input string in the Unix style to a vector of Strings demlimited by '/'
    vector<string> splitIterate(const string& input, char delimiter) {
        
        vector<string> components;
        string component = {};
                
        for(int i = 0; i < input.size(); i++)
        {
            if (input[i] == delimiter) 
            {               
                components.emplace_back(component);  
                //component = {};
            }
            else
            {
                component.push_back(input[i]); // Append the character to the word                
            }            
        }    
        components.emplace_back(component); // if the input doesn't have / at the end (as that is optional)        
        return components;
    }
    
    
    // Function to cleanup and merge the vector of sumcomponents to form the cannonical path
    string cleanupAndMerge(vector<string> components) {
                
        stack<string> mystack;
        // Filter out unnessasary stuff and process double period (..) to push the cleaned up path to the stack
        for (auto& component : components) {
            
            if(component == "." or component == "") {
                continue;
            }
            else if (component == "..") {
                if(!mystack.empty()) {
                    mystack.pop();
                }
            }
            else {
                mystack.push(component);  
            }
        }
        
        string ans="/";
        
        // Use an additional stack to improve time complexity while creating the cannonical path
        stack<string> reversed;
        if(mystack.empty()){
            return ans;
        }
        
        while(!mystack.empty()){ 
            reversed.push(mystack.top()); mystack.pop();
        }
        
        while(!reversed.empty()){
            ans+=reversed.top()+"/"; reversed.pop(); // appending at the end of the is much faster
        }
        
        return ans.substr(0,ans.length()-1); // Omiting the last character as we are adding an extra / inside the while loop
    }

};