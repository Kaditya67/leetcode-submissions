class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result;
        vector<int> freq(n+1,0);
        int count=0;
        for(int i=0;i<n;++i){
            ++freq[A[i]];
            ++freq[B[i]];

            if(A[i]==B[i]){
                ++count;
                result.push_back(count);
                continue;
            }
            if(freq[A[i]]>1){
                ++count;
            }

            if(freq[B[i]]>1){
                ++count;
            }
            result.push_back(count);
        }
        return result;
    }
};