class Solution {
public:
    int splitNum(int num) {
        vector<int> digits;
        
        // Extract digits
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        // Sort digits in ascending order
        sort(digits.begin(), digits.end());

        int num1 = 0, num2 = 0;

        // Distribute digits alternately
        for (int i = 0; i < digits.size(); i++) {
            if (i % 2 == 0) {
                num1 = num1 * 10 + digits[i];  // Append to num1
            } else {
                num2 = num2 * 10 + digits[i];  // Append to num2
            }
        }

        return num1 + num2;
    }
};
