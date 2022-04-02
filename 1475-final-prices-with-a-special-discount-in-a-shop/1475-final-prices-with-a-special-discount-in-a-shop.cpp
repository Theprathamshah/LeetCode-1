class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            int finalPrice = prices[i];
            int j = i + 1;
            while (j < n) {
                int discount = prices[j];
                if (discount <= finalPrice) {
                    finalPrice -= discount;
                    break;
                }
                j++;
            }
            answer.push_back(finalPrice);
        }
        return answer;
    }
};