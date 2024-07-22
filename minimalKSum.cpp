#include<bits/stdc++.h>
using namespace std;

long long minimalKSum(vector<int>& nums, int k){

    // sort(nums.begin(), nums.end());
    int maxi = 0;
    // int num = 1;
    long long sum = 0;
    unordered_set<int> st;

    for(auto it : nums)
    {
        st.insert(it);
        maxi = max(maxi, it);
    }
    for(int i=1; i<maxi*k; i++)
    {
        if(k == 0)
            return sum;
        else
        {
            if(st.find(i) == st.end())
            {
                k--;
                sum += i;
            }
        }
    }
return sum;
}

int main(){



return 0;
}
