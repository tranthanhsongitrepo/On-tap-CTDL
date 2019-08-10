#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Graph {
    long long int size;
    vector<long long int>* g;
public :
    Graph(long long int size) {
        this->size = size ;
        g = new vector<long long int>[size] ;
    }


    void addEdge(long long int v1, long long int v2) {
        g[v1].push_back(v2) ;
        g[v2].push_back(v1) ;
    }

    void DFSUtil(int i, int visited[]){
        cout << i + 1 << " " ;
        visited[i] = true ;
        for (int j = 0 ; j < g[i].size() ; j ++){
            if (!visited[g[i][j]])
                DFSUtil(g[i][j], visited) ;
        }

    }
    void DFS(){
        int visited[size] = {false};
        for (long long int i = 0 ; i < size ; i ++) {
            if (!visited[i]) {
                DFSUtil(i, visited) ;
                cout << endl;
            }
        }
    }
};

int main() {
    long long int t ;
    cin >> t ;
    while (t --){
        long long int n, m ;
        cin >> n >> m ;
        Graph g(n) ;
        while (m --) {
            long long int v1, v2 ;
            cin >> v1 >> v2 ;
            g.addEdge(v1 - 1, v2 - 1);
        }
        g.DFS() ;
    }
    return 0;
}