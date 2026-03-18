// =======================================================
// Graph + Dijkstra (Minimax Path Problem)
// Problem: Path With Minimum Effort
// Link: https://leetcode.com/problems/path-with-minimum-effort/
//
// Description:
// You are given a 2D grid of heights. You need to travel from
// the top-left cell (0,0) to the bottom-right cell (m-1,n-1).
//
// The effort of a path is defined as the maximum absolute
// difference in heights between two consecutive cells.
//
// Return the minimum possible effort required to reach the
// destination.
//
// Key Idea:
// - This is a variation of Dijkstra’s algorithm.
// - Instead of minimizing total distance, we minimize the
//   maximum edge weight along the path (minimax).
//
// State Definition:
// effort[r][c] = minimum effort required to reach cell (r,c)
//
// Priority Queue:
// - Min-heap based on current effort
//
// Transition:
// From (r,c) → (nr,nc):
// newEffort = max(currEffort, abs(height difference))
//
// If newEffort < effort[nr][nc], update it.
//
// Time Complexity: O(m * n * log(m * n))
// Space Complexity: O(m * n)
// =======================================================


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int currEffort = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if (r == m - 1 && c == n - 1)
                return currEffort;

            if (currEffort > effort[r][c])
                continue;

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {

                    int diff = abs(heights[r][c] - heights[nr][nc]);
                    int newEffort = max(currEffort, diff);

                    if (newEffort < effort[nr][nc]) {
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};