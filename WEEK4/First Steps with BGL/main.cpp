#include<iostream>
#include<vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, int> >      weighted_graph;
typedef boost::property_map<weighted_graph, boost::edge_weight_t>::type weight_map;
typedef boost::graph_traits<weighted_graph>::edge_descriptor            edge_desc;
typedef boost::graph_traits<weighted_graph>::vertex_descriptor          vertex_desc;

int kruskal(const weighted_graph& G, weight_map weights){
    std::vector<edge_desc> mst;
    boost::kruskal_minimum_spanning_tree(G, std::back_inserter(mst));
    int total_weight = 0;
    for(std::vector<edge_desc>:: iterator it = mst.begin(); it != mst.end(); ++it)
        total_weight += weights[*it];
    return total_weight;
}

int dist_to_furthest(const weighted_graph& G, int s){
    int n = boost::num_vertices(G);
    std::vector<int> dist_map(n);
    boost::dijkstra_shortest_paths(G, s, boost::distance_map(boost::make_iterator_property_map(dist_map.begin(), boost::get(boost::vertex_index, G))));
    int maxi = 0;
    for(int u : dist_map) maxi = std::max(maxi, u);
    return maxi;
}

int main(){
    int t, n, m, u, v, w;scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        weighted_graph G(n);
        weight_map weights = boost::get(boost::edge_weight, G);
        edge_desc e;
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &u, &v, &w);
            e = boost::add_edge(u, v, G).first; weights[e] = w;
        }
        printf("%d %d\n", kruskal(G, weights), dist_to_furthest(G, 0));
    }
    return 0;
}