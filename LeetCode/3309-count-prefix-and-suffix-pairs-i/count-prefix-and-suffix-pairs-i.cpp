class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++){
                string& word1 = words[i];
                string& word2 = words[j];
                if(word1.size()>word2.size()) continue;  // skip the same word

                if(word2.find(word1) == 0 && word2.rfind(word1)== word2.size()-word1.size()){
                    ++count;
                }
            }
        }
        return count;
    }
};