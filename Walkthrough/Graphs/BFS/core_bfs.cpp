#include<bits/stdc++.h>
using namespace std;

// bfs
// start at arbitrary node, explore neighbors, the move forward

int n;  // nodes
vector<vector<int>> graph;  // adjacency List rep

vector<int> bfs(int start, int end){
    vector<int> prev = solve(start);
    return reconstructPath(start, end, prev);
}

vector<int> solve(int start){
    queue<int> q;
    q.push(start);

    vector<bool> visited(n,false);

    visited[start] = true;
    vector<int> prev(n,0);  // track parent of i at index i

    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto nbr : graph[node]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
                prev[nbr] = node;
            }
        }
    }
    return prev;
}

vector<int> reconstructPath(int start,int end,vector<int> prev){
    vector<int> path;
    for(int node = end; node!=NULL; node = prev[node]){ // get ndoes from end link to root
        path.push_back(node);
    }
    reverse(path.begin(),path.end());   // reverse the path

    if(path[0] == start)    return path;

    // if start is not the fist node, there may have been a disconneted graph that did not help us reach "root"
    return {};
}


int main() {
    // number of nodes
    n = 6;

    // clear and init graph adjacency list
    graph.assign(n, vector<int>());

    // manually add edges (undirected graph)
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[3].push_back(4);
    graph[4].push_back(3);

    graph[4].push_back(5);
    graph[5].push_back(4);

    int start = 0;
    int end = 5;

    vector<int> path = bfs(start, end);

    if (path.empty()) {
        cout << "No path found\n";
    } else {
        for (int node : path) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
