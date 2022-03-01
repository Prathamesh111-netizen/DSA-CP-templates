#include <bits/stdc++.h>

using namespace std;
int nodes, edges;

void write(vector<int>&arr, int n){
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "]\n";
}
void DijkstraShortestPath(int source, vector<pair<int, int>> graph[],
                          vector<int> &distance, vector<int> &parent)
{

    distance[source] = 0;

    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;

    minpq.push({0, source});

    while(minpq.empty() == false){
        pair<int,int>mini = minpq.top();
        minpq.pop();

        int dist = mini.first;
        int vertex = mini.second;

        for (int i = 0; i < graph[vertex].size(); i++ ){
            int v = graph[vertex][i].first;
            int w = graph[vertex][i].second;

            if(dist + w <= distance[v]){
                distance[v] = dist + w;
                parent[v] = vertex;
                minpq.push({dist+w , v});
            }
        }
    }

    write(distance, nodes);
    write(parent, nodes);
    
}
signed main(int argc, char **argv)
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);

    cin >> nodes >> edges;

    vector<pair<int, int>> graph[nodes];

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source = 0;
    vector<int> distance(nodes, INT_MAX), parent(nodes, -1);
    DijkstraShortestPath(source, graph, distance, parent);


    // for (int j = 0; j < nodes; j++ )
    //     for (int i = 0; i < graph[j].size(); i++ )
    //         cout << j << " " << graph[j][i].first << " " << graph[j][i].second << endl;

    return 0;
}