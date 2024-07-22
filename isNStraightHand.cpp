#include<bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize){
        
    sort(hand.begin(), hand.end());
    unordered_map<int,int> ourmap;

    for(auto it : hand)
        ourmap[it]++;

    for(int i=0; i<hand.size(); i++)
    {
        if(ourmap.find(hand[i]) != ourmap.end())
        {
            int num;
            for(int j=0; j<groupSize; j++)
            {
                num = hand[i] + j;
                if(ourmap.find(num) != ourmap.end())
                {
                    ourmap[num]--;
                    if(ourmap[num] == 0)
                        ourmap.erase(num);
                }
                else
                    return false;
            }
        }
    }
return true;
}