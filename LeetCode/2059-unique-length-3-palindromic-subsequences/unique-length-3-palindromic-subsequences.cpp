class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstCharIdx(26,-1);
        vector<int> lastCharIdx(26,-1);

        int n = s.size();
        for(int i=0;i<n;i++){
            int currIdx = s[i]-'a';
            if(firstCharIdx[currIdx] == -1){
                firstCharIdx[currIdx] = i;
            }
            lastCharIdx[currIdx] = i;
        }

        int resCnt = 0;
        for(int i=0;i<26;i++){
            if(firstCharIdx[i]==-1){        // if character is not present -> skip
                continue;
            }
            
            // count all between characters
            unordered_set<char> btw;
            for(int j=firstCharIdx[i]+1;j<lastCharIdx[i];j++){
                btw.insert(s[j]);
            }
            
            resCnt+=btw.size();    
        }
        return resCnt;
    }
};