/*
dfs is basically exploring as far as we can and once we cant, we stop and backtrack
*/

#include<bits/stdc++.h>
using namespace std;

vector<bool> visited; // boolean array to track visited node
vector<vector<int>> graph;  // adjacency list representation of graph

void dfs(int node){
    if(visited[node])   return; // already visited backtrack

    visited[node] = true;

    for(auto nbr : graph[node]){
        if(!visited[nbr]){
            dfs(nbr);   // recurse to neighbors
        }
    }
}

int main(){
    int n=5;
    visited.assign(n,false);    // marks n indices as false
    graph.resize(n);    // expand the graph to allocate n
    
}