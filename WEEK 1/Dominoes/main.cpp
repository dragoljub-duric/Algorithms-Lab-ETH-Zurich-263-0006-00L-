#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n; scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int m, h, i, j; scanf("%d", &m); --m;
        for(i = 1; i < n && i <= m; ++i){
            scanf("%d", &h);
            j = h + i - 1, m = m > j ? m : j;
        }
        for(; i < n; scanf("%d", &h), ++i);
        ++m;
        printf("%d\n", min(m,n));
    }
    return 0;
}