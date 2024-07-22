#include <vector>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {

        int n = points.size();
        int ans = 0;

        unordered_map<char, vector<vector<int>>> pointTags;

        // Group points by their tags
        for (int i = 0; i < points.size(); ++i) {
            pointTags[s[i]].push_back(points[i]);
        }

        // Iterate over all pairs of points
        for(int i=0; i<n; i++)
        {
            int x = abs(points[i][0]);
            int y = abs(points[i][1]);

            int count = 1;
            unordered_set<char> st;
            st.insert(s[i]);

            for(int j=i+1; j<n; j++)
            {
                int nx = abs(points[j][0]);
                int ny = abs(points[j][1]);

                if(nx <= x && ny <= y)
                {
                    if(st.find(s[j]) == st.end())
                    {
                        count++;
                        st.insert(s[j]);
                    }
                }
            }

            ans = max(ans, count);
        }

        return ans;
    }
};
