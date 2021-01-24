#include<bits/stdc++.h>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor>>>> graph;
typedef traits::vertex_descriptor vertex_desc;
typedef traits::edge_descriptor edge_desc;
class edge_adder {
  graph &G;
 public:
  explicit edge_adder(graph &G) : G(G) {}
  void add_edge(int from, int to, long capacity) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
    const auto e = boost::add_edge(from, to, G).first;
    const auto rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0; // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
  }
};

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, l, p, gi, di, fi, ti; cin >> t;
    while(t--){
        cin >> l >> p;
        graph G(l);
        const vertex_desc src = boost::add_vertex(G);
        const vertex_desc sink = boost::add_vertex(G);
        edge_adder edg(G);
        long long total_demand = 0, total_min_flow_cap = 0, min_flow, max_flow;
        for(int i = 0; i < l; ++i){
            cin >> gi >> di;
            edg.add_edge(src, i, gi);
            edg.add_edge(i, sink, di);
            total_demand += di;
        }
        for(int i = 0; i < p; ++i){
            cin >> fi >> ti >> min_flow >> max_flow;
            edg.add_edge(src, ti, min_flow);
            edg.add_edge(fi, sink, min_flow);
            edg.add_edge(fi, ti, max_flow - min_flow);
            total_min_flow_cap += min_flow;
        }
        long long flow = push_relabel_max_flow(G, src, sink);
        cout << (flow >= total_demand + total_min_flow_cap ? "yes\n" : "no\n");
    }
    return 0;
}