#include<bits/stdc++.h>
using namespace std;
int t, n, m, r, b, u, v;
vector<vector<int>> adj, memo;

int dp(int s, int move){
    if(memo[s][move] != -1) return memo[s][move];
    if(move == 0){
        int min_s = INT32_MAX;
        for(int v : adj[s]) min_s = min(min_s, dp(v, 1));
        return memo[s][move] = min_s + 1;
    }
    int max_s = 0;
    for(int v : adj[s]) max_s = max(max_s, dp(v, 0));
    return memo[s][move] = max_s + 1;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d", &n, &m, &r, &b);
        adj = vector<vector<int>>(n);
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &u, &v);
            adj[u - 1].push_back(v - 1);
        }
        memo = vector<vector<int>>(n, vector<int>(2, -1)); memo[n-1][0] = memo[n - 1][1] = 0;
        int red = dp(r - 1, 0);
        memo = vector<vector<int>>(n, vector<int>(2, -1)); memo[n-1][0] = memo[n - 1][1] = 0;
        int black = dp(b - 1, 0);
        if(red - black != 0) printf("%d\n", red > black);
        else printf("%d\n", (red + black) % 4 == 0 || (red + black) % 4 == 3);
    }
    return 0;
}
