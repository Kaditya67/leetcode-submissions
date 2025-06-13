class Solution {
public:
    int ROW,COL;
    vector<vector<int>> directions = { 
        {1, 0},   // down
        {-1, 0},  // up
        {0, 1},   // right
        {0, -1}   // left
    };
    bool bfs(vector<vector<int>> &grid, int i, int j) {
        
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = 1;     // Mark Visited
        
        while(!que.empty()) {
            
            auto temp = que.front();
            que.pop();
            
            int x = temp.first;
            int y = temp.second;
            
            if(x == ROW-1)  // If last row reached --> Success
                return true;
            
            for(vector<int> & dir : directions) {       // Visit neighbours
                
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                
                if(new_x >= 0 && new_x < ROW && new_y >= 0 && new_y < COL && grid[new_x][new_y] == 0) {
                    que.push({new_x, new_y});
                    grid[new_x][new_y] = true;
                }
                
            }
            
        }
        
        return false;
    }
    bool dfs(vector<vector<int>>& grid,int i,int j){
        // Case
        if(i<0 || i>=ROW || j<0 || j>=COL || grid[i][j]==1){
            return false;
        }
        if(i==ROW-1) return true;   // End Row reached --> Success

        grid[i][j]=1;       // Mark Visited cell
        
        // Check for next cells in all directions and DFS for them
        for(vector<int> &dir:directions){
            if(dfs(grid, i+dir[0], j+dir[1])) return true;
        }

        return false;
    }
    bool canCross(vector<vector<int>>& cells,int day){
        vector<vector<int>>grid(ROW,vector<int>(COL));

        for(int i=0;i<=day;++i){
            int r=cells[i][0]-1;
            int c=cells[i][1]-1;

            grid[r][c]=1;
        }

        for(int j=0;j<COL;j++){
            if(grid[0][j]==0 && bfs(grid,0,j)){ // start from 1st row and move
                return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;
        vector<vector<int>>grid(row,vector<int>(col,0)); // Initialize 2D matrix with 0

        int n = cells.size();
        int l=0;
        int r=n-1;
        int lastDay=0;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(canCross(cells,mid)){
                l = mid+1;
                lastDay = mid+1;    // Index+1 gives day number
            }else{
                r = mid-1;
            }
        }
        return lastDay;
    }
};