class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        if (k > n) return -1;  

        int cnt = 0, ans = k;  

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'B') cnt++;
        }
        ans = min(ans, k - cnt);  

        for (int i = k; i < n; i++) {
            if (blocks[i] == 'B') cnt++;  
            if (blocks[i - k] == 'B') cnt--;  

            ans = min(ans, k - cnt);
        }

        return ans;
    }
};
