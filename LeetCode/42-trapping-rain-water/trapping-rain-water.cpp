class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        int rightMax=0,leftMax=0;
        int left=0,right = n-1;
        int waterTrapped=0;

        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=leftMax){
                    leftMax = height[left];
                }else{
                    waterTrapped+=leftMax - height[left];
                }
                ++left;
            }else{
                if(height[right]>=rightMax){
                    rightMax = height[right];
                }else{
                    waterTrapped+=rightMax - height[right];
                }
                --right;
            }
        }
        return waterTrapped;
    }
};