#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Graph {
    int size;
    vector<int>* g;
public :
    Graph(int size) {
        this->size = size ;
        g = new vector<int>[size] ;
    }

    int getSize(){
        return size ;
    }
    void addEdge(int v1, int v2) {
        g[v1].push_back(v2) ;
        g[v2].push_back(v1) ;
    }

    void BFS (int u){
        queue<int> q ;
        q.push(u) ;
        bool visited[size] = {false};
        visited[u] = true ;
        while (!q.empty()){
            cout << q.front() + 1 << " " ;
            for (int i = 0 ; i < g[q.front()].size(); i ++){
                if (!visited[g[q.front()][i]]) {
                    q.push(g[q.front()][i]);
                    visited[g[q.front()][i]] = true ;
                }
            }
            q.pop() ;
        }
        cout << endl ;
    }
};

int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n, m, u ;
        cin >> n >> m >> u ;
        Graph g(n) ;
        while (m --) {
            int v1, v2 ;
            cin >> v1 >> v2 ;
            g.addEdge(v1 - 1, v2 - 1);
        }
        g.BFS(u - 1) ;
    }
    return 0;
}