// =======================================================
// Dynamic Programming - 0/1 Knapsack Pattern
// Problem: Target Sum
// Link: https://leetcode.com/problems/target-sum/
//
// Description:
// Given an integer array nums and an integer target,
// return the number of ways to assign '+' and '-' signs
// to make the sum equal to target.
//
// Key Idea:
// - This problem can be converted into a "Count Subsets
//   with Given Sum" problem.
// - Let totalSum be the sum of all elements.
// - Using equations:
//     S1 - S2 = target
//     S1 + S2 = totalSum
//   => S1 = (target + totalSum) / 2
//
// - Now, the task reduces to counting subsets with sum = S1.
//
// Edge Cases:
// - If |target| > totalSum → no solution
// - If (target + totalSum) is odd → no solution
//
// DP Definition:
// dp[i][j] = number of ways to form sum 'j' using first 'i' elements.
//
// Base Case:
// - dp[i][0] = 1 (empty subset)
//
// Transition:
// If nums[i-1] <= j:
//    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]]
// Else:
//    dp[i][j] = dp[i-1][j]
//
// Time Complexity: O(n * sum)
// Space Complexity: O(n * sum)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        // Calculate total sum
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Edge cases
        if (abs(target) > sum) {
            return 0;
        }

        if ((target + sum) % 2 != 0) {
            return 0;
        }

        int total = (target + sum) / 2;

        // DP table
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));

        // Base case: sum 0 can be formed in 1 way
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= total; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][total];
    }
};