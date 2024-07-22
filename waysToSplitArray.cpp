#include<bits/stdc++.h>
using namespace std;

int waysToSplitArray(vector<int>& nums){
        
    int totalSum = 0;
    for(auto it : nums)
        totalSum += it;

    int count = 0;
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
    {
        sum += nums[i];
        if(sum >= totalSum-sum)
            count++;
    }
return count;
}