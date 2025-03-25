class Solution {
public:
    int n;
    vector<vector<int>>t;
    int solve(vector<vector<int>>& events, int idx, int k) {
        if(idx>=n || k<=0){
            return 0;
        }
        if(t[idx][k]!=-1) return t[idx][k];

        int start = events[idx][0];
        int end = events[idx][1];
        int value = events[idx][2];

        //skip
        int skip = solve(events,idx+1,k);
        int j=idx+1;
        for(;j<n;j++){
            if(events[j][0]>events[idx][1]) break;
        }

        int take = value + solve(events,j,k-1);
        return t[idx][k] = max(skip,take);        
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        sort(events.begin(),events.end());
        t.resize(n+1, vector<int>(k+1, -1));
        return solve(events,0,k);
    }
};