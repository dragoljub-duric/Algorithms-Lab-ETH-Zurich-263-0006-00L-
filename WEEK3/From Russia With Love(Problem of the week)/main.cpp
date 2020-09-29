#include<bits/stdc++.h>
#define part_sum(a, b) partial[b] - (a == 0 ? 0 : partial[a - 1])
using namespace std;
int t, n, m, k;
vector<int> vec, partial;
vector<vector<int>> memo;
vector<vector<pair<int, int>>> mv;

int dp(int l, int r, int p){
    if(l > r) return 0;
    if(memo[l][r] != -1) return memo[l][r];
    int count = p == 0 ? 1 : m - 1;
    if(r - l < count){
        mv[l][r] = make_pair(l + 1, l);
        return memo[l][r] = part_sum(l, r);
    }
    int max_sum = -1;  pair<int, int> pos_max;
    for(int i = 0; i <= count; ++i){
        int curr_l = l + i, curr_r = r - (count - i);
        dp(curr_l, curr_r, (p + 1) % 2);
        int next_l = mv[curr_l][curr_r].first, next_r = mv[curr_l][curr_r].second, curr_sum = part_sum(l, curr_l - 1) + part_sum(curr_r + 1, r) + dp(next_l, next_r, p);
        if(curr_sum > max_sum) max_sum = curr_sum, pos_max = make_pair(curr_l, curr_r);
    }
    mv[l][r] = pos_max;
    return memo[l][r] = max_sum;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d", &n, &m, &k);
        vec = vector<int>(n); partial = vector<int>(n);
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        mv = vector<vector<pair<int, int>>>(n, vector<pair<int,int>>(n, make_pair(-1, -1)));
        for(int i = 0; i < n; ++i){
            scanf("%d",&vec[i]);
            memo[i][i] = vec[i];
            mv[i][i] = make_pair(i+1, i);
        }
        partial[0] = vec[0];
        for(int i = 1; i < n; ++i) partial[i] = vec[i] + partial[i - 1];
        int min = INT32_MAX;
        for(int i = 0; i <= k; ++i){
            int curr = dp(i, n - k + i - 1, 0);
            if(curr < min) min = curr;
        }
        printf("%d\n", min);
    }
    return 0;
}