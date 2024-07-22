#include<bits/stdc++.h>
using namespace std;

int minMoves2(vector<int>& nums) {
    
    int n = nums.size();
    int index = (n-1)/2;
    int count = 0;

    sort(nums.begin(), nums.end());
    int mini = nums[index];

    for(int i=0; i<index; i++)
    {
        count += ((nums[i] - mini) * -1);
    }

    for(int j=index+1; j<n; j++)
    {
        count += nums[j] - mini;
    }

return count;
}

int main(){



return 0;
}