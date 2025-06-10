class Solution {
public:
    int maxDifference(string s) {
        vector<int> mpp(26);
        int maxi = 0, mini = INT_MAX;

        for (char c : s) mpp[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (mpp[i] % 2 != 0)
                maxi = max(maxi, mpp[i]);
            if (mpp[i] % 2 == 0 && mpp[i] > 0)
                mini = min(mini, mpp[i]);
        }

        // If no even frequency exists, avoid INT_MAX subtraction
        if (mini == INT_MAX) return maxi;
        return maxi - mini;
    }
};
