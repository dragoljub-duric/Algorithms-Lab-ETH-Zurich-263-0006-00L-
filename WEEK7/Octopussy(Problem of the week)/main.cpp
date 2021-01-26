#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, time; cin >> t;
    while(t--){
        cin >> n;
        vector<int> vec(n);
        for(int i = 0; i < n; ++i) cin >> vec[i];
        for(int i = 0; i <= (n-3)/2; ++i){
            vec[2*i + 1] = min(vec[2*i + 1], vec[i] - 1);
            vec[2*i + 2] = min(vec[2*i + 2], vec[i] - 1);
        }
        sort(vec.begin(), vec.end());
        int correct = true;
        for(int i = 0; i < n; ++i)
            if(vec[i] < i + 1){
                correct = false;
                break;
            }
        cout << (correct ? "yes\n" : "no\n");
    }
    return 0;
}