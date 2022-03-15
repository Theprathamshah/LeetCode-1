class Solution {
public:
    string simplifyPath(string path) {
        vector<string> components = split(path);       
        string output = merge(components);
        return output;           
    }
private:
    
    // Function to split the input string in the Unix style to a vector of Strings demlimited by '/'
    vector<string> split(const string& input, char delimiter= '/') {
        istringstream ss(input);
        vector<string> output;
        string item;
        while(getline(ss, item, delimiter)) {
            output.push_back(item);
        }
        return output;        
    }
    
    // Function to merge the vector of sumcomponents to form the cannonical path
    string merge(vector<string> components) {
                
        stack<string> mystack;
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
        
        return ans.substr(0,ans.length()-1); // Omiting the last character as it is "/"       
    }

};