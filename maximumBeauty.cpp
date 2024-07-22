#include<bits/stdc++.h>
using namespace std;

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries){

    int maxi = 0;
    sort(items.begin(), items.end());

    for(int i=0; i<items.size(); i++)
    {
        maxi = max(maxi, items[i][1]);
        items[i][1] = maxi;
    }

    vector<int> prices;
    for(auto it : items)
        prices.push_back(it[0]);

    vector<int> ans;
    for(auto it : queries)
    {
        auto index = upper_bound(prices.begin(), prices.end(), it);
        if(index == prices.begin())
            ans.push_back(0);
        else
            ans.push_back(items[index - prices.begin() - 1][1]);
    }

return ans;
}