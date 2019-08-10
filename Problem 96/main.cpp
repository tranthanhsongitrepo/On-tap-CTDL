#include <iostream>
#include <vector>
using namespace  std;
class Graph {
private :
    vector<int>* graph ;
    int n ;
    bool DFS(int i, int c, int color[]){
        color[i] = c;
        for (int j = 0 ; j < graph[i].size(); j ++){
            if (!color[graph[i][j]]) {
                if (!DFS(graph[i][j], c == 1 ? 2 : 1, color))
                    return false;
            }
            else if (color[graph[i][j]] == c)
                return false ;
        }
        return true ;
    }
public :
    Graph(int n){
        this->n = n ;
        graph = new vector<int> [n] ;
    }

    void addEdge(int v1, int v2 ){
        graph[v1 - 1].push_back(v2 - 1) ;
        graph[v2 - 1].push_back(v1 - 1) ;
    }
    bool isBipartite(){
        int color[n] = {0};
        for (int i = 0 ; i < n ; i ++){
            if (!color[i])
                if (!DFS(i, 1, color) )
                    return false ;
        }
        return true ;
    }

};
int main() {
    int t ;
    cin >> t ;
    while (t  --){
        int n ;
        cin >> n ;
        Graph graph(n) ;
        while (n-- != 1){
            int v1, v2;
            cin >> v1 >> v2 ;
            graph.addEdge(v1, v2) ;
        }
        graph.isBipartite() ? cout << "YES" << endl : cout <<  "NO" << endl ;
    }
    return 0;
}