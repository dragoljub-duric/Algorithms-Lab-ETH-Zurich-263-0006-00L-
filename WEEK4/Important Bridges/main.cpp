#include<bits/stdc++.h>
using namespace std;
struct Vertex{
    int low = -1, discovery = -1, parent = -1;
};

int c, n, m, u, v;
vector<Vertex> vertices;
vector<vector<int>> adj;
vector<pair<int, int>> bridges;

void bridge_util(int s){
    static int time = 0;
    vertices[s].low = vertices[s].discovery = ++time;
    for(int v : adj[s]){
        if(vertices[v].discovery == -1){
            vertices[v].parent = s;
            bridge_util(v);
            vertices[s].low = min(vertices[s].low, vertices[v].low);
            if(vertices[v].low > vertices[s].discovery)
                bridges.push_back(make_pair(min(s, v), max(s, v)));
        }
        else if(v != vertices[s].parent)
            vertices[s].low = min(vertices[s].low, vertices[v].low);
    }
}

void bridge(){
    for(int i = 0; i < n; ++i)
        if(vertices[i].discovery == -1)
            bridge_util(i);
}

const bool operator<(pair<int, int> a, pair<int, int> b){
    return a.first < b.first || a.first == b.first && a.second < b.second;
}

int main(){
    scanf("%d", &c);
    while(c--){
        scanf("%d%d", &n, &m);
        vertices = vector<Vertex>(n);
        adj = vector<vector<int>>(n, vector<int>());
        bridges = vector<pair<int, int>>();
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bridge();
        printf("%d\n", bridges.size());
        sort(bridges.begin(), bridges.end());
        for(pair<int, int> b : bridges){
            printf("%d %d\n", b.first, b.second);
        }
    }
    return 0;
}