class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n, 0);

        // calculate prefixSum
        int count = 0;
        for (int i = 0; i < n; ++i) {
            string& word = words[i];
            int m = word.size();
            if ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' ||
                 word[0] == 'o' || word[0] == 'u') &&
                (word[m - 1] == 'a' || word[m - 1] == 'e' ||
                 word[m - 1] == 'i' || word[m - 1] == 'o' ||
                 word[m - 1] == 'u')) { 
                count++;
            }
            prefixSum[i] = count;
        }

        // resolve queries
        int m = queries.size();
        vector<int> result(m); 
        for (int i = 0; i < m; ++i) {
            int leftIdx = queries[i][0];
            int rightIdx = queries[i][1];
            if (leftIdx == 0) {
                result[i] = prefixSum[rightIdx];
            } else {
                result[i] = prefixSum[rightIdx] - prefixSum[leftIdx - 1];  
            }
        }
        return result;
    }
};
