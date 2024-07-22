#include<bits/stdc++.h>
using namespace std;

long long minimumRemoval(vector<int>& beans){

    int n = beans.size();
    sort(beans.begin(), beans.end());
    long long count = 0;
    int j = 0;

    for(int i=0; i<n-1; i++)
    {
        if(beans[i] == beans[i+1])
            continue;

        else if(((i-j+1) * beans[i]) > (beans[i+1] - beans[i]))
        {
            count += (beans[i+1] - beans[i]);
            beans[i+1] = beans[i];
        }
        else if(((i-j+1) * beans[i]) < (beans[i+1] - beans[i]))
        {
            count += ((i-j+1) * beans[i]);
            j = i;
        }
    }

return count;
}

long long minimumRemoval(vector<int>& beans){

    int n = beans.size();
    sort(beans.begin(), beans.end());
    long long count = 1e9;
    long long total = 0;
    for(auto it : beans)
        total += it;
    
    for(int i=0; i<n; i++)
    {
        long long toRemove = abs(total - ((n-i) * beans[i])); // needed beans
        count = min(count, toRemove);
    }
 
return count;
}


int main(){



return 0;
}