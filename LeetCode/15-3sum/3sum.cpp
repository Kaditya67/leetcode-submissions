class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int comp = -nums[i];
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] == comp) {
                    arr.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                } else if (nums[j] + nums[k] > comp) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return arr;
    }
};