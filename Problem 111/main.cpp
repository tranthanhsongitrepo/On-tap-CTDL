#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
struct Edge{
    long long int v1, v2 ;
    float w ;
    Edge(double v1, double v2, double w){
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
struct Cordinate{
    double x, y ;
    Cordinate(double x, double y){
        this->x = x;
        this->y = y;
    }
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
    void addEdge(double v1, double v2, double w) {
        Edge e1(v1, v2, w) ;
        g.push_back(e1) ;
        Edge e2(v2, v1, w) ;
        g.push_back(e2) ;
    }

    double kruskalMST(){
        sort(g.begin(), g.end()) ;
        long long int c = 0, i = 0 ;
        double mst_w = 0 ;
        Node p[size] ;
        for (long long int j = 0 ; j < size ; j ++){
            p[j].p = j, p[j].r = 0 ;
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
        long long int n ;
        cin >> n ;
        Graph g(n) ;
        vector<Cordinate> v;
        for (long long int i = 0 ; i < n; i ++) {
            double x, y ;
            cin >> x >> y;
            Cordinate temp(x, y) ;
            v.push_back(temp) ;
        }
        for(long long int i = 0 ; i < n - 1; i ++){
            for(long long int j = i + 1; j < n ; j ++){
                double x = v[i].x - v[j].x,
                    y = v[i].y - v[j].y ;
                g.addEdge(i, j, sqrt(x * x + y * y)) ;
            }
        }
        cout.precision(6) ;
        cout << fixed << g.kruskalMST() << endl ;
    }
    return 0;
}