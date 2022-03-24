class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int sIdx = 0;
        int eIdx = height.size() - 1;
        
        int hight, width, maxAmount = 0;
        while(sIdx < eIdx) {
            
            hight = min(height[sIdx], height[eIdx]);
            width = eIdx - sIdx;
            
            maxAmount = max(maxAmount, hight*width);
            
            if (height[sIdx] < height[eIdx]) {
                sIdx++;
            }
            else
            {
                eIdx--;
            }            
        }
        return maxAmount;
        
        
    }
};