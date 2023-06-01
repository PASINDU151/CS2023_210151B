#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent a city and its distance from the source city
struct City {
    int id;
    int distance;
};

// Comparator for the priority queue
struct CityComparator {
    bool operator()(const City& c1, const City& c2) {
        return c1.distance > c2.distance;
    }
};

// Function to find the shortest time between the source city and all other cities
void findShortestTime(const vector<vector<int>>& graph, int source) {
    int numCities = graph.size();
    vector<int> distances(numCities, INT_MAX);  // Stores the shortest time from the source city
    vector<int> parent(numCities, -1);          // Stores the parent city of each city in the shortest path
    vector<bool> visited(numCities, false);     // Tracks visited cities

    // Priority queue to store cities and their distances
    priority_queue<City, vector<City>, CityComparator> pq;

    // Enqueue the source city with a distance of 0
    pq.push({source, 0});
    distances[source] = 0;

    while (!pq.empty()) {
        // Dequeue the city with the minimum distance
        City currentCity = pq.top();
        pq.pop();

        int city = currentCity.id;

        // Skip if the city is already visited
        if (visited[city]) {
            continue;
        }

        visited[city] = true;

        // Explore all neighboring cities
        for (int neighbor = 0; neighbor < numCities; neighbor++) {
            int travelTime = graph[city][neighbor];

            // Update distance if a shorter path is found
            if (travelTime > 0 && distances[city] + travelTime < distances[neighbor]) {
                distances[neighbor] = distances[city] + travelTime;
                parent[neighbor] = city;
                pq.push({neighbor, distances[neighbor]});
            }
        }
    }

    // Print the shortest time and path from the source city to each city
    for (int city = 0; city < numCities; city++) {
        cout << "From " << source << " to " << city << " : " << distances[city] << endl;

        // Print the shortest path
        cout << " (Path: ";
        int node = city;
        while (node != -1) {
            cout << node;
            node = parent[node];
            if (node != -1) {
                cout << " -> ";
            }
        }
        cout << ")" << endl;
    }
   
}

int main() {
   
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int sourceCity = 5;  

    findShortestTime(graph, sourceCity);

    return 0;
}
