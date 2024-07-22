#include<bits/stdc++.h>
using namespace std;

int prefixSum(vector<vector<int>>& grid, pair<int,int> start, pair<int,int> end){

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> prefixSum(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            prefixSum[i][j] = grid[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1]; 
        }
    }

    int a = start.first, b = start.second;
    int c = end.first, d = end.second;

    int sum = prefixSum[c+1][d+1] - prefixSum[a][d-1] - prefixSum[c+1][b] + prefixSum[a][b];

return sum;
}

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Prefix sums for 'X' and 'Y'
        vector<vector<int>> prefixX(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> prefixY(n + 1, vector<int>(m + 1, 0));

        // Compute the prefix sums
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prefixX[i][j] = prefixX[i - 1][j] + prefixX[i][j - 1] - prefixX[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X' ? 1 : 0);
                prefixY[i][j] = prefixY[i - 1][j] + prefixY[i][j - 1] - prefixY[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
            }
        }

        int count = 0;

        // Iterate over all possible submatrices
        for (int r1 = 0; r1 < n; ++r1) {
            for (int r2 = r1; r2 < n; ++r2) {
                for (int c1 = 0; c1 < m; ++c1) { 
                    for (int c2 = c1; c2 < m; ++c2) {
                        int totalX = prefixX[r2 + 1][c2 + 1] - prefixX[r1][c2 + 1] - prefixX[r2 + 1][c1] + prefixX[r1][c1];
                        int totalY = prefixY[r2 + 1][c2 + 1] - prefixY[r1][c2 + 1] - prefixY[r2 + 1][c1] + prefixY[r1][c1];
                        if (totalX == totalY) {
                            ++count;
                        }
                    }
                }
            }
        }

        return count;
    }
};


int main(){



return 0;
}

