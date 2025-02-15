class Solution {
public:
    bool isPartitionEqualToNum(int sqr, int target) {
        if (sqr == target) return true;
        if (sqr < target || target < 0) return false;

        return isPartitionEqualToNum(sqr / 10, target - sqr % 10) || 
               isPartitionEqualToNum(sqr / 100, target - sqr % 100) || 
               isPartitionEqualToNum(sqr / 1000, target - sqr % 1000);
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int sqr = i * i;
            if (isPartitionEqualToNum(sqr, i)) {
                sum += sqr;
            }
        }
        return sum;
    }
};
