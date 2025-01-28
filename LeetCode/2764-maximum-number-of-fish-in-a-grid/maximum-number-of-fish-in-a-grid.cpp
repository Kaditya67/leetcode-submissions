class Solution {
public:
    int dfs(int r,int c,int row,int col,vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=row || c >=col || grid[r][c]==0) return 0;
        int curr = grid[r][c];
        grid[r][c]=0;
        curr+=dfs(r+1,c,row, col, grid);
        curr+=dfs(r-1,c,row, col, grid);
        curr+=dfs(r,c+1,row, col, grid);
        curr+=dfs(r,c-1,row, col, grid);
        return curr;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]!=0){
                    ans = max(ans,dfs(r,c,row, col, grid));
                }
            }
        }
        return ans;
    }
};