class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26);  // Store last index of each character
        vector<bool> inStack(26, false);  // Track what's in the stack
        stack<char> st;

        // Record last occurrence of each character
        for (int i = 0; i < s.size(); ++i)
            lastIndex[s[i] - 'a'] = i;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            int idx = c - 'a';

            if (inStack[idx]) continue;

            // Maintain monotonic increasing stack
            while (!st.empty() && c < st.top() && lastIndex[st.top() - 'a'] > i) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[idx] = true;
        }

        // Build final result from stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
