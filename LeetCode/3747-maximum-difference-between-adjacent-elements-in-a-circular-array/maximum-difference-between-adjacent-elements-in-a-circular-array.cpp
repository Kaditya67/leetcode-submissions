class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDist=0;
        int n = nums.size();
        int d=0;
        for(int i=1;i<n;i++){
            d=max(d,abs(nums[i]-nums[i-1]));
        }

        d=max(d,abs(nums[n-1]-nums[0]));
        return d;
    }
};