class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry =0;
        string res;
        while(i>=0 or j>=0 or carry){
            int n1 = i>=0 ? num1[i]-'0' : 0;
            int n2 = j>=0 ? num2[j]-'0' : 0;

            int sum  = n1+n2+carry;
            carry = sum/10;     // Get carry from tens place
            res += (sum%10)+'0';    // Store remainder from unit place
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};