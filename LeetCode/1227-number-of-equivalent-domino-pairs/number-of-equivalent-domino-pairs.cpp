class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> mp(100,0);
        int result=0;
        for(auto &d:dominoes){
            if(d[0]>d[1]) swap(d[1],d[0]);
            int num = d[0]*10+d[1];
            result+=mp[num];
            mp[num]++;
        }
        return result;
    }
};