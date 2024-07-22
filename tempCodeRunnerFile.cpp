long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
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