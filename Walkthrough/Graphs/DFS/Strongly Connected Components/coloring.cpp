#include<bits/stdc++.h>
using namespace std;

int n; // nodes
vector<vector<int>> graph;
int componentcount = 0;    // identifier

vector<int> componentsID; // components ID for each node
vector<bool> visited;   // track if node is visited


void dfs(int node){
    visited[node] = true;
    componentsID[node] = componentcount; // assign current component ID (cnt) to this node

    for(auto nbr : graph[node]){    // iof nbr is not visited, recurse
        if(!visited[nbr])   dfs(nbr);
    }
}


map<int, vector<int>> findComponents(){
    visited.assign(n,false); // all indeices marekd as unvisited
    componentsID.assign(n,0);    // all n indices marked as 0
    int cnt = 0;

    // for all nodes in graph
    for(int id=0; id<n; id++){
        if(!visited[id]){   // if the node is not marked visited by earlier dfs, its not in same component
            componentcount++;   // new component found
            dfs(id);    // explore all nodes in this identifier.
        }
    }
    map<int, vector<int>> componentsMap;
    for(int node=0; node<n; node++){
        componentsMap[componentsID[node]].push_back(node);
    }
    return componentsMap;    // final map with color : scc list

}