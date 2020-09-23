#include <bits/stdc++.h>
using namespace std;
int t, n;
int even_subarrays(vector<int> arr){
    int even = 0, odd = 0, sum = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[i];
        if(sum % 2 == 0) even++; else odd++;
    }
    return (even - 1)*even/2 + (odd - 1)*odd/2 + even;
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        vector<vector<int>> mat(n, vector<int>(n));
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)scanf("%d",&mat[i][j]);
        int count = 0;
        for(int l = 0; l < n; ++l){
            vector<int> temp(n, 0);
            for(int r = l; r < n; ++r){
                for(int i = 0; i < n; ++i) temp[i] += mat[i][r];                       
                count += even_subarrays(temp);
            }
        }
        printf("%d\n", count);
    }
    return 0;
}