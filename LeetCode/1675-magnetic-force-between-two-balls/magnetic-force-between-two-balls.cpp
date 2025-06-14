class Solution {
public:
    bool isPossible(vector<int>& position, int mid, int m) {
        int count = 1;
        int lastPos = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPos >= mid) {
                count++;
                lastPos = position[i];
                if (count >= m) return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1;
        int h = position.back() - position[0];
        int ans = 0;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (isPossible(position, mid, m)) {
                ans = mid; 
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }
};
