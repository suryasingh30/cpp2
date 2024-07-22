#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box){
        
    int m = box.size();
    int n = box[0].size();

    for(int i=0; i<m; i++)
    {
        int start;
        int end = 0;
        for(int j=n-1; j>=0; j--)
        {
            if(box[i][j] == '.')
                end = j;
        }
        for(start = end-1; start>0; start--)
        {
            if(box[i][start] == '#' && box[i][end] == '.' && end > start)
            {
                box[i][end] = '#';
                box[i][start] = '.';
                end--;
            }

            if(box[i][start] == '*')
            {
                end = start;
            }

            while(end >= 0 && (box[i][end] == '#' || box[i][end] == '*'))
                end--;
        }
    }

    vector<vector<char>> ans;
    for(int i=0; i<n; i++)
    {
        vector<char> temp;
        for(int j=m-1; j>=0; j--)
        {
            temp.push_back(box[i][j]);
        }
        ans.push_back(temp);
    }

return ans;
}

int main(){

// [["#",".","#"]]
// [["#",".","*","."],["#","#","*","."]]
// [["#","#","*",".","*","."],["#","#","#","*",".","."],["#","#","#",".","#","."]]
return 0;
}