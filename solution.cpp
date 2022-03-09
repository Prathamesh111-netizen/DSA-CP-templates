#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define mod1 998244353
#define inf 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define read(arr, n)            \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define write(arr, n)          \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " " ; \
    cout << "\n" ; 
#define loop(i, n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void debug_code()
{
    #ifndef ONLINE_JUDGE
    freopen("debug.txt", "w", stderr);
    #endif
}

// Solution 1 : recursion 
long long knapsack01_1(vector<int>&weight, vector<int>&value, int capacity, int i){

    if(capacity == 0 || i < 0)
        return 0;
    
    if(weight[i] <= capacity){
        return max(value[i] + knapsack01_1(weight, value, capacity - weight[i], i - 1 ), 
                    knapsack01_1(weight, value, capacity , i -1 ));
    }
    else{
        return knapsack01_1(weight, value, capacity , i - 1 );
    }

}

// Solution 2 : recursion + memoization
vector<vector<long long>>dp2;
long long knapsack01_2(vector<int>&weight, vector<int>&value, int capacity, int i){

    if(capacity == 0 || i < 0)
        return 0;

    if(dp2[i][capacity] != -1)
        return dp2[i][capacity];
    
    if(weight[i] <= capacity){
        return dp2[i][capacity] = max(value[i] + knapsack01_2(weight, value, capacity - weight[i], i - 1 ), 
                    knapsack01_2(weight, value, capacity , i -1 ));
    }
    else{
        return dp2[i][capacity] = knapsack01_2(weight, value, capacity , i - 1 );
    }

}


// solution 3 : dynamic programming
vector<vector<long long>>dp;
void knapsack01(vector<int>&weight, vector<int>&value, int capacity, int n){

    dp.resize(n + 1, vector<long long>(capacity + 1, -1));
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= capacity; i++)
        dp[0][i] = 0;
    
    for (int j = 1; j <= n; j++){
        for (int i = 1; i <= capacity; i++){
            if(i >= weight[j - 1]){
                dp[j][i] = max(value[j-1] + dp[j - 1][i - weight[j - 1]], dp[j-1][i]);
            }
            else{
                dp[j][i] = dp[j-1][i];
            }
        }
    }       



    for (int j = 0; j <= n; j++, cerr << nline)
        for (int i = 0; i <= capacity; i++)
            cerr << dp[j][i] << " ";


    // Item Selection
    set<int>items;
    int j = capacity;
    for (int j = n; j >= 1; j--){
        if(dp[j][capacity] != dp[j - 1][capacity]){
            items.insert(j);
            capacity -= weight[j - 1];
        }
    }

    cerr << endl;
    debug(items);

}


signed main(int argc, char **argv){
    fastio();
    init_code();
    debug_code();
    clock_t clkStart, clkFinish;
    clkStart = clock();
    
    int n; cin >> n;
    vector<int>weight(n), value(n);
    read(weight, n);
    read(value, n);

    int capacity; cin >> capacity;

    // normal recursion
    // cout <<  knapsack01_1(weight, value, capacity, n - 1) << nline;


    // // recursion + memoization
    // dp2.resize(n + 1, vector<long long>(capacity + 1, -1));
    // cout <<  knapsack01_2(weight, value, capacity, n - 1) << nline;


    // dynamic programming
    knapsack01(weight, value, capacity, n);
    

    clkFinish = clock();
    cerr << "Finished in " <<  (double)(clkFinish - clkStart)/1000 << " sec" << endl;

    return 0;


}

