#include <iostream>
#include <queue>
using namespace std ;
char field[100][100] ;
int n, m ;
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
        if (fx + 1 < n && field[fx + 1][fy] == 'W') {
            Cordinate temp(fx + 1, fy);
            q.push(temp);
            field[fx + 1][fy] = '.';
        }
        if (fx + 1 < n && fy + 1 < m && field[fx + 1][fy + 1] == 'W') {
            Cordinate temp(fx + 1, fy + 1);
            q.push(temp);
            field[fx + 1][fy + 1] = '.';
        }
        if (fx + 1 < n && fy - 1 >= 0 && field[fx + 1][fy - 1] == 'W') {
            Cordinate temp(fx + 1, fy - 1);
            q.push(temp);
            field[fx + 1][fy - 1] = '.';
        }

        if (fy + 1 < m && field[fx][fy + 1] == 'W') {
            Cordinate temp(fx, fy + 1);
            q.push(temp);
            field[fx][fy + 1] = '.';
        }
        if (fy - 1 >= 0 && field[fx][fy - 1] == 'W') {
            Cordinate temp(fx, fy - 1);
            q.push(temp);
            field[fx][fy - 1] = '.';
        }

        if (fx - 1 >= 0 && field[fx - 1][fy] == 'W') {
            Cordinate temp(fx - 1, fy);
            q.push(temp);
            field[fx - 1][fy] = '.';
        }
        if (fx - 1 >= 0 && fy + 1 < m && field[fx - 1][fy + 1] == 'W') {
            Cordinate temp(fx - 1, fy + 1);
            q.push(temp);
            field[fx - 1][fy +1] = '.';
        }
        if (fx - 1 >= 0 && fy - 1 >= 0 && field[fx - 1][fy - 1] == 'W'){
            Cordinate temp(fx - 1, fy - 1) ;
            q.push(temp) ;
            field[fx - 1][fy - 1] = '.' ;
        }
    }
}
int noOfPonds() {
    int c = 0;
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m; j ++){
            if (field[i][j] == 'W') {
                BFS(i, j) ;
                c ++ ;
            }
        }
    }
    return c ;
}
int main() {
    cin >> n >>  m ;
    for (int i = 0; i < n ; i ++){
        for (int j = 0 ; j < m; j ++){
            cin >> field[i][j] ;
        }
    }
    cout << noOfPonds() ;
    return 0;
}