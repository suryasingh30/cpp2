#include<bits/stdc++.h>
using namespace std;

void reverseVectorTillIndex(vector<int>& vec, int index) {
    int start = 0;
    int end = index;
    while (start < end) {
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

vector<int> pancakeSort(vector<int>& arr){
        
    int n = arr.size();
    int i=0, j=n-1;

    vector<int> final = arr;
    sort(final.begin(), final.end());
    vector<int> ans;

    while(true)
    {
        i=0;
        j=n-1;
        while(i < j)
        {
            if(arr[i] > arr[j])
            {
                ans.push_back(j+1);
                // reverse till j
                reverseVectorTillIndex(arr, j);
                break;
            }
            i++;
            j--;
        }
        if(arr == final)
            break;
    }
return ans;
}

class Solution {
public:
    // Function to reverse the vector up to the specified index
    void reverseVectorTillIndex(vector<int>& vec, int index) {
        int start = 0;
        int end = index;
        while (start < end) {
            swap(vec[start], vec[end]);
            start++;
            end--;
        }
    }

    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();

        for(int i=n-1; i>0; i--)
        {
            int maxi_index = max_element(arr.begin(), arr.begin()+i+1) - arr.begin();

            if(maxi_index != i)
            {
                if(maxi_index > 0)
                {
                    reverseVectorTillIndex(arr, maxi_index);
                    ans.push_back(maxi_index+1);
                }
                reverseVectorTillIndex(arr, i);
                ans.push_back(i+1);
            }
        }
    
    return ans;
    }
};

int main(){

    vector<int> arr = {3, 2, 4, 1};
    // reverseVectorTillIndex(arr, 2);

    arr = pancakeSort(arr);
    for(auto it : arr)
        cout<<it<<" ";
    
return 0;
}

