#include<bits/stdc++.h>
using namespace std;

int waysToMakeFair(vector<int>& nums){

    int n = nums.size();
    vector<pair<int,int>> ans(n, {0,0});

    int even=0, odd=0;
    for(int i=1; i<nums.size(); i++)
    {
        if(i-1 % 2 == 0)
            even += nums[i];
        else
            odd += nums[i];
    }

    if(odd == even)
        return 0;

    ans[0] = {odd, even};
    for(int i=1; i<nums.size(); i++)
    {
        odd = ans[i-1].second;
        even = ans[i-1].first - nums[i] + nums[i-1];
        ans[i] = {odd, even};
        if(odd == even)
            return i;
    }
return -1;
}