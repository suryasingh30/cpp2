#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits){
        
    int n = fruits.size();
    int start = 0;
    int end = 0;
    unordered_map<int,int> ourmap;
    int maxi = 0;

    for(start=0; start<n; start++)
    {
        ourmap[fruits[start]]++;
        if(ourmap.size() > 2)
        {
            maxi = max(maxi, start - end);
            while(ourmap.size() >= 2)
            {
                cout<<start<<" ";
                ourmap[fruits[end]]--;
                if(ourmap[fruits[end]] == 0)
                    ourmap.erase(fruits[end]);
                end++;
            }
        }
    }
return maxi;
}

int main(){



return 0;
}