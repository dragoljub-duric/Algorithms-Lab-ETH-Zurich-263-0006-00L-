#include<bits/stdc++.h>

using namespace std;
int t, n, k;
vector<int> vec;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d",&n,&k);
        vec = vector<int>(n);
        for(int i = 0; i < n; ++i) scanf("%d",&vec[i]);
        int min_diff = INT_MAX, min_i = 0, min_j = 0, min_sum = INT_MAX, sum = vec[0];
        for(int i = 0, j = 0; i < n && sum != k; ++i){
            if(i != 0){
                sum -= vec[i - 1];
                if(j > i) sum -= vec[j--];
            }
            while(true){
                if(abs(k - sum) < min_diff || (abs(k - sum) == min_diff && sum < min_sum)){
                    min_diff = abs(k - sum); min_i = i; min_j = j; min_sum = sum;
                }
                if(j == n - 1 || sum >= k) break;
                sum += vec[++j];
            }
        }
        printf("%d %d\n", min_i, min_j);
    }
    return 0;
}