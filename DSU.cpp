#include<bits/stdc++.h>

using namespace std;

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

        cout << "a " << a << " b " << b << endl;
    }

}

// signed main (int argc, char** argv){

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("debug.txt", "w", stderr);
//     #endif



//     return 0;
// }
