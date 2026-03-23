/*
Problem: Minimum Score Triangulation of Polygon
Platform: LeetCode
Difficulty: Medium

-----------------------------------------------------

🧠 Intuition:
This problem is a classic example of **Matrix Chain Multiplication (MCM) pattern**.

We are given a polygon with `n` vertices, and each vertex has a value.
We need to divide the polygon into triangles such that the **total score is minimum**.

👉 Score of a triangle formed by vertices (i, k, j):
   = arr[i-1] * arr[k] * arr[j]

So basically, we try every possible point `k` between `i` and `j`
to form a triangle and recursively solve the left and right parts.

-----------------------------------------------------

🔁 Approach (Top-Down DP / Memoization):

1. Define a recursive function:
      solve(i, j) → minimum cost to triangulate vertices from i to j

2. Base Case:
      If (i == j), no triangle can be formed → return 0

3. Recurrence Relation:
      Try all possible partitions:
      
      solve(i, j) = min over all k in [i, j-1]:
          solve(i, k) 
        + solve(k+1, j) 
        + arr[i-1] * arr[k] * arr[j]

4. Use a DP table `dp[i][j]` to store results
   to avoid recomputation (memoization).

-----------------------------------------------------

⚡ Why this works:
- We break the polygon into smaller sub-polygons.
- Each choice of `k` forms one triangle and divides the problem.
- This ensures we explore all valid triangulations.

-----------------------------------------------------

⏱️ Time Complexity:
O(N^3)
- We have O(N^2) states
- For each state, we try O(N) partitions

📦 Space Complexity:
O(N^2) for DP table

-----------------------------------------------------

✨ Key Observation:
This is NOT a greedy problem.
Trying all partitions (like MCM) ensures we get the global minimum.

-----------------------------------------------------
*/

class Solution {
public:
    int dp[101][101];

    int solve(int i, int j, vector<int>& arr) {
        if (i == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k < j; k++) {
            int cost = solve(i, k, arr) 
                     + solve(k + 1, j, arr) 
                     + arr[i - 1] * arr[k] * arr[j];

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minScoreTriangulation(vector<int>& arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(1, n - 1, arr);
    }
};