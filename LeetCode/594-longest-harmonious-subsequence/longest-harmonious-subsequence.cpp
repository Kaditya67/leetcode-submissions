class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        int maxLen = 0;

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int key = it->first;
            int currCount = it->second;

            if (mp.find(key + 1) != mp.end()) {
                int total = currCount + mp[key + 1];
                maxLen = max(maxLen, total);
            }
        }

        return maxLen;
    }
};
