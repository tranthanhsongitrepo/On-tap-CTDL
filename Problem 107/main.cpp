#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct Edge {
    int v1, v2 ;
    Edge (int v1, int v2){
        this->v1 = v1 ;
        this->v2 = v2 ;
    }
};
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

    void DFS(int u){
        stack<int> s ;
        s.push(u) ;
        bool visited[size] = {false};
        visited[u] = true ;
        vector<Edge> tree ;
        while (!s.empty()){
            int top = s.top() ;
            s.pop() ;
            for (int i = 0; i < g[top].size() ; i ++){
                if (!visited[g[top][i]]) {
                    Edge t(top + 1, g[top][i] + 1) ;
                    tree.push_back(t) ;
                    s.push(top);
                    s.push(g[top][i]);
                    visited[g[top][i]] = true ;
                    break ;
                }
            }
        }
        if (tree.size() != size - 1)
            cout << -1 << endl ;
        else{
            for (int i = 0 ; i < tree.size(); i ++){
                cout << tree[i].v1 << " " << tree[i].v2 << endl ;
            }
        }
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
        g.DFS(u - 1) ;
    }
    return 0;
}
