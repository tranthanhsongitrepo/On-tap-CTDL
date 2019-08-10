#include <iostream>
#include <vector>
using namespace  std;
class Graph {
private :
    vector<int>* graph ;
    int n ;
    void DFS(int i, bool visited[]){
        visited[i] = true ;
        for (int j = 0 ; j < graph[i].size(); j ++){
            if (!visited[graph[i][j]])
                DFS(graph[i][j], visited) ;
        }
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

    bool isTree () {
        bool visited[n] = {0};
        DFS(0, visited);
        for (int i = 0 ; i < n ; i ++) {
            if (!visited[i])
                return false;
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
        graph.isTree() ? cout << "YES" << endl : cout <<  "NO" << endl ;
    }
    return 0;
}