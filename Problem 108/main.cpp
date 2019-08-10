#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Graph {
    int size;
    vector<int>* g ;
public :
    Graph(int size) {
        this->size = size ;
        g = new vector<int> [size] ;
    }

    int getSize(){
        return size ;
    }
    void addEdge(int v1, int v2) {
        g[v1].push_back(v2) ;
        g[v2].push_back(v1) ;
    }

    void noOfCCUtil(int i, bool visited[]){
        visited[i] = true ;
        for (int j = 0 ; j  < g[i].size(); j ++)
            if (!visited[g[i][j]])
                noOfCCUtil(g[i][j], visited) ;
    }
    int noOfCC(int u){
        int c = 0 ;
        bool visited[size] = {false};
        if (u != -1)
            visited[u] = true ;
        for (int i = 0; i < size; i ++) {
            if (!visited[i]) {
                noOfCCUtil(i, visited) ;
                c++;
            }
        }
        return c ;
    }
    void inDinhTru(){
        vector<int> res ;
        int initNoOfCC = noOfCC(-1) ;
        for(int i = 0; i < size; i ++) {
            if (noOfCC(i) > initNoOfCC)
                res.push_back(i + 1);
        }
        cout << res.size() << endl ;
        for (int i = 0; i < res.size(); i ++)
            cout << res[i] << " " ;
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
        while (m --) {
            int v1, v2 ;
            cin >> v1 >> v2 ;
            g.addEdge(v1 - 1, v2 - 1);
        }
        g.inDinhTru() ;

    }
    return 0;
}