#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Edge{
    int v1, v2 ;
    Edge(int v1, int v2){
        this->v1 = v1 ;
        this->v2 = v2 ;
    }
};
class Graph {
    int size;
    int** g ;
public :
    Graph(int size) {
        this->size = size ;
        g = new int* [size] ;
        for (int i = 0 ; i < size; i ++)
            g[i] = new int [size] ;
    }
    void addEdge(int v1, int v2) {
        g[v1][v2] = 1 ;
        g[v2][v1] = 1 ;
    }

    void removeEdge(int v1, int v2){
        g[v1][v2] = 0 ;
        g[v2][v1] = 0 ;
    }
    void DFS(int i, bool visited[]){
        visited[i] = true ;
        for (int j = 0 ; j < size; j ++){
            if (!visited[j] && g[i][j] == 1)
                DFS(j
                        , visited) ;
        }
    }
    int noOfCC(){
        int c = 0 ;
        bool visited[size] = {false};
        for (int i = 0; i < size; i ++) {
            if (!visited[i]) {
                DFS(i, visited) ;
                c++;
            }
        }
        return c ;
    }
    void inCanhCau(vector<Edge> e){
        vector<int> res ;
        int initNoOfCC = noOfCC();
        for(int i = 0; i < e.size(); i ++) {
            removeEdge(e[i].v1, e[i].v2) ;
            if (noOfCC() > initNoOfCC)
                res.push_back(i + 1);
            addEdge(e[i].v1, e[i].v2) ;
        }
        cout << res.size() << endl ;
        for (int i = 0; i < res.size(); i ++)
            cout << res[i] << endl ;
        cout << endl ;
    }
};

int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n, m ;
        cin >> n >> m  ;
        Graph g(n) ;
        vector<Edge> e ;
        while (m --) {
            int v1, v2 ;
            cin >> v1 >> v2 ;
            Edge tmp(v1 - 1, v2 - 1);
            e.push_back(tmp);
            g.addEdge(v1 - 1, v2 - 1);
        }
        g.inCanhCau(e) ;
    }
    return 0;
}