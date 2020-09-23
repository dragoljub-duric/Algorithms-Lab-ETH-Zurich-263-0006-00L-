#include<bits/stdc++.h>
using namespace std;
int t, n;
vector<int> vec;
vector<vector<int>> memo1; vector<vector<int>> memo2; vector<vector<int>> move1; vector<vector<int>> move2;

int dp(int l, int r, int p){
    if(l > r) return 0;
    vector<vector<int>>& m1 = p == 0 ? memo1 : memo2; 
    if(m1[l][r] != -1) return m1[l][r];
    vector<vector<int>>& mv1 = p == 0 ? move1 : move2; 
    vector<vector<int>>& mv2 = p == 0 ? move2 : move1;
    //take left
    dp(l + 1, r, (p + 1) % 2);
    int opponent = mv2[l+1][r];
    int new_l = l + 1 + (1 - opponent), new_r = r - opponent;
    int sum_left = vec[l] + dp(new_l, new_r, p);
    //take right
    dp(l, r - 1, (p + 1) % 2);
    opponent = mv2[l][r-1];
    new_l = l + (1 - opponent); new_r = r - 1 - opponent;
    int sum_right = vec[r] + dp(new_l, new_r, p);
    //choose move
    if(sum_left > sum_right){
        mv1[l][r] = 0;
        return m1[l][r] = sum_left;
    }
    mv1[l][r] = 1;
    return m1[l][r] = sum_right;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vec = vector<int>(n); memo1 = vector<vector<int>>(n, vector<int>(n, -1)); memo2 = vector<vector<int>>(n, vector<int>(n, -1));
        move1 = vector<vector<int>>(n, vector<int>(n, -1)); move2 = vector<vector<int>>(n, vector<int>(n, -1));
        for(int i = 0; i < n; ++i){
            scanf("%d",&vec[i]);
            memo1[i][i] = memo2[i][i] = vec[i]; 
            move1[i][i] = move2[i][i] = 0;
        }
        dp(0, n-1, 0);
        printf("%d\n",memo1[0][n-1]);
    }
    return 0;
}