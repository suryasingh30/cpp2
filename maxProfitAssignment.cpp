#include<bits/stdc++.h>
using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    
    vector<pair<int,int>> ourmap;
    for(int i=0; i<profit.size(); i++)
        ourmap.push_back({profit[i], difficulty[i]});

    sort(ourmap.begin(), ourmap.end());

    int ans = 0;
    for(auto work : worker)
    {
        for(auto diff : ourmap)
        {
            if(work >= diff.second)
            {
                ans += diff.first;
                break;
            }
        }
    }

return ans;
}

int main(){

    

return 0;
}