class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0, flowers = 0;
        for (int b : bloomDay) {
            if (b <= day) {
                flowers++;
                if (flowers == k) {
                    count++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * m * k;
        if (bloomDay.size() < total) return -1; 

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (isPossible(bloomDay, m, k, mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
