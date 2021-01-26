#include<bits/stdc++.h>
#include<CGAL/QP_models.h>
#include<CGAL/QP_functions.h>
#include<CGAL/Gmpz.h>
using namespace std;
typedef int IT;
typedef CGAL::Gmpz ET;
typedef CGAL::Quadratic_program<IT> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p, a, b;
    const int X = 0;
    const int Y = 1;
    const int Z = 2;
    while(true){
        cin >> p;
        if(p == 0) break;
        cin >> a >> b;
        Solution s;
        if(p == 1){
            Program lp(CGAL::SMALLER, true, 0, false, 0);
            lp.set_a(X, 0, 1); lp.set_a(Y, 0, 1); lp.set_b(0, 4);
            lp.set_a(X, 1, 4); lp.set_a(Y, 1, 2); lp.set_b(1, a*b);
            lp.set_a(X, 2, -1); lp.set_a(Y, 2, 1); lp.set_b(2, 1);
            lp.set_c(X, a); lp.set_c(Y, -1 * b); lp.set_c0(0);
            s = CGAL::solve_linear_program(lp, ET());
        }else{
            Program lp(CGAL::SMALLER, false, 0, true, 0);
            lp.set_a(X, 0, -1); lp.set_a(Y, 0, -1); lp.set_b(0, 4);
            lp.set_a(X, 1, -4); lp.set_a(Y, 1, -2); lp.set_a(Z, 1, -1); lp.set_b(1, a*b);
            lp.set_a(X, 2, 1); lp.set_a(Y, 2, -1); lp.set_b(2, 1);
            lp.set_c(X, a); lp.set_c(Y, b); lp.set_c(Z, 1);
            s = CGAL::solve_linear_program(lp, ET());
        }
        if(s.is_infeasible()) cout << "no\n";
        else if(s.is_unbounded()) cout << "unbounded\n";
        else{
            int val = ceil(CGAL::to_double(s.objective_value()));
            if(p == 1) val *= -1;
            cout << val << '\n';    
        }
    }
    return 0;
}