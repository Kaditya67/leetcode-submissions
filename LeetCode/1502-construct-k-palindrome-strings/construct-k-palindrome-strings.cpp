class Solution {
public:
    bool canConstruct(string s, int k) {
        // 1 Possibility
        // construct tree and form all possible patterns and count until we get the desired number of palindromes
        //  O(n^n)  --> not possible


        // 2nd Possibility
        // we only need to calculate number of palindromes
        // vector ---> count   ---> frequency

        // "leetcode"
        // l -> 1
        // e -> 3
        // t -> 1
        // c -> 1
        // o -> 1
        // d -> 1

        // 6 characters have odd count
        
        // "annabelle"
        // a -> 2
        // n -> 2
        // b -> 1
        // e -> 2
        // l -> 2

        // 1 character has odd count
        // 1 < k        // palindrome syrings can be formed

        if(s.size()<k) return false;
        vector<int> freq(26,0);

        for(char &ch:s){
            freq[ch-'a']++;
        }

        int count=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            if(freq[i]%2 != 0){
                count++;
            }
        }

        if(count>k) return false;
        return true;
    }
};
