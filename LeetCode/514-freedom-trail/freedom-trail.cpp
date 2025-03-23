class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        unordered_map<char, vector<int>> index_map;
        
        for (int i = 0; i < n; i++) {
            index_map[ring[i]].push_back(i);
        }

        vector<int> dp(n, 0);

        for (int key_pos = m - 1; key_pos >= 0; key_pos--) {
            vector<int> new_dp(n, INT_MAX);
            char target_char = key[key_pos];

            for (int target_pos : index_map[target_char]) {
                
                for (int curr_pos = 0; curr_pos < n; curr_pos++) {
                    int clockwise = abs(target_pos - curr_pos);
                    int counterclockwise = n - clockwise;
                    int rotate_steps = min(clockwise, counterclockwise);
                    
                    new_dp[curr_pos] = min(new_dp[curr_pos], rotate_steps + 1 + dp[target_pos]);
                }
            }
            dp = new_dp; 
        }

        return dp[0];
    }
};