#include<bits/stdc++.h>
using namespace std;
int t, n;
vector<int> vec;
vector<vector<int>> memo; vector<vector<int>> mv;

int dp(int l, int r);

void next_position(int l, int r, int m, int& new_l, int& new_r){
    new_l = l + (1 - m), new_r = r - m;
    dp(new_l, new_r);
    int opponent = mv[new_l][new_r];
    new_l = new_l + (1 - opponent);
    new_r = new_r - opponent;
}

int dp(int l, int r){
    if(l > r) return 0;
    if(memo[l][r] != -1) return memo[l][r];
    int new_l, new_r;
    //take left
    next_position(l, r, 0, new_l, new_r);
    int sum_left = vec[l] + dp(new_l, new_r);
    //take right
    next_position(l, r, 1, new_l, new_r);
    int sum_right = vec[r] + dp(new_l, new_r);
    //choose move
    if(sum_left > sum_right){
        mv[l][r] = 0;
        return memo[l][r] = sum_left;
    }
    mv[l][r] = 1;
    return memo[l][r] = sum_right;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vec = vector<int>(n); 
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        mv = vector<vector<int>>(n, vector<int>(n, -1));
        for(int i = 0; i < n; ++i){
            scanf("%d",&vec[i]);
            memo[i][i] = vec[i]; 
            mv[i][i] = 0;
        }
        dp(0, n-1);
        printf("%d\n",memo[0][n-1]);
    }
    return 0;
}
