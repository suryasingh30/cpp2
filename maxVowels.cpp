#include<bits/stdc++.h>
using namespace std;

int maxVowels(string s, int k){

    int st = 0;
    int e = 0;
    unordered_set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');

    int ans = 0;
    int count = 0;
    for(e=0; e<k; e++)
    {
        if(vowels.find(s[e]) != vowels.end())
        {
            count++;
        }
    }

    e = k;
    ans = count;
    while (e < s.size())
    {
        if(vowels.find(s[e]) != vowels.end())
        {
            count++;
        }
        if(vowels.find(s[st]) != vowels.end())
        {
            count--;
        }
        ans = max(ans, count);
    }
return ans;
}

int main(){



return 0;
}