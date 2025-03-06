class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> freq(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
        }

        int a,b;
        int count=0;
        for(int i=1;i<(n*n+1);i++){
            if(freq[i]==2 && count<2){
                a = i;
                count++;
            }
            if(freq[i]==0 && count<2){
                b = i;
                count++;
            }
        }
        return {a,b};

    }
};