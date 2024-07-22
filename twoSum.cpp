#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target){
        
    int i = 0;
    int j = numbers.size()-1;

    while(i<j)
    {
        int sum = numbers[i]+numbers[j];
        if(sum == target)
            return {i+1, j+1};
        else if(sum < target)
            i++;
        else if(sum > target)
            j--;
    }
return {};
}

int main(){



return 0;
}