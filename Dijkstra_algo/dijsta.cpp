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