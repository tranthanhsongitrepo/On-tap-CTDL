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

    int BFS (int start, int end){
        queue<int> q ;
        q.push(start) ;
        int prev_size = 1, c = 0 ;
        bool visited[size] = {false};
        visited[start] = true ;
        while (!q.empty()){
            if (q.front() == end)
                    return c ;
            for (int i = 0 ; i < g[q.front()].size(); i ++){
                if (!visited[g[q.front()][i]]) {
                    q.push(g[q.front()][i]);
                    visited[g[q.front()][i]] = true ;
                }
            }
            q.pop() ;
            prev_size -- ;
            if (prev_size == 0) {
                c++;
                prev_size = q.size() ;
            }
        }
        return -1  ;
    }
};

int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n, m, start, end ;
        cin >> n >> m >> start >> end ;
        Graph g(n) ;
        while (m --) {
            int v1, v2 ;
            cin >> v1 >> v2 ;
            g.addEdge(v1 - 1, v2 - 1);
        }
        cout << g.BFS(start - 1, end - 1) << endl ;
    }
    return 0;
}