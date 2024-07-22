#include<bits/stdc++.h>
using namespace std;

 bool check(int i, int j, vector<int>& nums) {
        // Iterate through the array and check each adjacent pair
        for (int k = i; i <j; ++k) {
            // Check the parity of nums[i] and nums[i+1]
            if ((nums[k] % 2) == (nums[k + 1] % 2)) {
                // If both numbers have the same parity, return false
                return false;
            }
        }
        // If all pairs have different parity, return true
        return true;
    }

   vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<bool> ans;
        for(int i=0; i<queries.size(); i++)
        {
            ans.push_back(check(queries[i][0], queries[i][1], nums));
        }

    return ans;
    } 


    int digitDifference(int num1, int num2) {
    // Convert numbers to strings
    std::string str1 = std::to_string(num1);
    std::string str2 = std::to_string(num2);

    // Make sure both strings have the same length by padding with zeros
    if (str1.length() > str2.length()) {
        str2.insert(0, str1.length() - str2.length(), '0');
    } else if (str2.length() > str1.length()) {
        str1.insert(0, str2.length() - str1.length(), '0');
    }

    int totalDifference = 0;

    // Calculate digit differences
    for (size_t i = 0; i < str1.length(); ++i) {
        totalDifference += abs(str1[i] - str2[i]);
    }

    return totalDifference;
}

long long sumDigitDifferences(vector<int>& nums) {

        int n = nums.size();
        int count = 0;

        for(int i=0; i<n ;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == j)
                    continue;
                count += digitDifference(nums[i], nums[j]);
            }
        }

    return count;
    }


#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Solution {
public:
    int digitDifference(int num1, int num2) {
        // Convert numbers to strings
        std::string str1 = std::to_string(num1);
        std::string str2 = std::to_string(num2);

        // Make sure both strings have the same length by padding with zeros
        if (str1.length() > str2.length()) {
            str2.insert(0, str1.length() - str2.length(), '0');
        } else if (str2.length() > str1.length()) {
            str1.insert(0, str2.length() - str1.length(), '0');
        }

        int differentDigitCount = 0;

        // Compare digits and count differences
        for (size_t i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[i]) {
                differentDigitCount++;
            }
        }

        return differentDigitCount;
    }

    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        long long totalDifference = 0;

        // Track the digit counts for each position (considering maximum 10 digits for generality)
        int max_digits = 10; // Assuming numbers can be up to 10 digits
        vector<vector<int>> digitCount(max_digits, vector<int>(10, 0));

        // Fill the digit count array
        for (int num : nums) {
            string str = to_string(num);
            int len = str.length();
            for (int i = 0; i < len; ++i) {
                int digit = str[len - i - 1] - '0';
                digitCount[i][digit]++;
            }
        }

        // Calculate the digit differences using the precomputed digit counts
        for (int i = 0; i < max_digits; ++i) {
            for (int d1 = 0; d1 < 10; ++d1) {
                for (int d2 = 0; d2 < 10; ++d2) {
                    if (d1 != d2) {
                        totalDifference += digitCount[i][d1] * digitCount[i][d2];
                    }
                }
            }
        }

        // Each difference is counted twice, once for each order (num1, num2) and (num2, num1)
        return totalDifference / 2;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {123, 456, 789, 321, 654};
    std::cout << "Total digit differences: " << sol.sumDigitDifferences(nums) << std::endl;
    return 0;
}




int recursion(int index, int jump, int k){

    if(index < 0)
        return 0;

    int count = 0;

    if(index == k)
        count += 1;

    int goDown = recursion(index-1, jump, k);
    int goUp = recursion(index+(1<<jump), jump+1, k);

    count += goDown + goUp;

return count;
}

int waysToReachStair(int k){
    return recursion(1, 0, k);
}

int main() {
    int num1 = 50;
    int num2 = 28;

    int result = digitDifference(num1, num2);
    std::cout << "Digit difference: " << result << std::endl;

    return 0;
}