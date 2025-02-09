class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = (long long)n * (n - 1) / 2;
        unordered_map<int, long long> badCount;
        for (int i = 0; i < n; i++) {
            int bad = nums[i] - i;
            totalPairs -= badCount[bad];
            badCount[bad]++;
        }
        return totalPairs;
    }
};