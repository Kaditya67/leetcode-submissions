class Solution {
public:
    int KadaneMax(vector<int>& arr) {
        int maxSum=INT_MIN;
        int currSum=0;

        for(int &num:arr){
            currSum = max(currSum+num,num);
            maxSum = max(currSum,maxSum);
        }
        return maxSum;
    }

    int KadaneMin(vector<int>& arr) {
        int minSum=INT_MAX;
        int currSum=0;

        for(int &num:arr){
            currSum = min(currSum+num,num);
            minSum = min(currSum,minSum);
        }
        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int Sum=0;
        for(int &num:nums){
            Sum+=num;
        }

        int maxSum = KadaneMax(nums);
        int minSum = KadaneMin(nums);
        int Circular_max = Sum - minSum;

        if(maxSum>0) return max(maxSum,Circular_max);
        return maxSum;
    }
};