class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxVol=0;
        while(i<j){
            int dist = j-i;
            maxVol = max(maxVol, min(height[i],height[j])*dist);
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return maxVol;
    }
};