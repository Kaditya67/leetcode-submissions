class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int left = lower - nums[i];
            int right = upper - nums[i];

            int l = lower_bound(nums.begin() + i + 1, nums.end(), left) - nums.begin();
            int r = upper_bound(nums.begin() + i + 1, nums.end(), right) - nums.begin();

            res += (r - l);
        }

        return res;
    }
};
