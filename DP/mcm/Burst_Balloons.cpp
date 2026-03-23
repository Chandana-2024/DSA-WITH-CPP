/*
Problem: Burst Balloons
Platform: LeetCode
Difficulty: Hard

-----------------------------------------------------

🧠 Intuition:
At first glance, bursting balloons seems like a greedy problem…
but it’s actually a **partition DP problem (MCM pattern)** in disguise.

Instead of thinking:
❌ "Which balloon to burst first?"

We reverse the thinking:
✅ "Which balloon to burst LAST in a range?"

Why?
Because when we burst the last balloon `k` in a range [i, j],
its neighbors are FIXED → nums[i-1] and nums[j+1]

👉 Coins gained:
   nums[i-1] * nums[k] * nums[j+1]

This removes uncertainty and makes the problem solvable using DP.

-----------------------------------------------------

🔁 Approach (Top-Down DP / Memoization):

1. Add virtual boundaries:
      nums = [1, original_array..., 1]

2. Define:
      solve(i, j) → maximum coins from bursting balloons in range [i, j]

3. Base Case:
      If (i > j), no balloons left → return 0

4. Recurrence:
      Try making each balloon `k` the LAST burst in [i, j]:

      solve(i, j) = max over k in [i, j]:
          nums[i-1] * nums[k] * nums[j+1]
        + solve(i, k-1)
        + solve(k+1, j)

5. Use DP table `dp[i][j]` to store results.

-----------------------------------------------------

⚡ Why this works:
- Choosing the last balloon avoids dependency issues.
- Each choice splits the problem into independent subproblems.
- Ensures we explore all optimal substructures.

-----------------------------------------------------

⏱️ Time Complexity:
O(N^3)
- O(N^2) states (i, j)
- For each state, we try O(N) choices of k

📦 Space Complexity:
O(N^2) for DP + recursion stack

-----------------------------------------------------

✨ Key Observations:
✔ Reverse thinking (last instead of first) is the key trick  
✔ Same pattern as Matrix Chain Multiplication  
✔ Boundaries (1,1) simplify edge cases  

-----------------------------------------------------

💡 Pro Tip:
Whenever a problem involves:
- Splitting into subarrays
- Trying every partition
- Combining left + right results

👉 Think: "Can I assume one element is the LAST operation?"

That often unlocks the DP solution 🚀

-----------------------------------------------------
*/

class Solution {
public:
    int dp[501][501];

    int solve(int i, int j, vector<int>& nums) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int maxi = 0;

        for (int k = i; k <= j; k++) {
            int cost = nums[i-1] * nums[k] * nums[j+1]
                     + solve(i, k-1, nums)
                     + solve(k+1, j, nums);

            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        memset(dp, -1, sizeof(dp));
        return solve(1, nums.size()-2, nums);
    }
};