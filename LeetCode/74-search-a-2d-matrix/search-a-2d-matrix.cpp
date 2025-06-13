class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int l = 0, h = r - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) h = mid - 1;
            else l = mid + 1;
        }

        int row = l - 1;
        if (row < 0) return false;

        int L = 0, H = c - 1;
        while (L <= H) {
            int mid = L + (H - L) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) L = mid + 1;
            else H = mid - 1;
        }

        return false;
    }
};
