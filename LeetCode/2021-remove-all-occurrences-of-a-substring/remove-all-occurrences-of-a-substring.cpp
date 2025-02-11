class Solution {
public:
    vector<int> lpsarr(string &part){
        int i = 1;
        int len = 0;
        int m = part.size();
        vector<int> lps(m,0);
        while(i<m){
            if(part[i]==part[len]){
                lps[i++] = ++len;
            }
            else if(len>0){
                len = lps[len-1];
            }
            else{
                lps[i++] = 0;
            }
        }
        return lps;
    }
    int KMP(string s, string part,vector<int> &lps) {
        int m = part.size();
        int n = s.size();
        int i = 0,j = 0;
        while(i<n){
            if(s[i]==part[j]){
                i++;
                j++;
                if(j == m) return i - m;
            }
            else if(j>0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
        return -1;
    }
    string removeOccurrences(string s, string part){
        vector<int> lps = lpsarr(part);
        while(true){
            int pos = KMP(s,part,lps);
            if(pos == -1) break;
            s.erase(pos,part.size());
        }
        return s;
    }
};