class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int score = 0; 
        int countOne=0;
        for(char &c:s){
            if(c=='1'){
                countOne++;
            }
        }

        int countZero=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                countZero++;
            }else{
                countOne--;
            }
            score = max(score,countZero+countOne);
        }

        return score;
    }
};