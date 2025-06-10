class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0;
        int candidate1=-2,candidate2=-1;
        vector<int>res;
        int n = nums.size();
        int threshold = n/3;
        for(int &num:nums){
            if(count1==0 && num!=candidate2){
                count1++;
                candidate1=num;
            }
            else if(count2==0 && num!=candidate1){
                count2++;
                candidate2=num;
            }
            else if(num==candidate1){
                count1++;
            }
            else if(num==candidate2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        // Now we have all good elements stored in candidate variables
        // Count the real number of occurrences of the candidate

        count1=0,count2=0;
        for(int &num:nums){
            if(num==candidate1) count1++;
            else if(num==candidate2) count2++;
        }

        if(count1>threshold) res.push_back(candidate1);
        if(count2>threshold) res.push_back(candidate2);
        return res;
    }
};