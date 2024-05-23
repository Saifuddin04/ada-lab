#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
void printSolution(const vector<vector<int>>& dist, int V) {
    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) 
                cout << setw(5) << "INF";
            else 
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: "; 	cin >> V;
    cout << "Enter the number of edges: "; 		cin >> E;

    vector<vector<int>> dist(V, vector<int>(V, INF));

    cout << "Enter the edges (u v w) where u and v are vertices and w is the weight:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for (int i = 0; i < V; ++i) 
        dist[i][i] = 0;

    floydWarshall(dist, V);
    printSolution(dist, V);
    return 0;
} // https://onecompiler.com/cpp/42e2h6hhh
