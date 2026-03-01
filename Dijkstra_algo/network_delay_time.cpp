/*
LeetCode: Network Delay Time
Link: https://leetcode.com/problems/network-delay-time/

Approach:
- Use Dijkstra's Algorithm (Min-Heap)
- Graph represented as adjacency list
- Find shortest time from source node k to all nodes
- Answer = maximum distance among all nodes
- If any node is unreachable, return -1

Time Complexity: O(E log V)
Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Adjacency list: node -> {neighbor, weight}
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Min-heap: {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, k});

        // Dijkstra
        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto &nbr : adj[node]) {
                int nextNode = nbr.first;
                int weight   = nbr.second;

                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        // Find maximum time
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};