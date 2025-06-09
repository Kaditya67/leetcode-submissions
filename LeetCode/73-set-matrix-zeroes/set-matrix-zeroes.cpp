class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool rowInfected = false;
        bool colInfected = false;

        // Check if the first row is infected
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) {
                rowInfected = true;
                break;
            }
        }

        // Check if the first column is infected
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                colInfected = true;
                break;
            }
        }

        // Use first row and column as markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeroes based on markers
        for(int i = 1; i < m; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j = 1; j < n; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Finally, handle the first row and column
        if(rowInfected) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if(colInfected) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
