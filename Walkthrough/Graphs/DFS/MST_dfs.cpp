// primms's MST algorithm can help find MST
// MST is subset that is connected with all nodes, minimal edge weights and no cycle

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> edge; // a pair from node A to node B

int n;
vector<bool> visited;
vector<vector<edge>> graph;    // essentially each index i has a vector that has pair - [ cost : dest node ]

vector<pair<int,int>> primms(){
    // mst prep
    vector<int> parent(n, -1);  // track mst edges

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    // pq thats minheap based on cost of each 'edge'
    visited.assign(n,false);
    pq.push({0,0});     // curr node has 0 distance;

    int totcost = 0;

    while(!pq.empty()){
        auto [cost, node] = pq.top();   pq.pop();

        if(visited[node])   continue;   //skip already processed node

        visited[node] = true;
        totcost += cost;

        for(auto& edge : graph[node]){
            int nbr = edge.second;
            int weight = edge.first;
            if(!visited[nbr]){
                pq.push({weight, nbr});
                // update parent if this node was a better connection
                if(parent[nbr] == -1 || weight < graph[parent[nbr]][nbr].first){
                    parent[nbr] = node; // track parent for this

                    /*
                    weight < graph[parent[nbr]][nbr].first
                    this check if the current wieght is less than THE CURRENT COST FROM NBR'S PARENT TO NBR
                    this means a cheaper edge to reach nbr is found in traversal
                    update the parent of nbr as current node
                    ensure mst has minimum possible cost
                    */
                }
            }
        }
    }
}