#include<bits/stdc++.h>
using namespace std;

int recursion(int index, vector<int>& nums, int k, int prev){

    if(index >= nums.size())
        return 0;

    int take = 0;
    if(prev == -1)
    {
        take = 1 + recursion(index+1, nums, k, nums[index]); 
    }
    else if(prev != nums[index] && k > 0)
    {
        take = 1 + recursion(index+1, nums, k-1, nums[index]);
    }
    int notTake = recursion(index+1, nums, k, prev);

return max(take, notTake);
}

int cnt(int index, vector<int>& nums, int k){

    int count = 1;
    int prev = nums[index];
    for(int i=index+1; i<nums.size(); i++)
    {
        if(k == 0)
        {
            count++;
        }
        else if(prev != nums[i])
        {
            count++;
            prev = nums[i];
            k--;
        }
    }
return count;
}

int maximumLength(vector<int>& nums, int k) {

    int maxi = 0;
    for(int i=0; i<nums.size(); i++)
    {
        int ans = cnt(i, nums, k);
        maxi = max(maxi, ans);
    }
return maxi;
}

int recursion(int index, vector<int>& nums, int k, int prev){

    if(index >= nums.size())
        return 0;

    int take = 0;
    if(prev == -1)
    {
        take = 1 + recursion(index+1, nums, k, nums[index]); 
    }
    else if(prev != nums[index] && k > 0)
    {
        take = 1 + recursion(index+1, nums, k-1, nums[index]);
    }
    else if(prev == nums[index])
    {
        take = 1 + recursion(index+1, nums, k, nums[index]);
    }
    int notTake = recursion(index+1, nums, k, prev);

return max(take, notTake);
}
    int maximumLength(vector<int>& nums, int k) {
        
    int ans = recursion(0,  nums, k, -1);
    return ans;
    }






int recursion(int index, vector<int>& arr, int x){

    if(index >= arr.size())
        return 0;

    int take = 0;
    if(arr[index] > x)
    {
        take = arr[index] + recursion(index+1, arr, x+arr[index]);
    }
    
    int notTake = 0;
    notTake = 0 + recursion(index+1, arr, x);

return max(take, notTake);
}

int memo(int index, vector<int>& arr, vector<int>& vis, int x, vector<vector<vector<int>>>& dp){

    if(index >= arr.size())
        return 0;

    if(dp[index][x][vis[index]] != -1)
        return dp[index][x][vis[index]];

    int take = 0;
    if(vis[index] == 0 && arr[index] > x)
    {
        vis[index] = 1;
        take = arr[index] + memo(index+1, arr, vis, x+arr[index], dp);
    }
    vis[index] = 1;
    int notTake = 0;
    notTake = 0 + memo(index+1, arr, vis, x, dp);

    dp[index][x][vis[index]] = max(take, notTake);

return dp[index][x][vis[index]];
}

int maxTotalReward(vector<int>& rewardValues){

    int n = rewardValues.size();
    int x = 0;
    sort(rewardValues.begin(), rewardValues.end());
    vector<int> vis(rewardValues.size(), 0);
    for(auto it : rewardValues)
        x += it;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(x, vector<int>(3, -1)));

    int ans = memo(0, rewardValues, vis, 0, dp);

return ans;
}

int solve(vector<int>& arr){

    int maxi = 0;
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++)
    {
        int sum = arr[i];
        for(int j=i+1; j<n; j++)
        {
            if(sum < arr[j])
                sum += arr[j];
        }
        maxi = max(maxi, sum);
    }
return maxi;
}


