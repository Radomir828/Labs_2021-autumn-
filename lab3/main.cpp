#include<iostream>
#include<vector>
#include<set>
#include <queue>

#define nV 4
const int INF = 99999;
using namespace std;
typedef vector<pair<int,int>> Node;
typedef vector<Node> adj_list;      // or graph(representig graph as adjency list)

void dijkstra_algorithm (int source_node, adj_list& graph) {

    vector<int> dist(graph.size(), INF);
    set<pair<int, int>> set_container;

    dist[source_node] = 0;
    set_container.insert(pair<int, int> (0, source_node));

    while (!set_container.empty()) {

        auto top = set_container.begin();                    //  U ovom dijelu dobijamo pointer na prvi element u set(taj element sadrzi pair<weight, node>)
        int current_source_node = top->second;                          //  top je pointer, top->second ukazuje na node koji uzimamo za trenutni source node
        set_container.erase(top);                               //  Micemo taj element iz seta(tj micemo prvi element iz seta jer on ima najmanju weight)

        for (int i = 0; i < graph[current_source_node].size() ; i++) {

            int adj_node = graph[current_source_node][i].first;
            int length_to_adjnode = graph[current_source_node][i].second;

            if (dist[adj_node] > length_to_adjnode + dist[current_source_node]) {

                if (dist[adj_node] != INF) {
                    set_container.erase(set_container.find(pair<int, int>(dist[adj_node], adj_node)));
                }
                dist[adj_node] = length_to_adjnode + dist[current_source_node];
                set_container.insert(pair<int, int>(dist[adj_node], adj_node));
            }
        }
    }

    for (int i = 0; i < graph.size(); i++)
        cout << "Source Node(" << source_node << ") -> Destination Node(" << i << ") : " << dist[i] << endl;
}

void printList(adj_list& adj)
{
    for (int i = 0; i < adj.size(); i++) {
        cout << "Node: " << i;
        for (int j = 0; j < adj[i].size(); j++) {
            cout << "--> (" << adj[i][j].first << "|" << adj[i][j].second << ") ";

        }
        cout << endl;
    }
    cout << endl;
}


/*

void algorithm_floid (vector<Node> &graph, int u){
    vector<vector<int>> mtrx(graph.size(), vector<int>(graph.size(), INT32_MAX));

    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].edges.size(); ++j) {j
            if (i == j) {
                mtrx[i][j] = 0;
            } else {
                mtrx[i][graph[i].edges[j].to_] = graph[i].edges[j].weight_;
            }
        }
    }

    for (int k = 0; k < graph.size(); k++) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                mtrx[i][j] = min(mtrx[i][j], mtrx[i][k] + mtrx[k][j]);
            }
        }
    }
    vector<int>dist = mtrx[u];

};
*/

void Floyd_Warshall(adj_list& graph) {

    vector<vector<int>> distance;
    for (int i = 0; i < graph.size(); i++) {
        distance[i][i] = 0;
    }

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); ++j) {
            int u = i;
            int v = graph[i][j].first;
            distance[u][v] = graph[i][j].second;

        }
    }

    for (int k = 0; k < graph.size(); k++) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    cout << "Shortest distance between nodes" << endl;
    for (int u = 0; u < graph.size(); u++) {
        for (int v = u + 1; v < graph.size(); v++) {
            cout << "\nDistance ( " << u << " - " << v << " ) : " << distance[u][v] << endl;
        }
    }
}



void print_matrix(vector<vector<int>> matrix) {
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void floyd_warshall(const vector<vector<int>>& graph) {
    int  i, j, k;
    vector<vector<int>> matrix = graph;
    int n = graph.size();

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    print_matrix(matrix);
}



int main(){

    vector<Node> graph;

    Node A = {
            {1,5},              // x = node; y = weight;
            {2,2},
    };
    graph.push_back(A);

    Node B = {
            {0,5},
            {2,1},
            {3,4},
            {4, 10}
    };
    graph.push_back(B);

    Node C = {
            {0,2},
            {1,1},
            {3,2},
    };
    graph.push_back(C);

    Node D = {
            {1,4},
            {2,2},
            {4,5},
    };
    graph.push_back(D);

    Node E = {
            {1,10},
            {3,5},
    };
    graph.push_back(E);

    int source_node = 0;
    //dijkstra_algorithm(source_node, graph);
    printList(graph);


    vector<vector<int>> graph_2 = {     {0, 5, INF, 10},
                                        {INF, 0, 3, INF},
                                        {INF, INF, 0, 1},
                                        {INF, INF,INF, 0}
                                };
    floyd_warshall(graph_2);


    return 0;
}