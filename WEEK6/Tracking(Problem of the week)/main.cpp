#include<bits/stdc++.h>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
using namespace std;
using namespace boost;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, int>> w_graph;
typedef boost::property_map<w_graph, boost::edge_weight_t>::type w_map;
typedef boost::graph_traits<w_graph>::edge_descriptor            edge_desc;
typedef boost::graph_traits<w_graph>::vertex_descriptor          vertex_desc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n, m, k, x, y, u, v, time, river; cin >> t;
    while(t--){
        cin >> n >> m >> k >> x >> y;
        w_graph G((k + 1)*n);
        w_map weights = boost::get(boost::edge_weight, G);
        edge_desc e;
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> time >> river;
            for(int i = 0; i <= k; ++i){
              e = boost::add_edge(n*i + u, n*i + v, G).first; 
              weights[e] = time;
            }
            if(river){
                for(int i = 0; i < k; ++i){
                    e = boost::add_edge(n*i + u, n*(i+1) + v, G).first; 
                    weights[e] = time;
                    e = boost::add_edge(n*(i+1) + u, n*i + v, G).first; 
                    weights[e] = time;
                }
            }
        }
        std::vector<int> dist_map((k+1)*n);
        boost::dijkstra_shortest_paths(G, x, boost::distance_map(boost::make_iterator_property_map(dist_map.begin(), boost::get(boost::vertex_index, G))));
        cout << dist_map[k*n + y] << "\n";
    }
    return 0;
}