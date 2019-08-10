#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct Edge{
    long long int v1, v2, w ;
    Edge(long long int v1, long long int v2, long long int w){
        this->v1 = v1 ;
        this->v2 = v2 ;
        this->w = w ;
    }
    bool operator < (Edge b){
        return this->w < b.w ;
    }
};
struct Node{
    long long int p, r ;
};
class Graph {
    long long int size;
    vector<Edge> g ;

    long long int find(long long int i, Node p[]){
        if (i != p[i].p)
            p[i].p = find(p[i].p, p) ;
        return p[i].p ;
    }

    void union_by_rank(long long int x, long long int y, Node p[]){
        if (p[x].r > p[y].r){
            p[y].p = x ;
        }
        else if (p[y].r > p[x].r){
            p[x].p = y ;
        }
        else{
            p[x].p = y ;
            p[x].r ++ ;
        }
    }
public :
    Graph(long long int size) {
        this->size = size ;
    }
    void addEdge(long long int v1, long long int v2, long long int w) {
        Edge e1(v1, v2, w) ;
        g.push_back(e1) ;
        Edge e2(v2, v1, w) ;
        g.push_back(e2) ;
    }

    long long int kruskalMST(){
        sort(g.begin(), g.end()) ;
        long long int c = 0, mst_w = 0, i = 0 ;
        Node p[size] ;
        for (long long int j = 0 ; j < size ; j ++){
            p[j].p = j ;
            p[j].r = 0 ;
        }
        while (c != size - 1){
            long long int x = find(g[i].v1, p),
                y = find(g[i].v2, p) ;
            if (x != y) {
                union_by_rank(x, y, p) ;
                mst_w += g[i].w ;
                c ++ ;
            }

            i ++ ;
        }
        return mst_w ;
    }
};

int main() {
    long long int t ;
    cin >> t ;
    while (t --){
        long long int n, m ;
        cin >> n >> m  ;
        Graph g(n) ;
        while (m --) {
            long long int v1, v2, w ;
            cin >> v1 >> v2 >> w ;
            g.addEdge(v1 - 1, v2 - 1, w);
        }
        cout << g.kruskalMST() << endl ;
    }
    return 0;
}
