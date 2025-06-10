class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int &num:nums){
            mp[num]++;
        }

        vector<int> result;
        int threshold = n/3;
        for(auto &e:mp){
            if(e.second > threshold){
                result.push_back(e.first);
            }
        }
        return result;
    }
};