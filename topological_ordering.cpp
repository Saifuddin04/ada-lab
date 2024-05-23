#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void DFS(int v, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& ordering) {
    visited[v] = true;
    for (int u : graph[v]) 
        if (!visited[u]) 
            DFS(u, graph, visited, ordering);

    ordering.push(v);
}
vector<int> topologicalSort(vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    stack<int> ordering;

    for (int v = 0; v < V; ++v) 
        if (!visited[v]) 
            DFS(v, graph, visited, ordering);

    vector<int> result;
    while (!ordering.empty()) {
        result.push_back(ordering.top());
        ordering.pop();
    }
    return result;
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: "; 	cin >> V;
    cout << "Enter the number of edges: "; 		cin >> E;

    vector<vector<int>> graph(V);
    cout << "Enter the edges (u v) where u and v are vertices:\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Add edge from u to v
    }

    vector<int> ordering = topologicalSort(graph, V);

    cout << "Topological Ordering: ";
    for (int vertex : ordering) 
        cout << vertex << " ";
    cout << endl;
    return 0;
} // https://onecompiler.com/cpp/42e2jpwpw
