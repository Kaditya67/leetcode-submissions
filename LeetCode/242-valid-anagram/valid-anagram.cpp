class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> seen;
        for(char &c:s){
            seen[c]++;
        }

        // check if all found
        for(char &c : t){
            if(seen[c]>0){
                seen[c]--;
            }else{
                return false;
            }
        }

        for (auto& pair : seen) {
            if (pair.second != 0) {
                return false;
            }
        }
        return true;
    }
};