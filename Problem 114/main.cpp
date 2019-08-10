#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF 1000000000000000009
int a[500][500] = {0};
using namespace std;
struct Node{
    int x, y, l ;
    Node(int x, int y, int p){
        this->x = x ;
        this->y = y ;
        this->l = p ;
    }
    Node(){
        this->x = this->y = -1 ;
        this->l = INT_MAX ;
    }
};

bool operator > (const Node a, const Node b){
    return a.l > b.l ;
}

int dijkstra(int n, int m){
    priority_queue<Node, vector<Node>, greater<Node>> q;
    Node p(0, 0, a[0][0]) ;
    q.push(p);
    int shortest_paths[n][m];
    for (int i = 0 ; i < n; i ++){
        for (int j = 0 ; j < m; j ++)
            shortest_paths[i][j] = INT_MAX ;
    }
    shortest_paths[0][0] = a[0][0];
    while (!q.empty()){
        Node top = q.top() ;
        int x = top.x,
                y = top.y,
                l = top.l ;

        q.pop();
        if (shortest_paths[x][y] != l) continue ;
        long long int t = a[x + 1][y] + l ;
        if (x + 1 < n && shortest_paths[x + 1][y] >  t) {
            shortest_paths[x + 1][y] = t ;
            Node temp(x + 1, y, t) ;
            q.push(temp) ;
        }

        t = a[x - 1][y] + l ;
        if (x - 1 >= 0 && shortest_paths[x - 1][y] >  t) {
            shortest_paths[x - 1][y] = t ;
            Node temp(x - 1, y, t) ;
            q.push(temp) ;
        }

        t = a[x][y + 1] + l ;
        if (y + 1 < m && shortest_paths[x][y + 1] >  t) {
            shortest_paths[x][y + 1] = t ;
            Node temp(x, y + 1, t) ;
            q.push(temp) ;
        }

        t = a[x][y - 1] + l ;
        if (y - 1 >= 0 && shortest_paths[x][y - 1] >  t) {
            shortest_paths[x][y - 1] = t ;
            Node temp(x, y - 1, t) ;
            q.push(temp) ;
        }
    }
    return shortest_paths[n- 1][m - 1] ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --) {
        int n, m;
        cin >> n >> m;
        for (int i = 0 ; i < n; i ++){
            for (int j = 0 ; j < m; j ++)
                cin >> a[i][j] ;
        }
        cout << dijkstra(n, m)  << endl ;
    }
    return 0;
}