class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int>st;

        for (int i = 0; i < 2 * n; i++) {
            int actualIdx = i % n;
            while (!st.empty() && nums[st.top()] < nums[actualIdx]) {
                res[st.top()] = nums[actualIdx];
                st.pop();
            }
            if (i < n) st.push(actualIdx);
        }
        return res;
    }
};