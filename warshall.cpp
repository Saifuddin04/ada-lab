#include <iostream>
#include <vector>
using namespace std;
void warshallAlgorithm(vector<vector<int>>& graph, int V) {
    vector<vector<int>> transitiveClosure = graph;
    for (int k = 0; k < V; ++k) 
        for (int i = 0; i < V; ++i) 
            for (int j = 0; j < V; ++j) 
                transitiveClosure[i][j] = transitiveClosure[i][j] || (transitiveClosure[i][k] && transitiveClosure[k][j]);

    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) 
            cout << transitiveClosure[i][j] << " ";
        cout << endl;
    }
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";   cin >> V;
    cout << "Enter the number of edges: ";      cin >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));
    for (int i = 0; i < V; ++i) 
        graph[i][i] = 1;

    cout << "Enter the edges (u v) where u and v are vertices:\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1; // There is a path from u to v
    }
    warshallAlgorithm(graph, V);
    return 0;
} // https://onecompiler.com/cpp/42e2j2btj
