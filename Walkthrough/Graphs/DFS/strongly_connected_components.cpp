// Kosaraju's algorithm

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;  // no of vertices
    vector<vector<int>> adj;    // adjacency list

public:
    Graph(int v){
        this->v = v;
        adj.resize(v);  // expand graph
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);    // directed edge u -> v
    }


    //< ------------ STEP 1 :  fill the original graph vertices in order of their finishing time    ------------------>
    // function to fill stack with vertices in order of finishing times
    void fillOrder(int v, vector<bool>& visited, stack<int>& stack){
        visited[v] = true;
        for(int nbr : adj[v]){
            if(!visited[nbr]){
                fillOrder(nbr, visited, stack);
            }
        }
        // the first element to be processed, here v, would be released at the very last
        // after all neighbors have been explored
        // thus after the recursive calls, the stack has elements in their finishing/releasing times.
        stack.push(v);
    }


    // dfs on transpose of graph to collect scc
    void dfsTranspose(int v, vector<bool>& visited, vector<int>& scc){
        visited[v] = true;
        scc.push_back(v);
        for(int nbr : adj[v]){
            if(!visited[nbr]){
                dfsTranspose(nbr, visited, scc);
            }
        }
    }


    // <----------- STEP 2 : transpose the graph ------------------------------>
    Graph getTransponse(){
        Graph g_t(v);    // g transpose of size v
        for(int i= 0; i<v; i++){
            for(int nbr : adj[i]){
                g_t.adj[nbr].push_back(i);
            }
        }
        return g_t;
    }

    vector<vector<int>> getSCC(){
        stack<int> stack;
        vector<bool> visited(v, false);

        for(int i=0; i<v; i++){
            if(!visited[i]) fillOrder(i,visited,stack);
        }

        Graph gr = getTransponse();

        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> sccs;

    //< -------------- STEP 3 :  pop vertices and perform dfs on transpose graph, each dfs yields one scc   ---------------->
        while(stack.empty()){
            int v = stack.top();    stack.pop();
            if(!visited[v]){
                vector<int> scc;
                gr.dfsTranspose(v, visited, scc);
                sccs.push_back(scc);
            }
        }
        return sccs;
    }
};


int main() {
    Graph g(5);
    // Example edges (directed)
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    vector<vector<int>> sccs = g.getSCC();
    cout << "Strongly Connected Components are:\n";
    for (auto& scc : sccs) {
        for (int v : scc) cout << v << " ";
        cout << "\n";
    }

    return 0;
}