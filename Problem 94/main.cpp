#include <iostream>
int graph[1000][1000] = {0};
using namespace std ;
void FloydAlgo(int n){
    for (int k = 0 ; k < n ; k  ++){
        for (int i = 0 ; i < n; i ++){
            for (int j = 0; j < n; j ++ ) {
                if (!graph[i][j])
                    graph[i][j] = graph[i][k] && graph[k][j] ;
            }
        }
    }
}
int main() {
    int t;
    cin >> t ;
    while (t --){
        int n, m;
        cin >> n >> m ;
        for (int i = 0 ; i < m; i ++){
            int v1, v2 ;
            cin >> v1 >> v2 ;
            graph[v1 - 1][v2 - 1] = 1 ;
            graph[v2 - 1][v1 - 1] = 1 ;
        }
        FloydAlgo(n) ;
        int q ;
        cin >> q ;
        while (q --){
            int v1, v2 ;
            cin >> v1 >> v2 ;
            graph[v1 - 1][v2 - 1] ? cout << "YES" << endl : cout << "NO" << endl ;
        }
    }
    return 0;
}