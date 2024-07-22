#include<bits/stdc++.h>
using namespace std;

int calculate(vector<vector<pair<int,int>>>& ourmap, pair<int,int> start){

    int sum = start.first;
    int index = start.second;
    int n = ourmap.size();

    for(int i=1; i<n; i++)
    {
        if(ourmap[i][0].second != index)
        {
            sum += ourmap[i][0].first;
            index = ourmap[i][0].second;
        }
        else
        {
            sum += ourmap[i][1].first;
            index = ourmap[i][1].second;
        }
    }
return sum;
}

int recursion(int i, int n, int minValue, int index, vector<vector<pair<int,int>>>& ourmap){

    if(i == n)
        return 0;

    int left = 1e9;
    int right = 1e9;

    if(index != ourmap[i][0].second)
    {
        left = recursion(i+1, n, minValue+ourmap[i][0].first, ourmap[i][0].second, ourmap);
    }
    if(index != ourmap[i][1].second)
    {
        right = recursion(i+1, n, minValue+ourmap[i][1].first, ourmap[i][1].second, ourmap);
    }

return min(left, right);
}

int minFallingPathSum(vector<vector<int>>& grid){
    
    vector<vector<pair<int,int>>> ourmap;
    int n = grid.size();

    for(int i=0; i<n; i++)
    {
        pair<int,int> min1 = {1e9, -1}, min2 = {1e9, -1};
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] < min1.first)
            {
                min1 = {grid[i][j], j};
                min2 = min1;
            }
        }
        ourmap.push_back({min1, min2});
    }

    // int ans = max(calculate(ourmap, ourmap[0][0]), calculate(ourmap, ourmap[0][1]));
    int ans1 = recursion(1, n, ourmap[0][0].first, ourmap[0][0].second, ourmap);
    int ans2 = recursion(1, n, ourmap[0][1].first, ourmap[0][1].second, ourmap);

return min(ans1, ans2); 
}

int main(){

    unordered_set<int> st;


return 0;
}