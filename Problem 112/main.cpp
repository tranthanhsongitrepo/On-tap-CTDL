#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
class Graph {
    long long int size;
    long long int** g ;
public :
    Graph(long long int size) {
        this->size = size ;
        g = new long long int* [size] ;
        for (long long int i = 0 ; i < size; i ++)
            g[i] = new long long int [size] ;
    }

    void addEdge(long long int v1, long long int v2, long long int w) {
        g[v1][v2] = w ;
        g[v2][v1] = w ;
    }
    void floyd(long long int q){
        long long int shortest_paths[size][size] ;
        for(long long int i = 0; i < size; i ++){
            for (long long int j = 0 ; j < size; j ++)
                if (i == j)
                    shortest_paths[i][j] = 0 ;
                else
                 shortest_paths[i][j] = g[i][j] == 0 ? INT_MAX : g[i][j] ;
        }

        for(long long int k = 0 ; k < size; k ++){
            for(long long int i = 0 ; i < size; i ++){
                for(long long int j = 0 ; j < size; j ++){
                    if(shortest_paths[i][k] != INT_MAX && shortest_paths[k][j] != INT_MAX) {
                        long long int t = shortest_paths[i][k] + shortest_paths[k][j] ;
                        if (shortest_paths[i][j] > t)
                            shortest_paths[i][j] = t ;
                    }
                }
            }
        }

        while (q--){
            long long int v1, v2 ;
            cin >> v1 >> v2 ;
            cout << shortest_paths[v1 - 1][v2 - 1] << endl ;
        }
    }
};

int main() {
    long long int n, m;
    cin >> n >> m;
    Graph g(n);
    while (m--) {
        long long int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g.addEdge(v1 - 1, v2 - 1, w) ;
    }
    long long int q;
    cin >> q;
    g.floyd(q);

    return 0;
}