#include<bits/stdc++.h>
using namespace std;

int numberOfSubmatrices(vector<vector<char>>& grid){
        
    int countX = 0, countY = 0;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<pair<int,int>>> prefixSum(n+1, vector<pair<int,int>>(m+1, {0,0}));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(grid[i-1][j-1] == 'X')
            {
                prefixSum[i][j] = {1+prefixSum[i-1][j].first+prefixSum[i][j-1].first-prefixSum[i-1][j-1].first, 
                                    prefixSum[i-1][j].second+prefixSum[i][j-1].second-prefixSum[i-1][j-1].second};
            }
            if(grid[i-1][j-1] == 'Y')
            {
                prefixSum[i][j] = {prefixSum[i-1][j].first+prefixSum[i][j-1].first-prefixSum[i-1][j-1].first, 
                                   1+prefixSum[i-1][j].second+prefixSum[i][j-1].second-prefixSum[i-1][j-1].second};
            }
        }
    }

    int count = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(prefixSum[i][j].first > 0 && prefixSum[i][j].first == prefixSum[i][j].second)
                count++;
        }
    }

return count;
}

int main(){



return 0;
}