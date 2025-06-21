class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        vector<int> realFreq;
        for (int f : freq) {
            if (f > 0) realFreq.push_back(f);
        }

        sort(realFreq.begin(), realFreq.end());
        int n = realFreq.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int targetMin = realFreq[i];
            int targetMax = targetMin + k;
            int deletions = 0;

            for (int j = 0; j < n; ++j) {
                if (realFreq[j] < targetMin) {
                    deletions += realFreq[j];  // delete all
                } else if (realFreq[j] > targetMax) {
                    deletions += realFreq[j] - targetMax;  // reduce to max allowed
                }
            }
            ans = min(ans, deletions);
        }

        return ans;
    }
};
