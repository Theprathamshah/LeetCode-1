class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size();
        int n = board[0].size();
                                
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                                
                int count_1 = 0;                
                
                //delta to go to neighbor
                vector<int> x_dir = {-1,-1, 0, 1, 1, 1, 0,-1};
                vector<int> y_dir = { 0, 1, 1, 1, 0,-1,-1,-1};
                
                
                // Count live and dead neighbours
                for(int z = 0; z < x_dir.size(); z++) {
        
                    // Neighbor coordinate
                    int x_temp = i + x_dir[z]; 
                    int y_temp = j + y_dir[z]; 
                    
                    if( x_temp >= 0 and x_temp < m and y_temp >= 0 and y_temp < n) {
                        
                        if(board[x_temp][y_temp] > 0){
                            count_1++;
                        }   
                    }                    
                }
                
                // Take a snapshot of the cell's value
                // temp[i][j] = board[i][j];                
                
                // Update the snapshot for the following cases
                if(board[i][j] > 0) { 
                    
                    // #1 and #3
                    if(count_1 < 2 or count_1 > 3) {
                        board[i][j] = 2;
                    }    
                    // #2 doesn't need to be handled seperately
                } 
                else { 
                    // #4
                    if(count_1 == 3) {
                        board[i][j] = -1;
                    }
                }
            }
        }
        
        // temp has the snapshop. copy it back to board
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 2){
                    board[i][j] = 0;
                }
                else if(board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
};