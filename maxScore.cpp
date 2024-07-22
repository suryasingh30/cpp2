#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k){

    int n = cardPoints.size();
    int i = 0;
    int j = n-1;

    int maxSum = 0;
    for(i=0; i<=k; i++)
    {
        maxSum += cardPoints[i];
    }
    int initialSum = maxSum;

    i = k-1;
    while(i>=0)
    {
        int sum = maxSum - cardPoints[i] + cardPoints[j];
        maxSum = max(sum, maxSum);
        initialSum = sum;
        j--;
        i--;
    }
return maxSum;
}

int main(){



return 0;
}