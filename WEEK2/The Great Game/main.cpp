#include<bits/stdc++.h>
using namespace std;
int t, n, m, u, v, r, b;
vector<vector<int>> adj;


int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d", &n, &m);
        adj = vector<vector<int>>(n);
        scanf("%d%d", &r, &b);
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &a, &b);
            --u, --v;
            adj[u].push_back(v);
        }
    }
    return 0;
}