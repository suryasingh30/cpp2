#include<bits/stdc++.h>
using namespace std;

vector<long long> findPrefixScore(vector<int>& nums){
        
    int maxi = 0;
    long long prefixSum = 0;
    vector<long long> ans;

    for(int i=0; i<nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
        prefixSum += maxi + nums[i];
        ans.push_back(prefixSum);
    }
return ans;
}