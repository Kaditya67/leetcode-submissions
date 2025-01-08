class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArr(n + 1, 0);  
        
        for (const auto& shift : shifts) {
            int startIdx = shift[0];
            int endIdx = shift[1];
            int direction = shift[2];
            
            if (direction == 1) {
                ++diffArr[startIdx];
                if (endIdx + 1 < n) --diffArr[endIdx + 1];
            } else {
                --diffArr[startIdx];
                if (endIdx + 1 < n) ++diffArr[endIdx + 1];
            }
        }

        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += diffArr[i];
            int shift = (s[i] - 'a' + cumulativeShift) % 26;
            if (shift < 0) shift += 26; 
            s[i] = 'a' + shift;
        }
        
        return s;
    }
};
