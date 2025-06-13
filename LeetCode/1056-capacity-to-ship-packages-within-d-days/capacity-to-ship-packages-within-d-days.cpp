class Solution {
public:
    bool isPossible(vector<int> &weights, int mid,int days,int n){
        int count=1;
        int sum=0;
        for(int &w:weights){
            sum+=w;
            if(sum>mid){
                sum = w;
                count++;
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        if(n < days)
            return -1; //not possible case

        int l = *max_element(begin(weights), end(weights));
        int r = accumulate(begin(weights),end(weights),0);      // minimum wight

        if(days == 1)
            return r;

        while(l<r){
            int mid = l+(r-l)/2;

            if(isPossible(weights,mid,days,n)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};