class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int res = 1;
        int i=1;
        while(i<n){
            if(word[i]==word[i-1]){
                res+=1;
            }
            i++;
        }
        return res;
    }
};