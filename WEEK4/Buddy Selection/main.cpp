#include<bits/stdc++.h>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>      graph;
typedef boost::graph_traits<graph>::edge_descriptor            edge_desc;
typedef boost::graph_traits<graph>::vertex_descriptor          vertex_desc;


bool check(std::vector<std::string> a, std::vector<std::string> b, int f){
    int i = 0, j = 0, len = a.size(), count = 0, res;
    while(i < len && j < len){
        res = a[i].compare(b[j]);
        if(res == 0) ++count, ++i, ++j;
        else if (res < 0) ++i;
        else ++j;
    }
    return count > f;
}

bool perfect_matching(const graph& G, int n){
    std::map<vertex_desc, vertex_desc> match;
    boost::associative_property_map<std::map<vertex_desc, vertex_desc>> mapAdapter(match);
    boost::checked_edmonds_maximum_cardinality_matching(G, mapAdapter);
    int count = 0;
    for(std::pair<vertex_desc, vertex_desc> a : match)
        if(a.second < n) ++count;
    return count == n;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std :: cin.tie(NULL);
    int t, n, c, f; 
    std::cin >> t;
    while(t--){
        std::cin >> n >> c >> f;
        graph G(n);
        edge_desc e;
        std::vector<std::vector<std::string>> vec(n, std::vector<std::string>(c));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < c; ++j) std::cin >> vec[i][j];
            std::sort(vec[i].begin(), vec[i].end());
            for(int k = 0; k < i; ++k)
                if(check(vec[i], vec[k], f))
                    boost::add_edge(i, k, G);
        }
        std::cout << (perfect_matching(G, n)? "not optimal" : "optimal") << "\n";
    }
    return 0;
}