class Solution {
public:
    bool canEatAll(vector<int>&piles,int mid,int h){
        int actualHours = 0;
        for(int &x:piles){
            actualHours+=x/mid;

            if(x%mid!=0){
                actualHours++;
            }
        }
        return actualHours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());

        while(left<right){
            int mid = left+(right-left)/2;
            if(canEatAll(piles,mid,h)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};