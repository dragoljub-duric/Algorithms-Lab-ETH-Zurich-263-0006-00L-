#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n, even = 0, odd = 0, sum = 0, c; scanf("%d",&n);
        for(int i = 0; i < n; ++i){
            scanf("%d",&c); sum += c;
            if(sum % 2 == 0) even++; else odd++;
        }
        printf("%d\n", ((even - 1)*even/2 + (odd - 1)*odd/2 + even));
    }
    return 0;
}