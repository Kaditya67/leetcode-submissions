class Solution {
public:
    vector<int> ch = vector<int>(3, 0); 

    bool isValid() {
        int cnt = 0;
        for (int num : ch) {
            if (num > 0) cnt++;
        }
        return cnt == 3; 
    }

    int numberOfSubstrings(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            ch[s[j] - 'a']++; 
            
            while (isValid()) { 
                ans += n - j; 
                ch[s[i] - 'a']--; 
                i++; 
            }

            j++; 
        }
        
        return ans;
    }
};
