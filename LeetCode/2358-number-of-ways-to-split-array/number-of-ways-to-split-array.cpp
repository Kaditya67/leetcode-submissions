class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n);

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefixSum[i] = sum;
        }

        int resCnt = 0; 
        for (int i = 0; i < n - 1; i++) {
            if (prefixSum[i] >= (prefixSum[n - 1] - prefixSum[i])) {
                resCnt++;
            }
        }
        return resCnt;
    }
};
