// LeetCode 1514: Path with Maximum Probability
// Approach: Modified Dijkstra (Max Heap)
// Time: O(E log V), Space: O(V + E)

#include <bits/stdc++.h>
using namespace std;

class Solution { 
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int,double>>> adj(n);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        vector<double> prob(n,0.0);
        prob[start_node] =1.0;

        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});

        while(!pq.empty()){
            auto[currProb,node]=pq.top();
            pq.pop();

            if(node == end_node){
                return currProb;
            }

            if(currProb < prob[node]) continue;



            for(auto &n : adj[node]){
                int nextNode = n.first;
                double edgeProb = n.second;

                double newProb = currProb * edgeProb;

                if(newProb > prob[nextNode]){
                    prob[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            
            }
        }

        return 0.0;
        
    }
};