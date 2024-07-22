#include<bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int>& people, int limit){
        
    int s = 0, e = people.size()-1;
    int count = 0;

    while(s <= e)
    {
        if(people[s] + people[e] <= limit)
        {
            count++;
            s++;
            e--;
        }
        else
        {
            count++;
            e--;
        }
    }
return count;
}

// long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
//         sort(enemyEnergies.begin(), enemyEnergies.end());
//         int points = 0;
//         int n = enemyEnergies.size();
//         vector<int> marked(n, 0);
        
//         priority_queue<pair<int,int>> pq;  // Max-heap to store the energies of marked enemies
//         for(int i=0; i<enemyEnergies.size(); i++)
//         {
//             pq.push({enemyEnergies[i], i});
//         }

//         for (int i = 0; i < n; i++) {
//             if (currentEnergy >= enemyEnergies[i] && marked[i] == 0) {
//                 // Attack the enemy to gain a point
//                 currentEnergy -= enemyEnergies[i];
//                 points += (currentEnergy/enemyEnergies[i]);
//                 // pq.push(enemyEnergies[i]);
//             } else if (!pq.empty() && points > 0) {
//                 // If current energy is insufficient to attack and we have previously marked enemies
//                 currentEnergy += pq.top().first; // regain energy from the most energy-providing marked enemy
//                 marked[pq.top().second] = 1;
//                 pq.pop();
//                 i--;  // retry the same enemy with the regained energy
//             } else {
//                 break;  // No more moves possible
//             }
//         }
        
//         return points;
//     }


long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
    sort(enemyEnergies.begin(), enemyEnergies.end());
    long long points = 0;
    int n = enemyEnergies.size();
    vector<int> marked(n, 0);
    
    int i = 0, j = n-1;

    while(i < j)
    {
        if(currentEnergy >= enemyEnergies[i] && marked[i] == 0)
        {
            points += (currentEnergy/enemyEnergies[i]);
            currentEnergy = (currentEnergy%enemyEnergies[i]);
            i++;
        }
        else if(points > 0 && marked[j] == 0)
        {
            currentEnergy = currentEnergy + enemyEnergies[j];
            marked[j] = 1;
            j--;
        }
    }

return points;
}

int recursion(int index, int past, vector<int>& colors, int cnt, int k){

    if(index >= colors.size())
        return 0;

    if(cnt == k)
        return 1;

    int pick = 0, notPick = 0;

    if(colors[index] != past)
        pick = recursion(index+1, colors[index], colors, cnt+1, k);
    
    notPick = recursion(index+1, past, colors, cnt, k);

return pick+notPick;
}

int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        vector<int> dp(n, 0);

        // Iterate through each possible starting point in the array
        for (int t = 0; t < n; t++) {
            bool isValid = true;
            // Check the segment of size k starting from t
            for (int i = 0; i < k-1; i++) {
                cout<<i<<" ";
                if (colors[(t + i) % n] == colors[(t + i + 1) % n]) {
                    isValid = false; // Break if any two consecutive colors are the same
                    cout<<"broke"<<" ";
                    break;
                }
                dp[(t+i+1) % n] = dp[(t+i) % n] + 1;
            }
            if (isValid) {
                // cout<<"valid-"<<t<<" ";
                count++; // Increment count if a valid alternating group is found
            }
        }  
        return count;
    }

int main(){

    cout<<10/2;

return 0;
}
