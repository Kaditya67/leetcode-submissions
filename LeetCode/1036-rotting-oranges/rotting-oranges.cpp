class Solution {
public:
    typedef pair<int,int> P;
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P> que;
        int freshCount=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }else if(grid[i][j]==1){
                    freshCount++;
                }
            }
        }
        if(freshCount==0){
            return 0;
        }

        vector<vector<int>> directions{{-1,0},{1,0},{0,1},{0,-1}};
        int minute=0;
        while(!que.empty()){
            int N = que.size();
            while(N--){ // iterate new queue elements
                P curr = que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;

                for(auto &dir:directions){
                    int _i = i+dir[0];
                    int _j = j+dir[1];

                    if(_i>=0 && _i<m && _j>=0 && _j<n && grid[_i][_j]==1){
                        grid[_i][_j]=2;
                        que.push({_i,_j});
                        freshCount--;
                    }
                }
            }
            minute++; // increase minute for new queue
        }
        return freshCount==0?minute-1 : -1;
    }
};