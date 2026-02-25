// =======================================================
// Dynamic Programming - 0/1 Knapsack Pattern
// Problem: Partition Equal Subset Sum
// Link: https://leetcode.com/problems/partition-equal-subset-sum/
//
// Description:
// Given an integer array nums, determine whether the array
// can be partitioned into two subsets such that the sum of
// elements in both subsets is equal.
//
// Key Idea:
// - This is a Subset Sum problem.
// - If total sum is odd, equal partition is impossible.
// - Otherwise, check if a subset with sum = totalSum / 2 exists.
//
// DP Definition:
// dp[i][j] = true if we can form sum 'j' using first 'i' elements.
//
// Base Case:
// - dp[i][0] = true
// - dp[0][j] = false (j > 0)
//
// Transition:
// If nums[i-1] <= j:
//    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]]
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
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        // Calculate total sum
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // If sum is odd, cannot partition
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        // DP table
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: sum 0 is always possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};