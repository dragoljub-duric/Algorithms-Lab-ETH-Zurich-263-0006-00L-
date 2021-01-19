#include<bits/stdc++.h>
using namespace std;

long long dp(vector<vector<long long>>& memo, vector<vector<pair<int, int>>>& adj, int position, int moves){
    if(memo[position][moves] != -1) return memo[position][moves];
    long long maxi = -1;
    if(adj[position].size() == 0) maxi = dp(memo, adj, 0, moves);
    for(int i = 0; i < adj[position].size(); ++i) maxi = max(maxi, adj[position][i].second + dp(memo, adj, adj[position][i].first, moves -1));
    return memo[position][moves] = maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n, m, k; cin >> t;
    long long x;
    while(t--){
        cin >> n >> m >> x >> k;
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for(int i = 0; i < m; ++i){
            int u, v, p; cin >> u >> v >> p;
            adj[u].push_back(make_pair(v, p));
        }
        vector<vector<long long>> memo(n, vector<long long>(k+1, -1));
        for(int i = 0; i < n; ++i) memo[i][0] = 0;
        bool possible = false;
        for(int i = 1; i <= k && !possible; ++i)
            if(dp(memo, adj, 0, i) >= x){
                cout << i << "\n";
                possible = true;
            }
        if(!possible) cout << "Impossible" << "\n";
    }
    return 0;
}