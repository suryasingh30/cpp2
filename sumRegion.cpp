#include<bits/stdc++.h>
using namespace std;

// NumMatrix(vector<vector<int>>& matrix) {
        
//     }
    
// int sumRegion(int row1, int col1, int row2, int col2) {
    
// }

int pivotIndex(vector<int>& nums){
        
    int totalSum = 0;
    for(auto it : nums)
        totalSum += it;

    int sum = 0;
    for(int i=0; i<nums.size(); i++)
    {   
        int left = sum;
        int right = totalSum - sum - nums[i];
        if(left == right)
            return i;
        sum += nums[i]; 
    }
return -1;
}

