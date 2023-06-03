#include <iostream>
#include <climits>

#define V 6 // Number of vertices in the graph

int findMinKey(int key[], bool mstSet[]) {
    int minKey = INT_MAX, minIndex;
    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int graph[V][V]) {
    std::cout << "Edge \tWeight\n";
    std::cout << parent[1] << " - " << 1 << "\t" << graph[1][parent[1]] << std::endl;
    for (int v = 2; v < V; ++v) {
        std::cout <<  "0 - " << v << "\t" << graph[v][parent[v]]+graph[parent[v]][parent[v-1]] << std::endl;
    }
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; ++i) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 15, 0, 4, 0}
    };

    primMST(graph);

    return 0;
}
