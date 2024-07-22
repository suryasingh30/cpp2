#include<bits/stdc++.h>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity){
        
    int n = 0;
    for(auto trip : trips)
        n = max(n, trip[2]);
    
    vector<int> ans(n+1, 0);

    for(auto trip : trips)
    {
        ans[trip[1]] += trip[0];
        ans[trip[2]+1] -= trip[0];
    }

    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += ans[i];
        if(sum > capacity)
            return false;
    }
return true;
}