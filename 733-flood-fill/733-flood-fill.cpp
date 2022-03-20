class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
        if (image[sr][sc] == newColor) { return image; }
        
        vector<vector<int>> mutableImage = image;
        queue<pair<int,int>> q; // q to store the co-rdinate of a cell (r,c)
        
        int sourceColor = image[sr][sc];
                
        int m = image.size(); // rows
        int n = image[0].size(); // columns
        
        // its given sc and sr and within bounds so we don't have to check
        q.push(make_pair(sr,sc));
        
        vector<int> rowDir = {1, -1, 0, 0};
        vector<int> colDir = {0, 0, 1, -1};
        
        int r,c;
        
        while(!q.empty())
        {
            // pop the coordinate
            auto& [row, column] = q.front(); q.pop();
            
            //chnage the color also
            mutableImage[row][column] = newColor;
           
            // Now we need to run BFS and go the nodes which had the same color as the startcell
            for(int i = 0; i < rowDir.size(); i++) {
                
                r = row + rowDir[i];
                c = column + colDir[i];
                
                if (r >= 0 and r < m and c >= 0 and c < n and mutableImage[r][c] == sourceColor) {
                    q.push(make_pair(r,c));
                }
            }
        }
        return mutableImage;
    }    
};