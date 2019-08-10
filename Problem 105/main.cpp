#include <iostream>
#include <vector>
#include <stack>

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

    int DFSUtil(int i, int s, int e, int visited[], int p[]){
        if (i == e) {
            int c = 0, j = e ;
            while(j != s){
                c ++ ;
                j = p[j] ;
            }
            return c ;
        }
        visited[i] = true ;
        for (int j = 0 ; j < g[i].size() ; j ++){
            if (!visited[g[i][j]]) {
                p[g[i][j]] = i ;
                int c = DFSUtil(g[i][j], s, e, visited, p);
                if (c != -1)
                    return c ;
            }
        }
        return -1 ;
    }
    int DFS(int s, int e){
        int visited[size] = {false}, p[size] = {0} ;
        return DFSUtil(s, s, e, visited, p) ;
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
        cout << g.DFS(start - 1, end - 1 ) << endl ;
    }
    return 0;
}