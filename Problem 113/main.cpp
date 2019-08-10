#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF 1000000000000000009

using namespace std;
struct Pair{
    long long int l, p;
    Pair() {
        l = INF; p = 0 ;
    }
    Pair(long long int l, long long int p){
        this->l = l ;
        this->p = p ;   
    }
};


bool operator > (const Pair a, const Pair p){
    return a.l < p.l ;
}

struct Edge{
    long long int v, w ;
    Edge(long long int v, long long int w){
        this->v = v ;
        this->w = w ;
    }
};
class Graph {
    long long int size;
    vector<Edge>* g ;
public :
    Graph(long long int size) {
        this->size = size ;
        g = new vector<Edge> [size] ;
    }

    void addEdge(long long int v1, long long int v2, long long int w) {
        Edge t(v1, w) ;
        g[v2].push_back(t) ;
        Edge t2(v2, w) ;
        g[v1].push_back(t2);
    }
    void dijkstra(){
        priority_queue<Pair, vector<Pair>, greater<Pair>> q;
        Pair p(0, 0) ;
        q.push(p);
        Pair shortest_paths[size];
        shortest_paths[0].l = 0 ;
        shortest_paths[0].p = 1 ;
        while (!q.empty()){
            Pair temp = q.top() ;
            long long int u = temp.p, du = temp.l ;
            q.pop();
            if (shortest_paths[u].l != du) continue ;
            for(long long int i = 0 ; i < g[u].size(); i ++){
                long long int t = shortest_paths[u].l + g[u][i].w,
                              v = g[u][i].v ;
                if (shortest_paths[v].l > t) {
                    shortest_paths[v].l = t;
                    shortest_paths[v].p = shortest_paths[u].p;
                    Pair tmp(shortest_paths[v].l, v)  ;
                    q.push(tmp) ;

                }
                else if (shortest_paths[v].l == t)
                    shortest_paths[v].p += shortest_paths[u].p ;
            }
        }
        if (size == 1)
            shortest_paths[size - 1].p = 0 ;
        cout << shortest_paths[size - 1].l << " " << shortest_paths[size - 1].p ;
    }
};

int main() {
    long long int n, m;
    cin >> n >> m;
    Graph g(n);
    while (m--) {
        long long int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g.addEdge(v1 - 1, v2 - 1, w) ;
    }
    g.dijkstra();

    return 0;
}