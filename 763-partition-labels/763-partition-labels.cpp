class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int> freq;
        
        // populate freq.
        for(auto& ch: s) {
            freq[ch]++;
        }
        
        set<char> unique;
        char ch;
        
        int partitionLen = 0, countNonZeroInPartition = 0;
        vector<int> lengthsOfPartitions;
        
        for(int i = 0; i < s.size(); i++) {
            
            ch = s[i];
            
            partitionLen++;
            
            countNonZeroInPartition = 0;
            
            // start of a new partition
            unique.insert(ch);
            
            //Decrement from the freq map
            freq[ch]--;
            
            int countInParitiion;
            for(auto& c : unique) {
                countNonZeroInPartition+= freq[c];
                if (countNonZeroInPartition!= 0)
                {
                    break;
                }                
            }
            
            if(countNonZeroInPartition == 0) // all elements found are in this partition
            {
                unique.clear();
                
                lengthsOfPartitions.push_back(partitionLen);
                partitionLen = 0;
            }
            
        }        
        
        return lengthsOfPartitions;
    }
};