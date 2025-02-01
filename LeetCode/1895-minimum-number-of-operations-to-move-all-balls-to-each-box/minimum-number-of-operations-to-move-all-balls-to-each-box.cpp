class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);

        int count = 0, moves = 0;
        // Left to Right Pass
        for (int i = 0; i < n; i++) {
            result[i] += moves;
            if (boxes[i] == '1') count++;
            moves += count;
        }

        count = 0, moves = 0;
        // Right to Left Pass
        for (int i = n - 1; i >= 0; i--) {
            result[i] += moves;
            if (boxes[i] == '1') count++;
            moves += count;
        }

        return result;
    }
};
