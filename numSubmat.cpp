#include<bits/stdc++.h>
using namespace std;

int numSubmat(vector<vector<int>>& mat){
    
    int n = mat.size();
    int m=mat[0].size();
    vector<vector<int>> pf(n+1, vector<int>(m+1, 0));
    int count = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(mat[i-1][j-1] == 1)
            {
                if(pf[i-1][j] != 0 || pf[i][j-1] != 0)
                {
                    pf[i][j] = 1+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
                }
                else
                {
                    pf[i][j] = 1;
                }
                count += pf[i][j];
            }
        }
    }

return count;
}


int minChanges(vector<int>& nums, int k){
        
    int n = nums.size();
    set<int> diff;

    for(int i=0 ;i<n/2; i++)
    {
        diff.insert(abs(nums[i] - nums[n - i - 1]));
    }

    int mini = INT_MAX;
    for(auto d : diff)
    {
        // int d = diff[i];
        int count = 0;
        for(int j=0; j<n/2; j++)
        {
            // if(j == i)
                // continue;

            int a = nums[j];
            int b = nums[n - j - 1];

            if (abs(a - b) != d) 
            {
                // Check if we can change a or b to make the difference diff
                int t = abs(a-b);
                bool canBeMade = false;
                for(int x=0; x<=k; x++)
                {
                    if(abs(x-b) == d || abs(x-a) == d)
                    {
                        count++;
                        canBeMade = true;
                        break;
                    }
                }
                if(!canBeMade)
                {
                    if(t <= k)
                    {
                        count+=2;
                    }
                    else
                        break;
                }
                if(count >= mini)
                    break;
            }
        }
        mini = min(mini, count);
    }

return mini;
}

int main(){



return 0;
}