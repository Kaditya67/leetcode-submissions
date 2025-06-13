class Solution {
public:
    bool isAnswer(vector<int> &nums, int mid,int p,int n){
        int count=0;
        int i=1;
        while(i<n){
            if((nums[i]-nums[i-1])<=mid){
                count++;
                i++;
            }
            i++;
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l=0;
        int r = nums[n-1]-nums[0];

        int ans=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isAnswer(nums,mid,p,n)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};