#include<bits/stdc++.h>
using namespace std;

int n;
vector<bool> visited;
vector<bool> recstack;
vector<vector<int>> graph;  //adj list rep

/*
traverse the graph
keep track of parent
if we ever reach a ndoe thats not parent and is visited
*/

bool findcycle(int node){
    visited[node] = true;
    recstack[node] = true;
    // mark as visted and add entry to recursion stack

    for(int nbr : graph[node]){
        if(!visited[nbr]){
            if(findcycle(nbr))  return true;
        }else if(recstack[nbr]) return true;    // node in current recursion stack
    }

    // if control comes here, backtrack
    recstack[node] = false; // release current node
    return false;   // no cycle
}

bool hascycle(){
    // for all the nodes in graph
    // check if theres a cycle from each index
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(findcycle(i))    return true;
        }
    }
    return false;
}