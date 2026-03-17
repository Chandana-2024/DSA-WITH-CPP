// =======================================================
// Dynamic Programming - Longest Common Subsequence Pattern
// Problem: Uncrossed Lines
// Link: https://leetcode.com/problems/uncrossed-lines/
//
// Description:
// You are given two arrays nums1 and nums2.
// You can draw lines connecting equal numbers between arrays.
// Lines must NOT cross.
// Return the maximum number of such lines.
//
// Key Idea:
// - This problem is exactly same as "Longest Common Subsequence (LCS)".
// - Instead of strings, we are using arrays.
//
// Why LCS?
// - If we match elements in order without crossing,
//   we are basically finding a common subsequence.
//
// Mapping:
// nums1 → first sequence
// nums2 → second sequence
// Answer = length of LCS
//
// DP Definition:
// dp[i][j] = maximum uncrossed lines using:
//            first i elements of nums1
//            first j elements of nums2
//
// Base Case:
// dp[i][0] = 0  (no elements in nums2)
// dp[0][j] = 0  (no elements in nums1)
//
// Transition:
// If nums1[i-1] == nums2[j-1]:
//    dp[i][j] = 1 + dp[i-1][j-1]
//    (we match them → add 1)
//
// Else:
//    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
//    (skip one element)
//
// Final Step:
// Return dp[n][m]
//
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
// =======================================================

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};