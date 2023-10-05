#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to perform Prim's algorithm
pair<vector<pair<int, int>>, int> primMST(vector<vector<pair<int, int>>>& graph, int start) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<pair<int, int>> minimumSpanningTree;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Start with the given vertex
    minHeap.push(make_pair(0, start));
    int totalWeight = 0;

    while (!minHeap.empty()) {
        // Extract the edge with the minimum weight
        pair<int, int> currentEdge = minHeap.top();
        minHeap.pop();

        int currentVertex = currentEdge.second;
        int currentWeight = currentEdge.first;

        // If the vertex is already visited, skip it
        if (visited[currentVertex]) {
            continue;
        }

        // Mark the current vertex as visited
        visited[currentVertex] = true;

        // Add the current edge to the minimum spanning tree
        minimumSpanningTree.push_back(make_pair(currentVertex, currentWeight));
        totalWeight += currentWeight;

        // Add adjacent edges to the priority queuexa
        for (pair<int, int>& neighbor : graph[currentVertex]) {
            int neighborVertex = neighbor.first;
            int neighborWeight = neighbor.second;
            if (!visited[neighborVertex]) {
                minHeap.push(make_pair(neighborWeight, neighborVertex));
            }
        }
    }

    return make_pair(minimumSpanningTree, totalWeight);
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<pair<int, int>>> graph(numVertices);

    cout << "Enter the edges in the format (from to weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(make_pair(to, weight));
        graph[to].push_back(make_pair(from, weight)); // Since the graph is undirected
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    pair<vector<pair<int, int>>, int> result = primMST(graph, startVertex);

    cout << "Minimum Spanning Tree edges:" << endl;
    for (const pair<int, int>& edge : result.first) {
        cout << edge.first << " -- " << edge.second << " --> " << edge.first << endl;
    }

    cout << "Total Weight of Minimum Spanning Tree: " << result.second << endl;

    return 0;
}
