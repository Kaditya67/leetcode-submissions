class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int score = 0;
        for(int i=0;i<n-1;i++){
            int left = 0;
            int right = 0;
            string leftWord = s.substr(0,i+1);
            string rightWord = s.substr(i+1,n-i);
            for(char c:leftWord){
                if(c=='0'){
                    left++;
                }
            }
            for(char c:rightWord){
                if(c=='1'){
                    right++;
                }
            }
            score = max(score,left+right);
        }
        return score;
    }
};