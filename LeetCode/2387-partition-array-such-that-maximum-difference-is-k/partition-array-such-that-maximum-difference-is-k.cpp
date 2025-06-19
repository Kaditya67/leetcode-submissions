class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int j=0,i=0;
        int n = nums.size();
        int res = 0;
        while(i<n){
            if((nums[i]-nums[j])<=k){
                i++;
            }else{
                res++;
                j=i;
            }
        }
        return res+1;
    }
};