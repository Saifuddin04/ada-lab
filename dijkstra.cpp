#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

void dijkstra(const vector<vector<pair<int, int>>> &graph, int source) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << " \t " << dist[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: "; 	cin >> V;
    cout << "Enter the number of edges: "; 		cin >> E;

    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter the edges (u v w) where u and v are vertices and w is the weight:" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); 
    }

    int source;
    cout << "Enter the source vertex: "; 	cin >> source;
    dijkstra(graph, source);
    return 0;
} // https://onecompiler.com/cpp/42e2gvd4t
