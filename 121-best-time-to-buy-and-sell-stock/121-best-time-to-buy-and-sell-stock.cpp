class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int currProfit = 0;
        int maxProfit = 0;
        int minCost = INT_MAX;
        
        for (int i = 0; i < prices.size(); i++) {
            
            minCost = min(minCost, prices[i]);
            
            currProfit = prices[i] - minCost;
            
            maxProfit = max(maxProfit, currProfit);
        }
        return maxProfit;
    }
};