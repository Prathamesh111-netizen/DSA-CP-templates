#include<bits/stdc++.h>

using namespace std;
int nodes, edges;
#define N 9
vector<int>parent(N, -1);
vector<int>size(N, -1);

void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if( v == parent[v]) return v;

    // path compression
    return parent[v] = find_set(parent[v]);
}

// union by size/rank
void union_sets(int a, int b){

    a = find_set(a),
    b = find_set(b);
    if (a != b){

        if (size[a] < size[b])
            swap(a, b); // a will always be maximum

        parent[b] = a;
        size[a] += size[b];
    }

}

void write(vector<int>arr, int n ){
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << " ]\n";
}

void kruskalAlgorithm(vector<pair<int,int>>graph[]){

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>minpq;

    for(int i = 0; i < nodes; i++)
        for (int j = 0; j < graph[i].size(); j++)
            minpq.push({graph[i][j].second, {i, graph[i][j].first}});
    
    int answer = 0;
    while (minpq.empty() == false){

        pair<int,pair<int,int>> x = minpq.top();
        minpq.pop();

        int u = x.second.first;
        int v = x.second.second;
        int w = x.first;

        if(parent[u] == -1 ) make_set(u);
        if(parent[v] == -1) make_set(v);

        if(find_set(u) != find_set(v)){
            union_sets(u, v);
            // cout << "u " << u << " v " << v << "\n";
            answer += w;
        }

    }
    write(parent, nodes);
    cout << answer << "\n";

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

    // for (int j = 0; j < nodes; j++ )
    //     for (int i = 0; i < graph[j].size(); i++ )
    //         cout << j << " " << graph[j][i].first << " " << graph[j][i].second << endl;

    kruskalAlgorithm(graph);

    
    return 0;
}