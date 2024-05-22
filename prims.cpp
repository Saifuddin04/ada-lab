#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

void printMST(vector<int>& parent, vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V);  
    vector<int> key(V, INT_MAX);  
    vector<bool> inMST(V, false);  
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    key[0] = 0;
    pq.push({0, 0});  
    parent[0] = -1;  

    while (!pq.empty()) {         
        int u = pq.top().second;
        pq.pop();         
        inMST[u] = true;         
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    printMST(parent, graph, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    primMST(graph, V);
    return 0;
} //refer - https://www.youtube.com/watch?v=mJcZjjKzeqk
//https://onecompiler.com/cpp/42dx9fyza
