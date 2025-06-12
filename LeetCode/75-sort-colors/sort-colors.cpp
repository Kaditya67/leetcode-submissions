class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l0=0,mid1=0,h2=n-1;
        while(mid1<=h2){
            if(nums[mid1]==0){
                swap(nums[l0++],nums[mid1++]);
            }else if(nums[mid1]==2){
                swap(nums[h2--],nums[mid1]);
            }else{
                mid1++;
            }
        }
    }
};