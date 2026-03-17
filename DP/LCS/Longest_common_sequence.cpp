// =======================================================
// Dynamic Programming - Longest Common Subsequence (LCS)
// Problem: Longest Common Subsequence
// Link: https://leetcode.com/problems/longest-common-subsequence/
//
// Description:
// Given two strings x and y, return the length of their
// longest common subsequence.
//
// A subsequence:
// - keeps order
// - may skip elements
//
// Key Idea:
// - We try matching characters from both strings
// - If match → include it
// - If not → skip one character
//
// Mapping:
// x → first string
// y → second string
//
// DP Definition:
// dp[i][j] = length of LCS using:
//            first i chars of x
//            first j chars of y
//
// Base Case:
// dp[i][0] = 0  (empty string)
// dp[0][j] = 0
//
// Transition:
// If x[i-1] == y[j-1]:
//    dp[i][j] = 1 + dp[i-1][j-1]
//    (match → take diagonal)
//
// Else:
//    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
//    (skip one char)
//
// Final Step:
// return dp[n][m]
//
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
// =======================================================
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int longestCommonSubsequence(string x, string y) {
        int  n = x.size();
        int m = y.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    
    }
};