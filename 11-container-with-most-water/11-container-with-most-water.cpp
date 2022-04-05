class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxArea = -1;        
        int leftWall = 0;
        int rightWall = height.size() - 1;
        
        int currArea = -1;
        int currHeight;
        int currWidth = rightWall - leftWall;
        while(leftWall < rightWall) {            
          
            if (height[leftWall] < height[rightWall]) {
                currHeight = height[leftWall];
                leftWall++;
            }
            else
            {
                 currHeight = height[rightWall];
                 rightWall--;
            }
            maxArea = max(maxArea, currHeight * currWidth);
            currWidth--;
            
        }
        return maxArea;
    }
};