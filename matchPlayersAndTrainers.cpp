#include<bits/stdc++.h>
using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers){
        
    int i=0, n=players.size();
    int j=0, m=trainers.size();
    int count = 0;

    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    while(i < n && j < m)
    {
        if(players[i] <= trainers[j])
        {
            count++;
            i++; j++;
        }
        else
            j++;
    }

return count;
}

int main(){


return 0;
}