#include <iostream>
#include <queue>
using namespace std ;

int field[100][100] ;
struct Cordinate {
    int x, y ;
    Cordinate(int x, int y){
        this->x = x ;
        this->y = y ;
    }
};
void BFS (int x, int y){
    queue<Cordinate> q ;
    Cordinate t(x, y) ;
    q.push(t) ;
    while (!q.empty()) {
        int fx = q.front().x,
                fy = q.front().y;
        q.pop();
        if (field[fx + 1][fy] == 1) {
            Cordinate temp(fx + 1, fy);
            q.push(temp);
            field[fx + 1][fy] = 0;
        }
        if (field[fx + 1][fy + 1] == 1) {
            Cordinate temp(fx + 1, fy + 1);
            q.push(temp);
            field[fx + 1][fy + 1] = 0;
        }
        if (field[fx + 1][fy - 1] == 1) {
            Cordinate temp(fx + 1, fy - 1);
            q.push(temp);
            field[fx + 1][fy - 1] = 0;
        }

        if (field[fx][fy + 1] == 1) {
            Cordinate temp(fx, fy + 1);
            q.push(temp);
            field[fx][fy + 1] = 0;
        }
        if (field[fx][fy - 1] == 1) {
            Cordinate temp(fx, fy - 1);
            q.push(temp);
            field[fx][fy - 1] = 0;
        }

        if (field[fx - 1][fy] == 1) {
            Cordinate temp(fx - 1, fy);
            q.push(temp);
            field[fx - 1][fy] = 0;
        }
        if (field[fx - 1][fy + 1] == 1) {
            Cordinate temp(fx - 1, fy + 1);
            q.push(temp);
            field[fx - 1][fy +1] = 0;
        }
        if (field[fx - 1][fy - 1] == 1){
            Cordinate temp(fx - 1, fy - 1) ;
            q.push(temp) ;
            field[fx - 1][fy - 1] = 0 ;
        }
    }
}
int noOfIslands(int n, int m) {
    int c = 0;
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m; j ++){
            if (field[i][j] == 1) {
                BFS(i, j) ;
                c ++ ;
            }
        }
    }
    return c ;
}
int main() {
    int t ;
    cin >> t ;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> field[i][j];
            }
        }
        cout << noOfIslands(n, m);
    }
    return 0;
}