#include<bits/stdc++.h>
#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include<CGAL/Delaunay_triangulation_2.h>
using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Triangulation;
typedef Triangulation::Finite_faces_iterator Face_iterator;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int n, m, x, y; cin >> n;
        if(n == 0) break;
        vector<K::Point_2> vec;
        vec.reserve(n);
        for(int i = 0; i < n; ++i){
            cin >> x >> y;
            vec.push_back(K::Point_2(x, y));
        }
        Triangulation t;
        t.insert(vec.begin(), vec.end());
        cin >> m;
        for(int i = 0; i < m; ++i){
            cin >> x >> y;
            K::Point_2 p(x, y);
            cout << fixed << setprecision(0) << CGAL::squared_distance(p, t.nearest_vertex(p) -> point()) << '\n';
        }
    }
    return 0;
}