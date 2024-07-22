#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums, int x){
        
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    int count = 0;

    while(n > 0 && i < j && x > 0)
    {
        if(nums[i] <= x)
        {
            if(nums[j] < x)
            {
                if(nums[i] > nums[j])
                {
                    x -= nums[i];
                    count++;
                    i++;
                }
                else
                {
                    x -= nums[j];
                    count++;
                    j--;
                }
            }
            else
            {
                x -= nums[i];
                count++;
                i++;
            }
        }
        else if(nums[j] <= x)
        {
            x -= nums[j];
            count++;
            j--;
        }
    }

return x == 0 ? count : -1;
}

int main(){



return 0;
}