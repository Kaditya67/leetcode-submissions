class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);  // Output array (we must return a new array)

        int index = 0;
        
        // First Pass: Add elements < pivot
        for (int num : nums) {
            if (num < pivot) {
                result[index++] = num;
            }
        }
        
        // Second Pass: Add elements == pivot
        for (int num : nums) {
            if (num == pivot) {
                result[index++] = num;
            }
        }

        // Third Pass: Add elements > pivot
        for (int num : nums) {
            if (num > pivot) {
                result[index++] = num;
            }
        }
        
        return result;
    }
};
