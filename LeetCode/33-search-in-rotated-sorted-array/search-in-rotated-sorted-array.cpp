class Solution {
public:
    int binarySearch(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;

        // Find the pivot where rotation happens
        while (i < n - 1 && nums[i] < nums[i + 1]) i++;

        // i is now the pivot index

        // If no rotation found (fully sorted)
        if (i == n - 1) return binarySearch(nums, target);

        // Create two subarrays
        vector<int> left(nums.begin(), nums.begin() + i + 1);

        // Search in left part
        int ans1 = binarySearch(left, target);
        if (ans1 != -1) return ans1;

        vector<int> right(nums.begin() + i + 1, nums.end());
        // Search in right part and add offset
        int ans2 = binarySearch(right, target);
        if (ans2 != -1) return ans2 + i + 1;

        return -1;
    }
};
