class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long int leftSum = 0;
        long long int rightSum = 0;
 
        for (int i = 0; i < n; ++i) {
            rightSum+=nums[i];
        }

        int resCnt = 0; 
        for (int i = 0; i < n - 1; ++i) {
            leftSum+=nums[i];
            rightSum-=nums[i];
            if(leftSum>= rightSum){
                ++resCnt;
            }
        }
        return resCnt;
    }
};
