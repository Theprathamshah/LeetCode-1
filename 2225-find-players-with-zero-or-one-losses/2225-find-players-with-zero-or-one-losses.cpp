class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int, pair<int,int>> players; // first -> losses, second -> wins
        
        for (auto& match: matches) {            
            players[match[0]].second++;
            players[match[1]].first++;
        }
                
        vector<vector<int>> answer(2);
        
        for (auto [idx, stats]: players) {
            
            if(stats.first == 0) {
                answer[0].push_back(idx);
            }
            else if (stats.first == 1) {
                answer[1].push_back(idx);
            }                        
        }
        
        return answer;
    }
};