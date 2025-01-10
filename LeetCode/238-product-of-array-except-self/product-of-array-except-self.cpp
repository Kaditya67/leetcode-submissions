class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        Calculate the product of all elements except the current element without using division.
        Use two passes: one to calculate the prefix product and another to calculate the suffix product.
        The final product for each element is the result of multiplying the prefix and suffix products.
        */
        int n = nums.size();
        vector<int> result(n, 1);  
        
        int prefixProduct = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefixProduct;
            prefixProduct *= nums[i];
        }
 
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }

        return result;
    }
};
