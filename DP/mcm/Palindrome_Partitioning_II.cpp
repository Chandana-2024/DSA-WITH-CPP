/*
Problem: Palindrome Partitioning II
Platform: LeetCode
Difficulty: Hard

-----------------------------------------------------

🧠 Intuition:
We need to partition the string such that every substring is a palindrome,
and the number of cuts is minimum.

👉 Key idea:
Instead of checking palindrome every time (which is costly),
we precompute all palindrome substrings using DP.

Then we use another DP to calculate the minimum cuts.

-----------------------------------------------------

🔁 Approach:

STEP 1️⃣: Precompute Palindrome Table

Let:
    t[i][j] = true → substring s[i...j] is a palindrome

Initialization:
    - All single characters are palindrome → t[i][i] = true

Build the table:
    - Length = 2 → check s[i] == s[j]
    - Length > 2 → check:
            s[i] == s[j] AND t[i+1][j-1]

This step ensures we can check palindrome in O(1) later.

-----------------------------------------------------

STEP 2️⃣: DP for Minimum Cuts

Let:
    dp[i] = minimum cuts needed for substring s[0...i]

Case 1:
    If s[0...i] is already a palindrome:
        dp[i] = 0

Case 2:
    Try all possible cuts:
        dp[i] = min over k in [0, i-1]:
            if s[k+1...i] is palindrome:
                dp[i] = min(dp[i], 1 + dp[k])

-----------------------------------------------------

⚡ Why this works:
- We avoid recomputing palindrome checks
- Each dp[i] builds on smaller valid partitions
- Ensures optimal substructure

-----------------------------------------------------

⏱️ Time Complexity:
O(N^2)
- Palindrome table → O(N^2)
- DP computation → O(N^2)

📦 Space Complexity:
O(N^2) for palindrome table + O(N) for dp array

-----------------------------------------------------

✨ Key Observations:
✔ Precomputing palindrome saves huge time  
✔ Partition DP pattern (cut-based decision)  
✔ Similar thinking to Matrix Chain Multiplication  

-----------------------------------------------------

💡 Optimization Insight:
Without the palindrome table, checking palindrome inside loop
would make it O(N^3). This DP optimization reduces it to O(N^2).

-----------------------------------------------------

🚀 Summary:
- First identify all palindromes
- Then minimize cuts using DP
- Clean separation of "validity check" and "optimization"

-----------------------------------------------------
*/
class Solution {
public:
    int minCut(string s) {
        int n =s.length();
        if(n == 0) return 0;
        vector<vector<bool>> t(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            t[i][i] = true;
        }


        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;

                if(l == 2){
                    t[i][j] = (s[i] == s[j]);
                }else{
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1]);
                }
            }
        }

        vector<int> dp(n);
        for(int i=0;i<n;i++){
            if(t[0][i] == true){
                dp[i] = 0;
            }else{
                dp[i] =INT_MAX;
                for(int k=0;k<i;k++){
                    if(t[k+1][i] == true && 1+dp[k] < dp[i]){
                        dp[i] = 1+dp[k];
                    }
                }
            }
        }

        return dp[n-1];
    }
};