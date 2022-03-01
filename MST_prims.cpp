#include<bits/stdc++.h>

using namespace std;
int nodes, edges;

void primsAlgorithm(vector<pair<int,int>>graph[]){

    vector<int>key(nodes, INT_MAX);
    vector<bool>mstSet(nodes, false);
    vector<int>parent(nodes, -1);

    // brute force
    int index = 0;
    key[index] = 0;

    for (int i = 1; i < nodes - 1; i++){

        int mini = INT_MAX, u;

        for (int j = 0; j < nodes; j++) 
            if(mstSet[j] == false && key[j] < mini)
                mini = key[j], u = j;
        mstSet[u] = true;

        for (int j = 0; j < graph[u].size(); j++){
            
            int v = graph[u][j].first ,
                w = graph[u][j].second ;

            if (mstSet[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    for (int i = 1; i < nodes; i++)
        cout << parent[i] << " - > " << i << "\n";
}



signed main(int argc, char **argv){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    cin >> nodes >> edges;
    vector<pair<int,int>>graph[nodes];

    for (int i = 0; i < edges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    primsAlgorithm(graph);


    return 0;
}