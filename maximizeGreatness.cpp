#include<bits/stdc++.h>
using namespace std;

vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2){
        
    int n = nums1.size();
    // vector<int> temp = nums;
    sort(nums1.begin(), nums1.end());
    unordered_set<int> st;
    vector<int> ans;

    int count = 0;
    for(int i=0; i<n; i++)
    {
        int index = upper_bound(nums1.begin(), nums1.end(), nums2[i]) - nums1.begin();
        while(index < n)
        {
            if(st.find(index) == st.end())
            {
                count++;
                st.insert(index);
                ans.push_back(nums1[index]);
                break;
            }
            index++;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(st.find(i) == st.end())
            ans.push_back(nums1[i]);
    }

return ans;
}

int maximizeGreatness(vector<int>& nums){

    int n = nums.size();
    sort(nums.begin(), nums.end());
    int count = 0;
    int start=0, end=0;

    while(end < n)
    {
        if(nums[start] < nums[end])
        {
            count++;
            start++;
        }
        end++;
    }

return count;
}


int main(){



return 0;
}