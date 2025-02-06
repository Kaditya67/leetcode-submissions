class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size();
         
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                productCount[nums[i] * nums[j]]++;
            }
        }

        int result = 0;
        // Calculate the number of valid tuples
        for (auto &[product, count] : productCount) {
            if (count > 1) {
                result += count * (count - 1) * 4;
            }
        }

        return result;
    }
};
