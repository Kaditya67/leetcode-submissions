class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int total = n + m;
        int mid1 = total / 2;
        int mid2 = (total % 2 == 0) ? mid1 - 1 : mid1;
        
        int i = 0, j = 0, count = 0;
        int median1 = 0, median2 = 0;

        while (count <= mid1) {
            int val;
            if (i < n && (j >= m || nums1[i] < nums2[j])) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }

            if (count == mid2) median1 = val;
            if (count == mid1) median2 = val;

            count++;
        }

        if (total % 2 == 0) return (median1 + median2) / 2.0;
        return median2;
    }
};