#include<bits/stdc++.h>
using namespace std;

int maxEqualFreq(vector<int>& nums){

    unordered_map<int,int> ourmap;
    for(auto it : nums)
        ourmap[it]++;

    unordered_map<int,int> mp;
    for(auto it : ourmap)
        mp[it.second]++;

    int count = 0;
    int times = 0;
    for(auto it : mp)
    {
        if(it.second > count)
        {
            times = it.first;
            count = it.second;
        }
    }
    
    if(mp.size() == 1)
    {
        return (times*(count-1))+1;
    }
    
return (times*count)+1;
}

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> freq; // frequency of elements
        unordered_map<int, int> count; // count of frequencies
        int maxFreq = 0; // maximum frequency
        int res = 0; // result to store maximum length of valid prefix

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];

            if (freq[num] > 0) {
                count[freq[num]]--;
                if (count[freq[num]] == 0) {
                    count.erase(freq[num]);
                }
            }

            freq[num]++;
            count[freq[num]]++;

            maxFreq = max(maxFreq, freq[num]);

            bool valid = false;

            // Case 1: All frequencies are the same
            if (count.size() == 1) {
                if (count.begin()->first == 1 || count.begin()->second == 1) {
                    valid = true;
                }
            }

            // Case 2: There are exactly two different frequencies
            if (count.size() == 2) {
                auto it = count.begin();
                int f1 = it->first;
                int c1 = it->second;
                ++it;
                int f2 = it->first;
                int c2 = it->second;

                // Check if we can remove one element
                if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) {
                    valid = true;
                }

                // Check if we can make all elements to be of same frequency by removing one element
                if ((f1 + 1 == f2 && c2 == 1) || (f2 + 1 == f1 && c1 == 1)) {
                    valid = true;
                }
            }

            if (valid) {
                res = i + 1;
            }
        }

        return res;
    }
};


int main(){



return 0;
}