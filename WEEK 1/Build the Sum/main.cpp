#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; scanf("%d",&t);
    while(t--){
        int n, a, sum = 0; scanf("%d",&n);
        for(int i = 0; i < n; scanf("%d",&a), sum += a, ++i);
        printf("%d\n",sum);
    }
    return 0;
}