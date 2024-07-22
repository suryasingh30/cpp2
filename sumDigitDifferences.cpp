#include<bits/stdc++.h>
using namespace std;


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
                int digit = str[i] - '0';
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

