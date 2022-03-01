#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define mod1 998244353
#define inf 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define size(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
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

class huffman_Node{
    public :

    char value;
    int freq;
    huffman_Node *left, *right;

    huffman_Node(char value, int freq, huffman_Node* left, huffman_Node* right){
        this->value = value;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

class huffman_tree{
    public :
        huffman_Node* root;

        huffman_tree(){
            root = NULL;
        }
   

};
huffman_tree* tree;

class Compare
{
public:
    bool operator() (huffman_Node* a, huffman_Node* b)
    {
        return a->freq > b->freq;
    }
};

bool checkLeaf(huffman_Node* current){
    return current->left == NULL && current->right == NULL;
}

map<char, string>table;
void print(huffman_Node * root, string s){
    
    if(root == NULL)
        return;

    if(checkLeaf(root)){
        table.insert({root->value, s});
        s = s.substr(0, size(s) - 1);
        return;
    }
    
    print(root->left, s + "1");
    print(root->right, s + "0");
}

string huffmanencoding( priority_queue<huffman_Node*, vector<huffman_Node*>, Compare> &minpq){
    tree = new huffman_tree();

    while(size(minpq) > 1){
        huffman_Node *left = minpq.top();
        minpq.pop();
        huffman_Node *right = minpq.top();
        minpq.pop();


        huffman_Node* newnode = new huffman_Node('#', left->freq + right->freq, left, right);
        minpq.push(newnode);
        tree->root = newnode;
    }
    print(tree->root, "");
}

string huffmandecoding(string encoded_string){
    string decoded_string = "";

    int i = 0;
    huffman_Node* current = tree->root;

    while(i < size(encoded_string)){

        if(encoded_string[i] == '1') // left
            current = current -> left;
        else // right
            current = current -> right;


        if(checkLeaf(current)){
            decoded_string += current->value;
            current = tree->root;
        }
        i++;
    }

    return decoded_string;
}

signed main(int argc, char **argv){
    fastio();
    init_code();
    debug_code();

    string s; cin >> s;

    // create a empty tree

    map<char, int>mp;
    for(auto x : s)
        mp[x]++;
    
    priority_queue<huffman_Node*, vector<huffman_Node*>, Compare>minpq;

    for (auto x : mp){
        huffman_Node* newnode = new huffman_Node(x.first, x.second, NULL, NULL);
        minpq.push(newnode);
    }

    huffmanencoding(minpq);

    for (auto x : table)
        cout << x.first << " " << x.second << nline;

    string encoded_string = "";
    for (auto x : s){
        auto itr = table.find(x);
        if(itr != table.end())
            encoded_string += itr->second;
    }
    cout << encoded_string << nline;

    cout << huffmandecoding(encoded_string) << nline;

    return 0;


}

