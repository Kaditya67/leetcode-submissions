class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> result;
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        int n = words.size();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){ 
                if(words[i].size() > words[j].size()) continue;
                if(words[j].find(words[i]) != string::npos){
                    result.insert(words[i]);
                    break;
                }
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};