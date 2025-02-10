class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(char &ch:s){
            if(isalpha(ch)){
                st.push(ch);
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }

        string res="";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            res = ch+res;
        }
        return res;
    }
};