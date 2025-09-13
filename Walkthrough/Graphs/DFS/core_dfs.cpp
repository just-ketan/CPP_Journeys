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

    graph[0].push_back(1);    // edge from 0 to 1
    graph[1].push_back(0);      // edge from 1 to 0
    graph[0].push_back(2);
    graph[2].push_back(0);
    graph[1].push_back(3);
    graph[3].push_back(1);
    graph[2].push_back(4);
    graph[4].push_back(2);

    dfs(0);
    return 0;
}