class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        // Sort based on end times..
        sort(points.begin(), points.end(), [](vector<int>& v1, vector<int>& v2){return v1[1] < v2[1] ? true:false;});
        
        int maxEnd = points[0][1];
        int nArrows = 1;
        int curStart = 0;
        for (int idx = 1; idx < points.size(); idx++) { // Iterate over all ballons. The ballons coming first will have smallerend..
            
            curStart = points[idx][0];
                        
            if (curStart <= maxEnd) {
                // we dont worry about it
            }
            else // means we need another arrow
            {
                maxEnd = points[idx][1]; // now this ballon's end becomes the gating criterion...
                nArrows++;
            }
        }
        
        return nArrows;
            
            
            
        
    }
};