#include<bits/stdc++.h>
#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

int main(){
    int n;
    scanf("%d", &n);
    while(n){
        long long s1, e1, s2, e2;
        scanf("%lld%lld%lld%lld", &s1, &e1, &s2, &e2);
        K::Point_2 s_r(s1, e1), e_r(s2, e2);
        K::Ray_2 ray(s_r, e_r);
        bool found =  false;
        for(int i = 0; i < n; ++i){
            scanf("%lld%lld%lld%lld", &s1, &e1, &s2, &e2);
            if(!found){
                K::Point_2 s_s(s1, e1), e_s(s2, e2);
                K::Segment_2 seg(s_s, e_s);
                found = CGAL::do_intersect(ray, seg);
            }
        }
        printf(found ? "yes\n":"no\n");
        scanf("%d", &n);
    }
    return 0;
}