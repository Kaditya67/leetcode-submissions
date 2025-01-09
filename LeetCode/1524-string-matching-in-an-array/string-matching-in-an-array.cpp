class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> result;
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(words[i].size() > words[j].size()) continue;
                if(words[j].find(words[i]) != string::npos){
                    result.insert(words[i]);
                }
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};