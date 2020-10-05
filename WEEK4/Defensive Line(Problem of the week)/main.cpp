#include<bits/stdc++.h>
#define INC -1e9
using namespace std;
int t, n, m, k;
vector<int> vec;
vector<vector<int>> memo;
vector<pair<int, int>> seg;

int binary(int l, int r, int x){
    if(l > r) return -1;
    int q = (r + l) / 2;
    if(seg[q].first == x) return q;
    if(seg[q].first > x) return binary(l, q - 1, x);
    return binary(q+1, r, x);
}

int dp(int att, int pos){
    if(memo[att][pos] != -1) return memo[att][pos];
    int max_val = INC, temp, ind = binary(0, seg.size() - 1, pos);
    if(ind != -1){
        //take segment starting at pos
        temp = dp(att - 1, seg[ind].second + 1);
        if (temp != INC) max_val = max(max_val, seg[ind].second - seg[ind].first + 1 + temp);
    }
    //or skip segment on the current position
    return memo[att][pos] = max(max_val, dp(att, pos + 1));
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &k);
        vec = vector<int>(n); memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1)); seg = vector<pair<int, int>>();
        for(int i = 0; i < n; ++i) scanf("%d", &vec[i]);
        for(int i = 0; i <= n; ++i) memo[0][i] = 0; for(int i = 1; i <= m; ++i) memo[i][n] = INC;
        int sum = 0, i = 0, j = 0;
        while(j < n){
            while(sum < k && j < n) sum += vec[j++];
            while(sum > k) sum -= vec[i++];
            if(sum == k)  seg.push_back(make_pair(i, j - 1)), sum -= vec[i++];
        }
        if(dp(m, 0) == INC) printf("fail\n");
        else printf("%d\n", memo[m][0]);
    }
    return 0;
}
