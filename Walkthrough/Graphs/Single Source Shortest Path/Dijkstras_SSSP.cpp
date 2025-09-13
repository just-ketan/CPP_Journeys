#include<bits/stdc++.h>
using namespace std;

/*
the main idea is to get a distance array 
we traverse each node and check in the const to reach there is lower than current cost
we update the cost
*/

typedef pair<int,int> edge; // [dist,node]

vector<int> dijkstra(const vector<vector<edge>>& graph, int start){
    int n = (int)graph.size();

    vector<bool> visited(n,false);
    vector<int> distance(n,INT_MAX);

    distance[start] = 0;    // distance from origin

    priority_queue<edge, vector<edge>, greater<edge>> minheap;

    minheap.push({0,start});    // push {dist, idx}

    while(!minheap.empty()){
        auto [minval, idx] = minheap.top(); minheap.pop();
        
        if(visited[idx])    continue;

        visited[idx] = true;

        for(auto& edge : graph[idx]){   // remember to put & whenever multivalued iteration
            if(!visited[edge.second]){   // if the destination index in popped pair is not visited
                int newdist = distance[idx] + edge.first;  // new dist would be the distance of node from origin, and to the current node
                if(newdist < distance[edge.first]){
                    distance[edge.first] = newdist;
                    minheap.push({newdist,edge.second});
                }
            }
        }
    }
    return distance;
}