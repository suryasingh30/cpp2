#include<bits/stdc++.h>
using namespace std;

vector<int> getStrongest(vector<int>& arr, int k) {

    int n = arr.size();
    vector<int> temp = arr;
    vector<pair<int,int>> strongest(n);
    sort(temp.begin(), temp.end());
    int m = temp[((n-1)/2)];

    for(int i=0; i<n; i++)
    {
        strongest[i] = {abs(arr[i] - m), arr[i]};
        cout<<strongest[i].first<<" "<<strongest[i].second<<endl;
    }

    sort(strongest.begin(), strongest.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    });

    for(int i=0; i<n; i++)
    {
        cout<<strongest[i].first<<" "<<strongest[i].second<<endl;
    }

    temp.clear();
    for(int i=0; i<k; i++)
    {
        temp.push_back(strongest[i].second);
    }

return temp;
}