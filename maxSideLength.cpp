#include<bits/stdc++.h>
using namespace std;

int maxSideLength(vector<vector<int>>& mat, int threshold){
        
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp = mat;

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];     
        }
    }

    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}

    sums = [
    [0, 0, 0, 0],
    [0, 1, 3, 6],
    [0, 5, 12, 21],
    [0, 12, 27, 45]
]

}