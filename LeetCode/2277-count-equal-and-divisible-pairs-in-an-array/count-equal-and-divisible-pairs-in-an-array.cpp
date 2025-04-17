class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((i*j)%k!=0) continue;

                if(nums[i]==nums[j]) result++;
            }
        }
        return result;
    }
};