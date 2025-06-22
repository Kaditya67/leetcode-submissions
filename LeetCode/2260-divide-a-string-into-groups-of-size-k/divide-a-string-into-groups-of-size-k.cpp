class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> res;

        for (int i = 0; i < n; i += k) {
            string chunk = s.substr(i, k);
            if (chunk.size() < k) {
                chunk.append(k - chunk.size(), fill);
            }
            res.push_back(chunk);
        }

        return res;
    }
};
