// =======================================================
// Dynamic Programming - LCS Variation
// Problem: Delete Operation for Two Strings
// Link: https://leetcode.com/problems/delete-operation-for-two-strings/
//
// Description:
// Given two strings word1 and word2,
// return minimum number of deletions required
// to make both strings equal.
//
// Key Idea:
// - We cannot reorder, only delete
// - So we keep the "common part" (LCS)
// - Delete everything else
//
// Mapping:
// - Find LCS of word1 and word2
// - Let LCS = common part to keep
//
// Formula:
// deletions = (n - LCS) + (m - LCS)
//           = n + m - 2 * LCS
//
// DP Definition:
// Same as LCS:
// dp[i][j] = LCS length till i, j
//
// Base Case:
// dp[i][0] = 0
// dp[0][j] = 0
//
// Transition:
// If word1[i-1] == word2[j-1]:
//    dp[i][j] = 1 + dp[i-1][j-1]
//
// Else:
//    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
//
// Final Step:
// lcs = dp[n][m]
// answer = n + m - 2 * lcs
//
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
// =======================================================


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] =  1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int lcs = dp[n][m];

        int ans = n+m-2*lcs;
        return ans;

    }
};