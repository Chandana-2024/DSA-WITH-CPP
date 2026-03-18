// =======================================================
// Dynamic Programming - Unbounded Knapsack Pattern
// Problem: Rod Cutting Problem
// Source: GeeksforGeeks (GFG)
//
// Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
//
// Description:
// Given a rod of length N and an array price[] where price[i]
// represents the value of a rod of length i+1,
// determine the maximum value obtainable by cutting up the rod.
//
// Key Idea:
// - This is an Unbounded Knapsack problem.
// - Each rod length can be used multiple times.
// - We either:
//   1) Cut the rod at current length (reuse allowed)
//   2) Skip the current length
//
// DP Definition:
// dp[i][j] = maximum value obtainable using first 'i' lengths
//            to achieve total rod length 'j'.
//
// Base Case:
// - dp[0][j] = 0 (no lengths available)
// - dp[i][0] = 0 (rod length 0)
//
// Transition:
// If i <= j:
//    dp[i][j] = max(
//                  price[i-1] + dp[i][j - i],   // take (unbounded)
//                  dp[i-1][j]                   // not take
//               )
// Else:
//    dp[i][j] = dp[i-1][j]
//
// Time Complexity: O(n * n)
// Space Complexity: O(n * n)
// =======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();

        // DP table
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i <= j) {
                    dp[i][j] = max(
                        price[i - 1] + dp[i][j - i],  // take (unbounded)
                        dp[i - 1][j]                  // not take
                    );
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][n];
    }
};