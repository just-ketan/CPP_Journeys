/*
topo sort is a method to order vertices of DAG such that u comes before v in order if edge u->v exists
*/

// do dfs
// mark node as visited
// whe exploration finishes, push element onto stack
// this ensures there are no nodes with outgoing edges being pushed before in order
// reverse the list to get topological order


#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& stack){
    visited[node] = true;
    for(int nbr : graph[node]){
        if(!visited[nbr])   dfs(nbr, graph, visited, stack);
    }
    stack.push(node);   // push after exploring all descendants
}

vector<int> topo_sort(int n, vector<vector<int>>& graph){
    vector<bool> visited(n,false);
    stack<int> stack;

    for(int i=0; i<n; i++){
        if(!visited[i]) dfs(i, graph, visited, stack);
    }

    vector<int> topo;   // topological ordering
    while(!stack.empty()){
        topo.push_back(stack.top());   stack.pop();
    }
    return topo;
}   

int main() {
    int n = 6;
    vector<vector<int>> graph(n);
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    vector<int> order = topo_sort(n, graph);
    for (int v : order)
        cout << v << " ";
    cout << "\n";

    return 0;
}