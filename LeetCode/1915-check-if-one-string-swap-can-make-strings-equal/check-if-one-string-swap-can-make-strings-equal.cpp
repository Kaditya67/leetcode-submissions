class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.size(); 
        vector<int> vec;

        for(int i = 0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(vec.size()>2){
                    return false;
                }
                vec.push_back(i);
            }
        }
        if(vec.size()==2){
            swap(s2[vec[0]],s2[vec[1]]);
        }
        return s1==s2;

    }
};