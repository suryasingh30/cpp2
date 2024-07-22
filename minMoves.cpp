#include<bits/stdc++.h>
using namespace std;

int minMoves(vector<int>& nums){

    int mini = nums[0];
    for(auto it : nums)
        mini = min(mini, it);

    int count = 0;
    for(auto it : nums)
    {
        count += it - mini;
    }
    
return count < 0 ? count*-1 : count;
}

int main(){


return 0;
}
