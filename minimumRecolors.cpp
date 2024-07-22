#include<bits/stdc++.h>
using namespace std;

int minimumRecolors(string blocks, int k){

    int s=0 , e=0, count=0;

    for(e=0; e<k; e++)
    {
        if(blocks[e] == 'W')
            count++;
    }

    e=k;
    int n = blocks.size();

    while (e<n)
    {
        if(blocks[e] == 'W')
            count++;
        if(blocks[s] == 'W')
            count--;
        e++;
        s++;
    }
return count;
}

int main(){



return 0;
}