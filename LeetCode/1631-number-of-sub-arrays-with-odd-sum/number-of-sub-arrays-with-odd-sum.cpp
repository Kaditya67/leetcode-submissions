class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0, even = 1; 
        long long count = 0, prefixSum = 0;
        
        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2 == 0) {
                count = (count + odd) % MOD;
                even++;  
            } else {
                count = (count + even) % MOD;
                odd++;
            }
        }
        
        return count;
    }
};
