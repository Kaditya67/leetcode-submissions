class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIdx(26);
        vector<bool> inStack(26, false);
        stack<char> st;

        int n = s.length();

        // Record the last occurrence of each character
        for (int i = 0; i < n; i++) {
            lastIdx[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if (inStack[idx]) continue;

            // Monotonic stack logic
            while (!st.empty() && ch < st.top() && lastIdx[st.top() - 'a'] > i) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            inStack[idx] = true;
        }

        // Build result from stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
