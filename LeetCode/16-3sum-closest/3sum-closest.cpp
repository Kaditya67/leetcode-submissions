class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int res=nums[0] + nums[1] + nums[2];
        int min_diff=INT_MAX;
        for(int i=0;i<n-2;i++){
            int l = i+1, r=n-1; // left,right

            while(l<r){
                int curr_sum = nums[i]+nums[l]+nums[r];
                int curr_diff = abs(curr_sum-target);

                if(curr_diff < min_diff){
                    // result 
                    min_diff = curr_diff;
                    res = curr_sum;
                }
                if(curr_sum < target){
                    // more sum needed
                    l++;
                }else{
                    // little smaller
                    r--;
                }
            }
        }
        return res;
    }
};