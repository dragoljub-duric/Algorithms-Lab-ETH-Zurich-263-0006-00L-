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
    int n, m, mini, maxi, cost, amount;
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        Program lp(CGAL::SMALLER, true, 0, false, 0);
        for(int i = 0; i < n; ++i){
            cin >> mini >> maxi;
            lp.set_b(i, -1 * mini); 
            lp.set_b(n + i, maxi);
        }
        for(int i = 0; i < m; ++i){
            cin >> cost;
            lp.set_c(i, cost);
            for(int j = 0; j < n; ++j){
                cin >> amount;
                lp.set_a(i, j, -1 * amount);
                lp.set_a(i, n + j, amount);
            }
        }
        Solution s = CGAL::solve_linear_program(lp, ET());;
        if(s.is_infeasible()) cout << "No such diet.\n";
        else if(s.is_unbounded()) cout << "unbounded\n";
        else{
            int val = floor(CGAL::to_double(s.objective_value()));
            cout << val << '\n';    
        }
    }
    return 0;
}