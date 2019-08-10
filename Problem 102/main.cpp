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

    void BFS (){
        bool visited[size] = {false};
        for (int i = 0; i < size; i ++) {
            if (visited[i] == false) {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    cout << q.front() + 1 << " ";
                    for (int j = 0; j < g[q.front()].size(); j ++) {
                        if (!visited[g[q.front()][j]]) {
                            q.push(g[q.front()][j]);
                            visited[g[q.front()][j]] = true;
                        }
                    }
                    q.pop();
                }
                cout << endl;
            }
        }
    }
};

int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n, m ;
        cin >> n >> m ;
        Graph g(n) ;
        while (m --) {
            int v1, v2 ;
            cin >> v1 >> v2 ;
            g.addEdge(v1 - 1, v2 - 1);
        }
        g.BFS() ;
    }
    return 0;
}