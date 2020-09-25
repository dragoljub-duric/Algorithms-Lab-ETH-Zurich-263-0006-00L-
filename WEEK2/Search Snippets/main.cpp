#include<bits/stdc++.h>
using namespace std;
int t, n;
vector<int> vec;
vector<vector<int>> text;

struct s{
    int row, ind, pos;
    s(int row, int ind, int pos) : row(row), ind(ind), pos(pos){}
};

int operator<(const s& a, const s& b){
    return a.pos > b.pos;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        vec = vector<int>(n);
        text = vector<vector<int>>(n);
        for(int i = 0; i < n; scanf("%d", &vec[i++]));
        for(int i = 0; i < n; ++i){
            text[i] = vector<int>(vec[i]);
            for(int j = 0; j < vec[i]; ++j) scanf("%d", &text[i][j]);
        }
        priority_queue<s> q;
        int min_diff = INT32_MAX, diff, max = -1;
        for(int i = 0; i < n; ++i){
            q.push(s(i, 0, text[i][0]));
            if(text[i][0] > max) max = text[i][0];
        }
        while(true){
            s curr = q.top(); q.pop();
            diff = max - curr.pos + 1;
            min_diff = diff < min_diff ? diff : min_diff;
            if(curr.ind != vec[curr.row] - 1){
                s b(curr.row, curr.ind + 1, text[curr.row][curr.ind + 1]);
                q.push(b);
                max = b.pos > max ? b.pos : max;
            }else break;
        }
        printf("%d\n",min_diff);
    }
    return 0;
}
