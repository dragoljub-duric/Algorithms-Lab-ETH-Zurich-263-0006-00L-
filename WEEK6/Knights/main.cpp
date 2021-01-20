#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>

using namespace std;
using namespace boost;
typedef adjacency_list_traits<vecS, vecS, directedS> Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
    property<edge_capacity_t, long,
        property<edge_residual_capacity_t, long, property<edge_reverse_t, Traits::edge_descriptor>>>> Graph;
typedef property_map<Graph, edge_capacity_t>::type EdgeCapacityMap;
typedef property_map<Graph, edge_residual_capacity_t>::type ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type ReverseEdgeMap;
typedef graph_traits<Graph>::edge_descriptor Edge;

struct Helper {
    Graph &G;
    EdgeCapacityMap &capacitymap;
    ReverseEdgeMap &revmap;

    Helper(Graph &G, EdgeCapacityMap &capacitymap, ReverseEdgeMap &revmap) : G(G), capacitymap(capacitymap),
                                                                             revmap(revmap) {}

    void addEdge(int source, int target, int capacity) {
        Edge e, rev_e;
        bool success;
        tie(e, success) = add_edge(source, target, G);
        tie(rev_e, success) = add_edge(target, source, G);
        capacitymap[e] = capacity, capacitymap[rev_e] = 0;
        revmap[e] = rev_e, revmap[rev_e] = e;
    }
};

int main() {
    int T, m, n, k, c;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &m, &n, &k, &c);
        int siz = max(m, n), s = siz * siz * 2 + 2, t = s + 1, p1, p2;
        Graph G(t + 1);
        EdgeCapacityMap edgeCap = get(edge_capacity, G);
        ReverseEdgeMap revEdge = get(edge_reverse, G);
        ResidualCapacityMap resCap = get(edge_residual_capacity, G);
        Helper helper(G, edgeCap, revEdge);

        for (int i = 0; i < k; i++) {
            scanf("%d%d", &p1, &p2);
            //connect s to knight's in node
            helper.addEdge(s, (p2 * siz + p1) * 2, 1);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //intersection split in 2 nodes, connected
                //with edge of capacity c
                int in_node = (i * siz + j) * 2;
                int out_node = in_node + 1;
                helper.addEdge(in_node, out_node, c);
                //connect segments which are neighbours
                if (i != 0) helper.addEdge(out_node, ((i - 1) * siz + j) * 2, 1);
                if (i != n - 1) helper.addEdge(out_node, ((i + 1) * siz + j) * 2, 1);
                if (j != 0) helper.addEdge(out_node, (i * siz + j - 1) * 2, 1);
                if (j != m - 1) helper.addEdge(out_node, (i * siz + j + 1) * 2, 1);
                //connect segments on border to t
                if (i == 0 || i == n - 1) helper.addEdge(out_node, t, 1);
                if (j == 0 || j == m - 1) helper.addEdge(out_node, t, 1);
            }
        }
        int flow = push_relabel_max_flow(G, s, t);
        printf("%d\n", flow);
    }
    return 0;
}