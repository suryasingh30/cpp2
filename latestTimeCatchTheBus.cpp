#include<bits/stdc++.h>
using namespace std;

int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity){
        
    int n = buses.size();
    int m = passengers.size();
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());

    int last = 0;
    int i=0, j=0;
    unordered_set<int> st;

    while(i < n && j < m)
    {
        int cap = capacity;
        st.clear();
        while(j < m && cap > 0 && passengers[j] <= buses[i])
        {
            st.insert(passengers[j]);
            last = passengers[j];
            j++;
            cap--;
        }
        if(cap > 0)
            last = buses[i];
        i++;
    }
    while(st.find(last) != st.end())
        last--;

return last;
}

int main(){



return 0;
}