class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum=0;
        int n = nums.size();
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                sum+=nums[i];
            }else{ 
                maxSum = max(maxSum,sum);
                sum=nums[i];
            }

        }

        return max(maxSum,sum);;
    }
};