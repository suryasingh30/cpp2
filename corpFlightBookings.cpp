#include<bits/stdc++.h>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n){
        
    vector<int> ans(n, 0);

    for(auto book : bookings)
    {
        for(int i=book[0]; i<=book[1]; i++)
        {
            ans[i-1] += book[2];
        }
    }

return ans;
}


vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n){
        
    vector<int> ans(n+1, 0);

    for(auto it : bookings)
    {
        ans[it[0]-1] += it[2];
        ans[it[1]] -= it[2];
    }

    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += ans[i];
        ans[i] = sum;
    }
    ans.pop_back();

return ans;
}

