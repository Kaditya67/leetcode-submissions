#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(nums.begin(), nums.end()); 
        int count = 0;

        while(pq.top()<k){
            long long x=pq.top(); pq.pop();
            long long y=pq.top(); pq.pop();
            pq.push(2*x+y);
            count++;
        }

        return (pq.top() >= k) ? count : -1; 
    }
};