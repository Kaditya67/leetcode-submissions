class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        vector<int> result;
        int n = A.size();
        int count=0;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;

            if(A[i]==B[i]){
                count++;
                result.push_back(count);
                continue;
            }
            if(mp[A[i]]>1){
                count++;
            }

            if(mp[B[i]]>1){
                count++;
            }
            result.push_back(count);
        }
        return result;
    }
};