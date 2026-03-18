// =======================================================
// Dynamic Programming - 0/1 Knapsack Pattern
// Problem: Last Stone Weight II
// Link: https://leetcode.com/problems/last-stone-weight-ii/
//
// Description:
// You are given an array of stones where stones[i] is the
// weight of the ith stone. Each turn, you can smash two stones.
// The goal is to minimize the final remaining stone weight.
//
// Key Idea:
// - This problem is a variation of "Minimum Subset Sum Difference".
// - Divide stones into two subsets such that the difference
//   between their sums is minimized.
//
// Mapping:
// - Let total = sum of all stones.
// - Find a subset with sum as close as possible to total / 2.
// - Final answer = total - 2 * subsetSum.
//
// DP Definition:
// dp[i][j] = true if we can form sum 'j' using first 'i' stones.
//
// Base Case:
// - dp[i][0] = true (sum 0 is always possible)
//
// Transition:
// If stones[i-1] <= j:
//    dp[i][j] = dp[i-1][j] || dp[i-1][j - stones[i-1]]
// Else:
//    dp[i][j] = dp[i-1][j]
//
// Final Step:
// - Traverse dp[n][j] from j = total/2 down to 0
// - First true value gives the best subset sum
//
// Time Complexity: O(n * sum)
// Space Complexity: O(n * sum)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;

        // Calculate total sum
        for (int i = 0; i < n; i++) {
            total += stones[i];
        }

        int sum = total / 2;

        // DP table
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (stones[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - stones[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Find best possible subset sum closest to total/2
        int best = 0;
        for (int j = sum; j >= 0; j--) {
            if (dp[n][j]) {
                best = j;
                break;
            }
        }

        return total - 2 * best;
    }
};