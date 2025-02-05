class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0; // Edge case where there are fewer than 2 prices

        int minPrice = prices[0];  
        int maxProfit = 0;  
        for (int i = 1; i < n; i++) { 
            maxProfit = max(maxProfit, prices[i] - minPrice); 
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
