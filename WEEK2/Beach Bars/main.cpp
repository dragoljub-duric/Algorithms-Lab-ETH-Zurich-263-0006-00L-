#include<bits/stdc++.h>
using namespace std;
int t, n;
vector<int> vec;

int binary_search(int l, int r, int target){
    if(l == r) return l;
    int q = (l + r) / 2;
    if(vec[q] == target || (vec[q] < target && (q + 1 == n || vec[q + 1] > target))) return q;
    if(vec[q] < target) return binary_search(q + 1, r, target);
    return binary_search(l, q - 1, target);
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        vec = vector<int>(n); vector<int> locations; int max_num = 0, min_size = INT_MAX;
        for(int i = 0; i < n; scanf("%d", &vec[i++]));
        sort(vec.begin(), vec.end());
        for(int i = 0; i < n; ++i){
            int j = binary_search(i, n - 1, vec[i] + 200), curr_num = j - i + 1, add = abs(vec[i] - vec[j]) % 2 == 1, curr_size = (abs(vec[i] - vec[j]) + add) / 2;
            if(curr_num > max_num || (curr_num == max_num && curr_size < min_size)){
                max_num = curr_num, min_size = curr_size, locations = vector<int>({vec[i] + curr_size - add});
                if(add) locations.push_back(vec[i] + curr_size);
            }else if(curr_num == max_num && curr_size == min_size){
                locations.push_back(vec[i] + curr_size - add);
                if(add) locations.push_back(vec[i] + curr_size);
            }
        }
        printf("%d %d\n", max_num, min_size);
        for(int v : locations) printf("%d ", v);
        printf("\n");
    }
}
