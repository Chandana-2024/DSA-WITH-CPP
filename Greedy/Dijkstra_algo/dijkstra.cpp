// =======================================================
// Graph Algorithm - Dijkstra’s Algorithm (Shortest Path)
// Problem: Find shortest distance from source to all vertices
//
// Description:
// Given a weighted graph (non-negative weights),
// find the shortest distance from a source node
// to all other nodes.
//
// Key Idea:
// - Greedy approach
// - Always pick the node with minimum distance
// - Update (relax) its neighbors
//
// Important Condition:
// - Works ONLY for non-negative weights
//
// Mapping:
// graph → adjacency matrix
// dist[] → shortest distance from source
// visited[] → whether node is finalized
//
// DP / State Meaning:
// dist[i] = shortest distance from source → i
//
// Initialization:
// - dist[i] = INF (9999 here)
// - visited[i] = false
// - dist[source] = 0
//
// Steps:
//
// Repeat (n-1) times:
// 1. Pick unvisited node with minimum distance → u
// 2. Mark u as visited
// 3. Update all neighbors v:
//
//    If:
//    - v is not visited
//    - edge exists (graph[u][v] != 0)
//    - new distance is smaller
//
//    Then:
//    dist[v] = dist[u] + weight(u,v)
//
// Relaxation Formula:
// if(dist[u] + graph[u][v] < dist[v])
//     dist[v] = dist[u] + graph[u][v]
//
// Final Step:
// dist[] contains shortest distances from source
//
// Time Complexity: O(V^2)
// (because we linearly find min each time)
//
// Space Complexity: O(V)
// =======================================================


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=4;
    int graph[4][4]={
        {0,2,4,0},
        {2,0,1,7},
        {4,1,0,3},
        {0,7,3,0},
    };

    int source =0 ;
    int dist[n];
    bool visited[n];

    for(int i=0;i<n;i++){
        dist[i] = 9999;
        visited[i] =false;
    }

    dist[source] = 0;
    for(int cnt =0;cnt<n-1;cnt++){
        int min = 9999,u;
        for(int i=0;i<n;i++){
            if(!visited[i] && dist[i] < min ){
                min =dist[i];
                u=i;
                visited[u]= true;
                for(int v=0;v<n;v++){
                    if(!visited[v] && graph[u][v] !=0 && dist[u]+graph[u][v] < dist[v] ){
                        dist[v] =dist[u]+graph[u][v];
                    }
                }
            }
        }
    }

    cout<<"Shortest  distance from  source:\n";
    for(int i=0;i<n;i++){
        cout<<"to vertex"<<i<<"=" << dist[i]<<endl;
    }
    return 0;


}