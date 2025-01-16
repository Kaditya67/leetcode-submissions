class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // map<int,int>M,M1;
        // for(int i=0;i<Nums1.size();i++)
        // {
        //     M[Nums1[i]]++;
        //     // M1[Nums2[i]]++
        // }
        // for(int i=0;i<Nums2.size();i++)
        // {
        //     // M[Nums1[i]]++;
        //     M1[Nums2[i]]++;
        // }
        // vector<int>nums1,nums2;
        // for(auto it : M)
        // {
        //     nums1.push_back(it.first);
        // }
        // for(auto it : M1)
        // {
        //     nums2.push_back(it.first);
        // }
        int sz=nums1.size();
        int sz1=nums2.size();
        if(sz%2==0 && sz1%2==0)
        {
            return 0;
        }
        if(sz%2==1 && sz1%2==0)
        {
            int P=0;
            for(int i=0;i<nums2.size();i++)
            {
                P=(P^nums2[i]);
            }
            return P;
        }
        if(sz%2==0 && sz1%2==1)
        {
            int P=0;
            for(int i=0;i<nums1.size();i++)
            {
                P=(P^nums1[i]);
            }
            return P;
        }
        int P=0;
        for(int i=0;i<nums1.size();i++)
        {
            P=(P^nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            P=(P^nums2[i]);
        }
        return P;
    }
};