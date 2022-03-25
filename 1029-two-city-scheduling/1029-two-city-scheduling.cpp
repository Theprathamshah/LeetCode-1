class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        
        vector<pair<int,int>> diff(n); //first->difference, second->idx
        
        for(int i = 0; i < costs.size(); i++) {
            
            diff[i].first = costs[i][0] - costs[i][1];            
            diff[i].second = i; 
        }
               
        sort(diff.begin(), diff.end()); // sort in ascending based on first.. means 0 to n-1 -> a and n to 2n-1 -> b
        
        int total=0, idxInCost;
        for(int i=0; i < diff.size()/2; i++) {
            
            idxInCost = diff[i].second;
            total += costs[idxInCost][0];
        }
        for(int i=diff.size()/2; i < diff.size(); i++) {
            
            idxInCost = diff[i].second;
            total += costs[idxInCost][1];
        }
        return total;
    }
};


/*

[259,770], -500 a 
[184,139], 45 a
[577,469] 100 a

[926,667], 300 b
[448,54], 450 b
[840,118], 600 b

*/
    
    