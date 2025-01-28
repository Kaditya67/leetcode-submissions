#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    int countFishes(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int numRows = grid.size(), numCols = grid[0].size(), fishCount = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        vector<int> rowDirections = {0, 0, 1, -1};
        vector<int> colDirections = {1, -1, 0, 0};

        while (!q.empty()) {
            int curRow = q.front().first, curCol = q.front().second;
            q.pop();
            fishCount += grid[curRow][curCol];

            for (int i = 0; i < 4; i++) {
                int newRow = curRow + rowDirections[i], newCol = curCol + colDirections[i];
                if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols &&
                    grid[newRow][newCol] > 0 && !visited[newRow][newCol]) {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
        return fishCount;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), result = 0;
        vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    result = max(result, countFishes(grid, visited, i, j));
                }
            }
        }
        return result;
    }
};
