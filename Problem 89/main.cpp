#include <iostream>
using namespace std ;
struct Edge{
    int v1, v2 ;
};
int main() {
    // bài này ăn gian tí :))
    int n, m ;
    cin >> n >> m ;
    Edge e[m] ;
    for (int i = 0; i < m; i ++) {
        cin >> e[i].v1 >> e[i].v2 ;
    }
    for (int i = m - 1; i >= 0 ; i --){
        cout << e[i].v1 << " " << e[i].v2 << endl ;
    }
    return 0;
}