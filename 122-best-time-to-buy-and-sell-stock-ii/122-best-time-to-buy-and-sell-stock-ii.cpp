class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        bool bought = false;
        int overallProfit = 0;
        int cost = 0;
        for(int i = 0; i < n-1; i++) { // we'll not go till the last value
            
            if(!bought) { // buying strategy
                
                // i should buy if the next price is greater than mine
                if(prices[i+1] > prices[i]) {
                    
                    bought = true;
                    
                    cost = prices[i];
                    
                }
                
                
            }
            else { // selling strategy
                
                if(prices[i+1] < prices[i]) { // if the next price is smaller than mine then sell
                    
                    bought = false;
                    
                    overallProfit += prices[i] - cost;
                    
                    //Reset cost
                    cost = 0;
                }
                
            }
            
        }
        
        if(bought) { // this means we never sold it yet, so lets sell it now
            overallProfit += prices[n-1] - cost;
        }
        
        
        
        return overallProfit;
        
    }
};

/*

7 1 5 3 6 4 <-- scan once and find min

cp=1 sp=1 profit = 0
cp=1 sp=5 should i sell? i should compare my value with i+1.. if the value is larger, i should hold. if it is smaller, i should sell... given i have already bougth it..
cp=1 sp=3 profit = 2, max profit = 2

15 36

















*/