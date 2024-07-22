#include<bits/stdc++.h>
using namespace std;

vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2){
        
    int n = nums1.size();
    vector<pair<int,int>> Tnum2;
    vector<int> Tnum1 = nums1;
    for(int i=0; i<n; i++)
    {
        Tnum2.push_back({nums2[i], i});
    }

    sort(Tnum2.begin(), Tnum2.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    });
    sort(nums1.begin(), nums1.end());

    int j=0;

    for(int i=0; i<n; i++)
    {
        if(nums1[i] > Tnum2[j].first)
        {
            Tnum1[Tnum2[j].second] = nums1[i];
            i++;
        }
    }

return Tnum1;
}

int main(){



return 0;
}