class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int oddCount = 0;
        int evenCount = 0;
        for(int i=0;i<n;i++){
            if(position[i]&1) ++oddCount;
            else ++evenCount;
        }
        return min(oddCount,evenCount);
    }
};