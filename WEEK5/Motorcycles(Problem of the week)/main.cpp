#include<bits/stdc++.h>
#include<CGAL/Exact_predicates_exact_constructions_kernel.h>
typedef CGAL::Exact_predicates_exact_constructions_kernel K;

using namespace std;
struct Biker{
    K::Ray_2 ray;
    int ind;
    K::FT slope;
    Biker(K::Ray_2 ray, int ind, K::FT slope): ray(ray), ind(ind), slope(slope){}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n; cin >> t;
    long long y0, x1, y1;
    while(t--){
        cin >> n;
        vector<Biker> bikers;
        for(int i = 0; i < n; ++i){
            cin >> y0 >> x1 >> y1;
            K::Ray_2 b(K::Point_2(0, y0), K::Point_2(x1, y1));
            K::FT slope = (K::FT(y1 - y0))/(K::FT(x1));
            bikers.push_back(Biker(b, i, slope));
        }
        sort(bikers.begin(), bikers.end(), [](const Biker& a, const Biker& b) -> bool {return a.ray.source().y() > b.ray.source().y();});
        vector<Biker> left;
        Biker main_slope = bikers[0];
        left.push_back(main_slope);
        for(int i = 1; i < n; ++i){
            if(bikers[i].slope <= main_slope.slope){
                left.push_back(bikers[i]);
                main_slope = bikers[i];
                continue;
            }
            if(abs(bikers[i].slope) <= abs(main_slope.slope)){
                int start_to_delete = left.size();
                while(start_to_delete > 0 && CGAL::do_intersect(bikers[i].ray, left[start_to_delete - 1].ray) && abs(bikers[i].slope) <= abs(left[start_to_delete - 1].slope))
                    --start_to_delete;
                left.erase(left.begin() + start_to_delete, left.end());
                if(start_to_delete == 0 || bikers[i].slope <= left[start_to_delete - 1].slope){
                    left.push_back(bikers[i]);
                    main_slope = bikers[i];
                }
            }
        }
        sort(left.begin(), left.end(),  [](const Biker& a, const Biker& b) -> bool {return a.ind < b.ind;});
        for(int i = 0; i < left.size(); ++i) cout << left[i].ind << " ";
        cout << "\n";
    }
    return 0;
}