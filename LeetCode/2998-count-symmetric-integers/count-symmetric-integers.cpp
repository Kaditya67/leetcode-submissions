class Solution {
public:
    int getLength(int num){
        int len=0;
        while(num>0){
            len++;
            num/=10;
        }
        return len;
    }
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int num = low; num <= high; num++){
            int len = getLength(num);
            if(len%2!=0) continue;
            string s = to_string(num);
            int half = len / 2;
            int leftSum = 0, rightSum = 0;

            for (int i = 0; i < half; i++)
                leftSum += s[i] - '0';
            for (int i = half; i < len; i++)
                rightSum += s[i] - '0';

            if (leftSum == rightSum)
                count++;
        }
        return count;
    }
};